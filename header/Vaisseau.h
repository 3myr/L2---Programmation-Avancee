#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Projectile.h"

using namespace std;

class Vaisseau
{

protected:

  sf::Texture texture;
  sf::Sprite sprite;
  string filename;

  float x;
  float y;

  int pv;
  int atqSpeed;

  float speed;

  float shootTime;


public:

  // Constructeurs
  Vaisseau();
  Vaisseau(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed );
  Vaisseau(const std::string FILENAME,int NbLigneInTxt);
  // Fonctions d'observations
  void affiche();
  sf::Sprite getSprite();
  sf::Texture getTexture();
  float getShootTime();
  int getAtqSpeed();




  // Fonctions de transformations
  void setTexture();
  void setShootTime(float VAL);
  void collision(Vaisseau v2);
  void collision(Projectile p);
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  void attaque();

};
#endif
