#ifndef INTERFACE_H
#define INTERFACE_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Player.h"


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
  Interface(float width, float height, sf::Texture texture);


  // Fonctions d'observations
  sf::Sprite getSprite();
  sf::Texture getTexture();
  sf::Text getText(int i);
  float getTime();

  // Fonctions de transformations
  void setTexture();
  void setTime(float VAL);

}
;
#endif
