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
  Projectile getProjectile();
  vector<Projectile> getProjectiles();
  float getTimeCastProj();
  sf::Sprite getSpriteProjectiles(int i);




  // Fonctions de transformations
  void setProjectile();
  void setTimeCastProj(float VAL);
  void moveProjectile(int i);
  void setPositionProjectile(float x, float y);
  void push_backProjectile(Projectile projectile);


};
#endif
