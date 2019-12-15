/**
 * \file Projectile.cpp
 * \author Demazieres Remy
 * \date 15 decembre 2019
 *
 */
#include "header/Projectile.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instanciation des projectiles
*/
Projectile::Projectile()
{

}

/**
* \brief Instanciation des projectiles
*/
Projectile::Projectile(const std::string FILENAME) : speed(0.001)
{
  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
  x = sprite.getPosition().x;
  y = sprite.getPosition().y;
}

// ---------------------------------------------------------------------------






//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
sf::Sprite Projectile::getSprite()
{
  return sprite;
}

/**
* \brief
*/
float Projectile::getPosition()
{
  return sprite.getPosition().x;
}

/**
* \brief
*/
sf::Texture Projectile::getTexture()
{
  return texture;
}

// ---------------------------------------------------------------------------





//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Deplacement d'un projectile
*/
void Projectile::move(float x, float y)
{
  sprite.move(x,y);
}

/**
* \brief
*/
void Projectile::setTexture(const std::string FILENAME)
{
    texture.loadFromFile(FILENAME);
    sprite.setTexture(texture);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    sprite.setScale(0.25,0.25);
}

/**
* \brief
*/
void Projectile::setPosition(float x,float y)
{
  sprite.setPosition(x,y);
}

// ---------------------------------------------------------------------------
