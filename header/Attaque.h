#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include <string>
#include <SFML/Audio.hpp>


using namespace std;

class Attaque
{

  protected:
    // Attribut
    Projectile projectile;
    vector<Projectile> projectiles;
    int nbProjectiles; // Nombre de projectiles tirés par attaque

    float timeCastProj;

    //Verifier ou l'on rentre
    string name;

    // Son du projectile
    sf::SoundBuffer buffer;
    sf::Sound sound;

  public:

  // Constructeurs
  Attaque(const std::string FILENAME);

  // Fonctions d'observations
  sf::Sprite getSpritePro(int i);
  int getSizeProj();
  Projectile getProjectile(int i);
  vector<Projectile> getProjectiles();
  string getName();


  // Fonctions de transformations
  void setTextureProj(const std::string FILENAME);
  void setPosition(float x, float y);
  void push_back();
  virtual void moveP(float b);
  virtual void moveE(float b);
  virtual void addProj(float posX, float poxY, float scaleX, float scaleY, float widthSprite);
  void erase(int i);



};
#endif
