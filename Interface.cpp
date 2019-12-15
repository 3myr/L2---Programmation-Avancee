/**
 * \file Interface.cpp
 * \author Demazieres Remy
 * \date 15 decembre 2019
 *
 */
#include "header/Interface.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instancie une interface
*/
Interface::Interface()
{
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
}

/**
* \brief Instancie une interface
*/
Interface::Interface(float width, float height)
{
  //Chargement de la police d'ecriture des textes
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }

  // Implementation des FPS------------------------------
  if(!fontFPS.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
  textFPS.setFont(fontFPS);
  // -----------------------------------------------------

  score = 0;

  // Placement des différent textes------
  sf::Text text;
  text.setFont(font);
  text.setString("Score : ");
  text.setPosition(width, height);

  text.setScale(0.2,0.2);
  texts.push_back(sf::Text(text));

  scoreText.setFont(fontFPS);
  scoreText.setString(to_string(score));
  // -------------------------------------
}

// ---------------------------------------------------------------------------





//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
sf::Text Interface::getText(int i)
{
  return texts[i];
}

/**
* \brief
*/
float Interface::getTime()
{
  return Time;
}

/**
* \brief
*/
sf::Sprite Interface::getSprite()
{
  return sprite;
}

/**
* \brief
*/
sf::Texture Interface::getTexture()
{
  return texture;
}

/**
* \brief
*/
int Interface::size()
{
  return texts.size();
}

/**
* \brief
*/
sf::Text Interface::getScoreText()
{

  return scoreText;
}

/**
* \brief
*/
int Interface::getScore()
{
  return score;
}
// ---------------------------------------------------------------------------





//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Fixe le temps de la clock pour gérer l'animation
*/
void Interface::setTime(float VAL)
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
void Interface::setTexture()
{
  sprite.setTexture(texture);
}

/**
* \brief
*/
void Interface::setPosition(float x, float y)
{
  for(int i=0;i<texts.size();i++)
  {
    texts[i].setPosition(x,y+(i*10)); // A modifier si utiliser
  }
}

/**
* \brief
*/
void Interface::setFrameTime(sf::Clock* clock)
{
  frameTime =  clock->getElapsedTime();
}

/**
* \brief
*/
void Interface::setFPS()
{
  textFPS.setString("Fps: " + to_string(int(1/frameTime.asSeconds())));
  textFPS.setScale(0.20,0.20);
}

/**
* \brief
*/
void Interface::setPositionFPS(float x, float y)
{
  textFPS.setPosition(x,y);
}

/**
* \brief
*/
void Interface::drawFPS(sf::RenderWindow* window)
{
  window->draw(textFPS);
}

/**
* \brief
*/
void Interface::drawScore(sf::RenderWindow* window)
{
  scoreText.setScale(texts[0].getScale().x,texts[0].getScale().y);
  scoreText.setPosition(texts[0].getPosition().x+30, texts[0].getPosition().y);
  window->draw(scoreText);
}

/**
* \brief
*/
void Interface::setScore(int i)
{
  score = i;
  scoreText.setFont(fontFPS);
  scoreText.setString(to_string(score));

}

// ---------------------------------------------------------------------------
