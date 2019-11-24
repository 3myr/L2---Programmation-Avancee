#include "header/Menu.h"

// Methode constructive

Menu::Menu()
{

}

Menu::Menu(float width, float height)
{

}


//Fonctions d'observations
sf::Text Menu::getText(int i)
{
  return texts[i];
}

int Menu::getMenuEtat()
{
  return menuIsOn;
}

float Menu::getTime()
{
  return Time;
}


//Fonctions de transmorfations

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


void Menu::setPosition(float x, float y)
{
  for(int i=0;i<texts.size();i++)
  {
    texts[i].setPosition(x,y+(i*10));
  }
}

void Menu::setMenuEtat(int val)
{
  menuIsOn = val;
}
