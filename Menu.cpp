#include "header/Menu.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instanciation d'un menu
*/
Menu::Menu()
{

}

/**
* \brief Instanciation d'un menu
*/
Menu::Menu(float width, float height)
{

}

// ---------------------------------------------------------------------------

//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
sf::Text Menu::getText(int i)
{
  return texts[i];
}

/**
* \brief
*/
int Menu::getMenuEtat()
{
  return menuIsOn;
}

/**
* \brief
*/
float Menu::getTime()
{
  return Time;
}

/**
* \brief
*/
int Menu::isPlaying()
{
  return playing;
}

/**
* \brief
*/
int Menu::getSelectedItemIndex()
{
  return selectedItemIndex;
}

// ---------------------------------------------------------------------------


//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Fixe le temps de la clock pour gérer l'animation de choix d'option
*/
void Menu::setTime(float VAL)
{
  if(VAL==-1)
  {
    Time = 0;
  }
  else
  {
    Time = Time + VAL;
  }
}

/**
* \brief
*/
void Menu::setPosition(float x, float y)
{
  for(int i=0;i<texts.size();i++)
  {
    texts[i].setPosition(x,y+(i*10));
  }
}

/**
* \brief
*/
void Menu::setMenuEtat(int val)
{
  menuIsOn = val;
}

/**
* \brief
*/
void Menu::setPlaying()
{
  playing = 1;
}

/**
* \brief
*/
void Menu::playSound()
{
  sound.play();
  playing = 1;
}

/**
* \brief
*/
void Menu::stopSound()
{
  sound.stop();
  playing = 0;
}

/**
* \brief
*/
void Menu::pauseSound()
{
  sound.pause();
  playing = 0;
}

/**
* \brief
*/
void Menu::drawUi(sf::RenderWindow* window)
{
  for(int i=0;i<titreSprite.size();i++)
  {
    window->draw(titreSprite[i]);
  }
}

// ---------------------------------------------------------------------------
