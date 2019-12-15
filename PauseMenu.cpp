/**
 * \file PauseMenu.cpp
 * \author Demazieres Remy
 * \date 15 decembre 2019
 *
 */
#include "header/PauseMenu.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instancie un menu pause
*/
PauseMenu::PauseMenu()
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
}

/**
* \brief Instancie un menu pause
*/
PauseMenu::PauseMenu(float width, float height)
{
  // Charge la police du texte
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }


  menuIsOn = 0;
  selectedItemIndex = 0;
  Time = 0;

  // Implementation du texte ------------------
  sf::Text text;
  text.setFont(font);
  text.setString("Continue");
  text.setPosition(width, height);
  //text.setPosition(150, 100);
  text.setScale(0.2,0.2);
  text. setFillColor(sf::Color::Red);
  texts.push_back(sf::Text(text));

  text.setString("Save");
  text.setPosition(width, (height));
  //text.setPosition(150, 140);
  text.setScale(0.2,0.2);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  text.setString("Menu principale");
  text.setPosition(width, (height));
  //text.setPosition(150, 180);
  text.setScale(0.2,0.2);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  text.setString("Quitter");
  text.setPosition(width, (height));
  //text.setPosition(150, 180);
  text.setScale(0.2,0.2);
  text. setFillColor(sf::Color::White);
  texts.push_back(sf::Text(text));

  //------------------------------------------
}

// ---------------------------------------------------------------------------





//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
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
  return -1;
}

/**
* \brief
*/
sf::Sprite PauseMenu::getSprite()
{
  return sprite;
}

// ---------------------------------------------------------------------------





//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Fonction qui gere le choix de l'utilisateur dans le menu
*/
void PauseMenu::choix()
{
  // Si on appuie sur echappe
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
      texts[selectedItemIndex].setFillColor(sf::Color::White);
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
      texts[selectedItemIndex].setFillColor(sf::Color::White);
      if(selectedItemIndex == 0)
      {
        selectedItemIndex = 3;
      }
      else
      {
        selectedItemIndex = selectedItemIndex - 1;
      }
      texts[selectedItemIndex].setFillColor(sf::Color::Red);
    }
  }
}
/**
* \brief
*/
void PauseMenu::setPosition(float x, float y)
{
  for(int i=0;i<texts.size();i++)
  {
    texts[i].setPosition(x,y+(i*10)); // A modifier si utiliser
  }
}
/**
* \brief
*/
void PauseMenu::setTexture()
{
  texture.loadFromFile("Background/menu.jpg");
  sprite.setTexture(this->texture);
  sprite.scale(0.7,0.7);
}

// ---------------------------------------------------------------------------
