#include "header/PauseMenu.h"
#define SFML_DEPRECATED

// Methode constructive

PauseMenu::PauseMenu()
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
}

PauseMenu::PauseMenu(float width, float height)
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }

  menuIsOn = 0;
  selectedItemIndex = 0;

  sf::Text text;
  text.setFont(font);
  text.setString("Continue");
  text.setPosition(width, height);
  //text.setPosition(150, 100);
  text.setScale(0.2,0.2);
  text.setColor(sf::Color::Red);
  texts.push_back(sf::Text(text));

  text.setString("Options");
  text.setPosition(width, (height));
  //text.setPosition(150, 140);
  text.setScale(0.2,0.2);
  text.setColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  text.setString("Menu principale");
  text.setPosition(width, (height));
  //text.setPosition(150, 180);
  text.setScale(0.2,0.2);
  text.setColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  text.setString("Quitter");
  text.setPosition(width, (height));
  //text.setPosition(150, 180);
  text.setScale(0.2,0.2);
  text.setColor(sf::Color::White);
  texts.push_back(sf::Text(text));
}


//Fonctions d'observations

int PauseMenu::getEnter()
{
  //Choisit un onglet
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && Time >= 240 && menuIsOn == 1)
  {
    Time = 0;
    if(selectedItemIndex==0)
    {
      menuIsOn = 0;
    }
    if(selectedItemIndex==2)
    {
      menuIsOn = 0;
    }
    if(selectedItemIndex==3)
    {
      menuIsOn = 0;
    }
    return selectedItemIndex;
  }
}

sf::Sprite PauseMenu::getSprite()
{
  return sprite;
}


//Fonctions de transmorfations


//Return 1 si on affiche le menu, 0 sinon
void PauseMenu::choix()
{
  // Gère la gestion d'une manette ou d'un clavier
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Time >= 240)
  {
    Time = 0;
    if(menuIsOn == 0)
    {
      menuIsOn = 1;
    }
    else
    {
      menuIsOn = 0;
    }
  }
  if(menuIsOn == 1)
  {
    //Deplacement en Bas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Time >= 240)
    {
      Time = 0;
      texts[selectedItemIndex].setColor(sf::Color::White);
      if(selectedItemIndex == 3)
      {
        selectedItemIndex = 0;
      }
      else
      {
        selectedItemIndex = selectedItemIndex + 1;
      }
      texts[selectedItemIndex].setColor(sf::Color::Red);
    }
    //Deplacement en Haut
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Time >= 240)
    {
      Time = 0;
      texts[selectedItemIndex].setColor(sf::Color::White);
      if(selectedItemIndex == 0)
      {
        selectedItemIndex = 3;
      }
      else
      {
        selectedItemIndex = selectedItemIndex - 1;
      }
      texts[selectedItemIndex].setColor(sf::Color::Red);
    }
  }
}

void PauseMenu::setPosition(float x, float y)
{
  for(int i=0;i<texts.size();i++)
  {
    texts[i].setPosition(x,y+(i*10)); // A modifier si utiliser
  }
}

void PauseMenu::setTexture()
{
  texture.loadFromFile("Background/menu.jpg");
  sprite.setTexture(this->texture);
  sprite.scale(0.7,0.7);
}
