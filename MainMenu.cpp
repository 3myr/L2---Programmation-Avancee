#include "header/MainMenu.h"

// Methode constructive

MainMenu::MainMenu()
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
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

MainMenu::MainMenu(float width, float height)
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }

  menuIsOn = 1;
  selectedItemIndex = 0;

  sf::Text text;
  text.setFont(font);
  text.setString("Continue");
  //text.setPosition(width, height);
  text.setPosition(150, 60);
  text.setScale(1,1);
  text. setFillColor(sf::Color::Red);
  texts.push_back(sf::Text(text));

  text.setString("Nouvelle partie");
  //text.setPosition(width, (height));
  text.setPosition(150, 100);
  text.setScale(1,1);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  text.setString("Options");
  //text.setPosition(width, (height));
  text.setPosition(150, 140);
  text.setScale(1,1);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  text.setString("Quitter");
  //text.setPosition(width, (height));
  text.setPosition(150, 180);
  text.setScale(1,1);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));
}


//Fonctions d'observations

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

sf::Sprite MainMenu::getSprite()
{
  return sprite;
}


//Fonctions de transmorfations


//Return 1 si on affiche le menu, 0 sinon
void MainMenu::choix()
{
  if(menuIsOn == 1)
  {
    //Deplacement en Bas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Time >= 240)
    {
      Time = 0;
      texts[selectedItemIndex]. setFillColor(sf::Color::White);
      if(selectedItemIndex == 3)
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
        selectedItemIndex = 3;
      }
      else
      {
        selectedItemIndex = selectedItemIndex - 1;
      }
      texts[selectedItemIndex]. setFillColor(sf::Color::Red);
    }
  }
}


void MainMenu::setTexture()
{
  texture.loadFromFile("Background/menu.jpg");
  sprite.setTexture(this->texture);
  sprite.scale(0.7,0.7);
}
