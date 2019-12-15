#include "header/ChoiceMenu.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instancie le menu de choix de niveau
*/
ChoiceMenu::ChoiceMenu()
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
    exit(EXIT_FAILURE);
  }

  menuIsOn = 0;
  selectedItemIndex = 0;
  Time = 0;

  sf::Text text;
  text.setFont(font);
  text.setString("Choissisez Votre Monde");
  text.setPosition(50, 20);
  text.setScale(0.20,0.20);
  texts.push_back(sf::Text(text));

}

/**
* \brief Instancie le menu de choix de niveau
*/
ChoiceMenu::ChoiceMenu(float width, float height)
{
  // Charge la texture du texte qui sera affiché
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }

  // Charge la musique qui sera jouer---------------------------
  if (!buffer.loadFromFile("Sounds/rasputin.ogg")) // A CHANGER
  {
    cout<<"Le sond n'a pas pu être chargé !"<<endl;
    exit(EXIT_FAILURE);
  }
  sound.setBuffer(buffer);
  // -----------------------------------------------------------

  playing = 0;

  menuIsOn = 0;
  selectedItemIndex = 0;
  Time = 0;

  // Instancie le text et les texture du menu
  sf::Text text;
  text.setFont(font);
  text.setString("Choissisez Votre Monde");
  //text.setPosition(width, height);
  text.setPosition(350, 20);
  text.setScale(1.5,1.5);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  // UI pour le premier menu
  textureUI[0].loadFromFile("Menu/level_1.png");
  spriteUI.setTexture(textureUI[0]);
  spriteUI.setPosition(140,255);
  titreSprite.push_back(sf::Sprite(spriteUI));

  // UI pour le premier menu
  textureUI[1].loadFromFile("Menu/level_2_lock.png");
  spriteUI.setTexture(textureUI[1]);
  spriteUI.setPosition(540,255);
  titreSprite.push_back(sf::Sprite(spriteUI));

  // UI pour le premier menu
  textureUI[2].loadFromFile("Menu/level_block.png");
  spriteUI.setTexture(textureUI[2]);
  spriteUI.setPosition(940,255);
  titreSprite.push_back(sf::Sprite(spriteUI));

  // UI pour le premier menu
  textureUI[3].loadFromFile("Menu/level_block.png");
  spriteUI.setTexture(textureUI[3]);
  spriteUI.setPosition(310,425);
  titreSprite.push_back(sf::Sprite(spriteUI));

  // UI pour le premier menu
  textureUI[4].loadFromFile("Menu/level_block.png");
  spriteUI.setTexture(textureUI[4]);
  spriteUI.setPosition(710,425);
  titreSprite.push_back(sf::Sprite(spriteUI));

  // permet de rendre transparent les images qui sont en cours de selection
  titreSprite[0].setColor(sf::Color(255,255,255,128));
  // -------------------------------------------------------------

}

// ---------------------------------------------------------------------------




//Fonctions d'observations ---------------------------------------------------

/**
* \brief Gère l'evenement qui se produit quand l'utilisateur appuie sur entrer
*/
int ChoiceMenu::getEnter()
{
  //Choisit un onglet
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && Time >= 240 && menuIsOn == 1)
  {
    Time = 0;
    return selectedItemIndex;
  }
  return -1;
}

/**
* \brief
*/
sf::Sprite ChoiceMenu::getSprite()
{
  return sprite;
}

/**
* \brief
*/
int ChoiceMenu::getLevel()
{
  return level;
}

// ---------------------------------------------------------------------------





//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Fonction qui gere le choix de l'utilisateur dans le menu
*/
void ChoiceMenu::choix()
{
  if(menuIsOn == 1)
  {
    //Deplacement en Bas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Time >= 240)
    {
      Time = 0;
      titreSprite[selectedItemIndex].setColor(sf::Color(255,255,255,255)); // remet la texture sans transparence
      if(selectedItemIndex == 4)
      {
        selectedItemIndex = 0;
      }
      else
      {
        selectedItemIndex = selectedItemIndex + 1;
      }
      titreSprite[selectedItemIndex].setColor(sf::Color(255,255,255,128)); // met la texture avec un niveau de transparance pour montrer qu'on le survole

    }
    //Deplacement en Haut
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Time >= 240)
    {
      Time = 0;
      titreSprite[selectedItemIndex].setColor(sf::Color(255,255,255,255)); // remet la texture sans transparence
      if(selectedItemIndex == 0)
      {
        selectedItemIndex = 4;
      }
      else
      {
        selectedItemIndex = selectedItemIndex - 1;
      }
      titreSprite[selectedItemIndex].setColor(sf::Color(255,255,255,128)); // met la texture avec un niveau de transparance pour montrer qu'on le survole
    }
  }
}

/**
* \brief
*/
void ChoiceMenu::setTexture()
{
  texture.loadFromFile("Background/menu.jpg");
  sprite.setTexture(this->texture);
  sprite.scale(0.7,0.7);
}

/**
* \brief Permet de changer la texture d'une icone quand le niveau est débloqué
*/
void ChoiceMenu::unlockLevel()
{
  textureUI[1].loadFromFile("Menu/level_2.png");
}

/**
* \brief Permet de verrouiller tout les niveaux
*/
void ChoiceMenu::lockedAllLevel()
{
  textureUI[1].loadFromFile("Menu/level_2_lock.png");
}
// ---------------------------------------------------------------------------
