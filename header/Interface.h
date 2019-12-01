#ifndef INTERFACE_H
#define INTERFACE_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Background.h"


using namespace std;

class Interface
{

  protected:
    // Gestion de l'affichage
    sf::Sprite sprite;
    sf::Texture texture;

    // Score du joueur
    int score;
    sf::Text scoreText;

    // Gestion de text
    sf::Font font; // Style de caractère
    vector<sf::Text> texts; // Titre des options cliquable

    //Fps
    sf::Font fontFPS;
    sf::Text textFPS;
    sf::Time frameTime;

    // Gestion des animations / raffraichissement
    float Time;


  public:

  // Constructeurs
  Interface();
  Interface(float width, float height);


  // Fonctions d'observations
  sf::Sprite getSprite();
  sf::Texture getTexture();
  sf::Text getText(int i);
  sf::Text getScoreText();
  float getTime();
  int size();



  // Fonctions de transformations
  void setTexture();
  void setTime(float VAL);
  void setPosition(float x, float y);
  void setFrameTime(sf::Clock* clock);
  void setFPS();
  void setPositionFPS(float x, float y);
  void drawFPS(sf::RenderWindow* window);
  void setScore(int i);


}
;
#endif
