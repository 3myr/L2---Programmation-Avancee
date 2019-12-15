#include "header/MainMenu.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instanciation d'un menu
*/
MainMenu::MainMenu()
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
    exit(EXIT_FAILURE);
  }

  menuIsOn = 1;
  selectedItemIndex = 0;
  sf::Text text;
  text.setFont(font);
  text.setString("Continue");
  text.setPosition(150, 80);
  text.setScale(0.20,0.20);
  texts.push_back(sf::Text(text));

  text.setString("Nouvelle partie");
  text.setPosition(250, 80);
  text.setScale(0.20,0.20);
  texts.push_back(sf::Text(text));

  text.setString("Options");
  text.setPosition(350, 80);
  text.setScale(0.20,0.20);
  texts.push_back(sf::Text(text));

  text.setString("Quitter");
  text.setPosition(450, 80);
  text.setScale(0.20,0.20);
  texts.push_back(sf::Text(text));

}

/**
* \brief Instanciation d'un menu
*/
MainMenu::MainMenu(float width, float height)
{
  // Charge la police d'ecriture
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }

  // Charge une musique-------------------
  if (!buffer.loadFromFile("Sounds/tir.ogg"))
  {
    cout<<"Le sond n'a pas pu être chargé !"<<endl;
    exit(EXIT_FAILURE);
  }
  sound.setBuffer(buffer);
  // --------------------------------------
  playing = 0;

  menuIsOn = 1;
  selectedItemIndex = 0;

  Time = 0;


  // Instancie les différents elements d'un menu

  // UI pour le titre
  titleTexture.loadFromFile("Menu/Title.png");
  titleSprite.setTexture(titleTexture);
  titleSprite.setPosition(110,20);
  titreSprite.push_back(sf::Sprite(titleSprite));


  sf::Text text;
  text.setFont(font);
  text.setString("Continue");
  //text.setPosition(width, height);
  text.setPosition(555, 390);
  text.setScale(1,1);
  text. setFillColor(sf::Color::Red);
  texts.push_back(sf::Text(text));

  // UI pour le premier menu
  textureUI.loadFromFile("Menu/UI_block3.png");
  spriteUI.setTexture(textureUI);
  spriteUI.setPosition(540,380);
  titreSprite.push_back(sf::Sprite(spriteUI));

  text.setString("Nouveau");
  //text.setPosition(width, (height));
  text.setPosition(555, 470);
  text.setScale(1,1);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  // UI pour le premier menu
  spriteUI.setPosition(540,460);
  titreSprite.push_back(sf::Sprite(spriteUI));


  // UI pour le premier menu
  textureUI.loadFromFile("Menu/UI_block3.png");
  spriteUI.setTexture(textureUI);
  spriteUI.setPosition(540,540);
  titreSprite.push_back(sf::Sprite(spriteUI));


  text.setString("Quitter");
  //text.setPosition(width, (height));
  text.setPosition(555, 550);
  text.setScale(1,1);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  // -------------------------------------------------------
}

// ---------------------------------------------------------------------------



//Fonctions d'observations ---------------------------------------------------

/**
* \brief Gère l'evenement qui se produit quand l'utilisateur appuie sur entrer
*/
int MainMenu::getEnter()
{
  //Choisit un onglet
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && Time >= 240 && menuIsOn == 1)
  {
    Time = 0;
    // Cas dans lequel on continue la partie
    if(selectedItemIndex==0)
    {
      // Ferme le menu
      menuIsOn = 0;
    }
    // Cas dans lequel on lance une nouvelle partie
    if(selectedItemIndex==1)
    {
      // Ferme le menu
      menuIsOn = 0;
    }
    return selectedItemIndex;
  }
  return -1;
}

/**
* \brief
*/
sf::Sprite MainMenu::getSprite()
{
  return sprite;
}

// ---------------------------------------------------------------------------





//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Fonction qui gere le choix de l'utilisateur dans le menu
*/
void MainMenu::choix()
{
  if(menuIsOn == 1)
  {
    //Deplacement en Bas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Time >= 240)
    {
      Time = 0;
      texts[selectedItemIndex]. setFillColor(sf::Color::White);
      if(selectedItemIndex == 2)
      {
        selectedItemIndex = 0;
      }
      else
      {
        selectedItemIndex = selectedItemIndex + 1;
      }
      texts[selectedItemIndex]. setFillColor(sf::Color::Red);

    }
    //Deplacement en Haut
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Time >= 240)
    {
      Time = 0;
      texts[selectedItemIndex]. setFillColor(sf::Color::White);
      if(selectedItemIndex == 0)
      {
        selectedItemIndex = 2;
      }
      else
      {
        selectedItemIndex = selectedItemIndex - 1;
      }
      texts[selectedItemIndex]. setFillColor(sf::Color::Red);
    }
  }
}

/**
* \brief
*/
void MainMenu::setTexture()
{
  texture.loadFromFile("Background/menu.jpg");
  sprite.setTexture(this->texture);
  sprite.scale(0.7,0.7);
}

// ---------------------------------------------------------------------------
