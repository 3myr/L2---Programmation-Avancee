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

    // Gestion de text
    sf::Font font; // Style de caractère
    vector<sf::Text> texts; // Titre des options cliquable

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
  float getTime();
  int size();



  // Fonctions de transformations
  void setTexture();
  void setTime(float VAL);
  void setPosition(Background b);

}
;
#endif
