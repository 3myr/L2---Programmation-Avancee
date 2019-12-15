#ifndef BONUS_H
#define BONUS_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Background.h"
#include "Vaisseau.h"

using namespace std;

class Bonus
{

protected:

  // Affichage du bonus
  sf::Texture texture;
  sf::Sprite sprite;
  string filename;

  // Position
  float x;
  float y;

  // Vitesse de déplacement
  float speed;
  int descente;

  // Nom du bonus
  string nom;


public:

  // Constructeurs
  Bonus();
  Bonus(float x, float y, sf::Texture texture, float speed );
  Bonus(const std::string FILENAME,int NbLigneInTxt);


  // Fonctions d'observations
  sf::Sprite getSprite();
  sf::Texture getTexture();
  float getSpeed();
  float getPosition();
  string getName();


  // Fonctions de transformations
  void setTexture();
  int collision(Vaisseau* v2);
  void deplacement(Background b);
  void loadVar(const std::string FILENAME,int NbLigneInTxt);


};
#endif
