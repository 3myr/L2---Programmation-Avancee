#include "header/Interface.h"

// Methode constructive
Interface::Interface()
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
}

Interface::Interface(float width, float height)
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }

  sf::Text text;
  text.setFont(font);
  text.setString("Score :");
  text.setPosition(width, height);

  text.setScale(0.2,0.2);
  text. setFillColor(sf::Color::Red);
  texts.push_back(sf::Text(text));
}

// Fonctions d'observations

sf::Text Interface::getText(int i)
{
  return texts[i];
}

float Interface::getTime()
{
  return Time;
}

sf::Sprite Interface::getSprite()
{
  return sprite;
}

sf::Texture Interface::getTexture()
{
  return texture;
}

int Interface::size()
{
  return texts.size();
}


// Fonctions constructive

void Interface::setTime(float VAL)
{
  if(VAL==-1) // Mettre le temps a 0
  {
    Time = 0;
  }
  else
  {
    Time = Time + VAL;
  }
}

void Interface::setTexture()
{
  sprite.setTexture(texture);
}

void Interface::setPosition(Background b)
{

}
