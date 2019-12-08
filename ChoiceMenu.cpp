#include "header/ChoiceMenu.h"

// Methode constructive -----------------------------------------------------

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

ChoiceMenu::ChoiceMenu(float width, float height)
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
  if (!buffer.loadFromFile("Sounds/rasputin.wav"))
  {
    cout<<"Le sond n'a pas pu être chargé !"<<endl;
    exit(EXIT_FAILURE);
  }
  sound.setBuffer(buffer);
  playing = 0;

  menuIsOn = 0;
  selectedItemIndex = 0;
  Time = 0;

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
  textureUI[1].loadFromFile("Menu/level_2.png");
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

  titreSprite[0].setColor(sf::Color(255,255,255,128));

}

// ---------------------------------------------------------------------------




//Fonctions d'observations ---------------------------------------------------

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

sf::Sprite ChoiceMenu::getSprite()
{
  return sprite;
}

// ---------------------------------------------------------------------------





//Fonctions de transmorfations -----------------------------------------------

//Return 1 si on affiche le menu, 0 sinon
void ChoiceMenu::choix()
{
  if(menuIsOn == 1)
  {
    //Deplacement en Bas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Time >= 240)
    {
      Time = 0;
      titreSprite[selectedItemIndex].setColor(sf::Color(255,255,255,255));
      if(selectedItemIndex == 4)
      {
        selectedItemIndex = 0;
      }
      else
      {
        selectedItemIndex = selectedItemIndex + 1;
      }
      titreSprite[selectedItemIndex].setColor(sf::Color(255,255,255,128));

    }
    //Deplacement en Haut
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Time >= 240)
    {
      Time = 0;
      titreSprite[selectedItemIndex].setColor(sf::Color(255,255,255,255));
      if(selectedItemIndex == 0)
      {
        selectedItemIndex = 4;
      }
      else
      {
        selectedItemIndex = selectedItemIndex - 1;
      }
      titreSprite[selectedItemIndex].setColor(sf::Color(255,255,255,128));
    }
  }
}


void ChoiceMenu::setTexture()
{
  texture.loadFromFile("Background/menu.jpg");
  sprite.setTexture(this->texture);
  sprite.scale(0.7,0.7);
}

// ---------------------------------------------------------------------------
