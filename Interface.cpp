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

  // Implementation des FPS
  if(!fontFPS.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
  textFPS.setFont(fontFPS);

  sf::Text text;
  text.setFont(font);
  text.setString("Score :");
  text.setPosition(width, height);

  text.setScale(0.2,0.2);
  texts.push_back(sf::Text(text));

  score = 0;
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

sf::Text Interface::getScoreText()
{

  return scoreText;
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

void Interface::setPosition(float x, float y)
{
  for(int i=0;i<texts.size();i++)
  {
    texts[i].setPosition(x,y+(i*10)); // A modifier si utiliser
  }
}
void Interface::setFrameTime(sf::Clock* clock)
{
  frameTime =  clock->getElapsedTime();
}

void Interface::setFPS()
{
  textFPS.setString("Fps: " + to_string(int(1/frameTime.asSeconds())));
  textFPS.setScale(0.20,0.20);
}

void Interface::setPositionFPS(float x, float y)
{
  textFPS.setPosition(x,y);
}

void Interface::drawFPS(sf::RenderWindow* window)
{
  window->draw(textFPS);
}

void Interface::setScore(int i)
{
  score = score +i;
  scoreText.setFont(fontFPS);
  scoreText.setString(score+"");
  scoreText.setPosition(texts[0].getPosition().x, texts[0].getPosition().y);
}
