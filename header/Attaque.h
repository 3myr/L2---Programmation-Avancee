#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Projectile.h"


using namespace std;

class Attaque
{

  protected:
    // Attribut
    Projectile projectile;
    vector<Projectile> projectiles;

    float timeCastProj;

  public:

  // Constructeurs
  Attaque();

  // Fonctions d'observations
  sf::Sprite getSpritePro(int i);
  int getSizeProj();
  Projectile getProjectile(int i);




  // Fonctions de transformations
  void setTextureProj(const std::string FILENAME);
  void setPosition(float x, float y);
  void push_back();
  void moveP(float b);
  void moveE(float b);



};
#endif
