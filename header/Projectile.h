#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Projectile
{

  protected:
  // Attribut
    sf::Texture texture;
    sf::Sprite sprite;

    int nbDegats;

    float x;
    float y;

    float speed;

  public:

  // Constructeurs
  Projectile();
  Projectile(const std::string FILENAME);
  Projectile(const std::string FILENAME, int NBDEGATS, float X, float Y);
  Projectile(const std::string FILENAME, int NBDEGATS);

  // Fonctions d'observations
  void affiche();
  float getPosition();
  sf::Sprite getSprite();
  sf::Texture getTexture();

  // Fonctions de transformations
  void move(float x, float y);
  void setTexture(const std::string FILENAME);
  void setPosition(float x,float y);


};
#endif
