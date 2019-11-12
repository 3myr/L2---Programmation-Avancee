#include "header/Projectile.h"

// Methode constructive
Projectile::Projectile()
{

}

Projectile::Projectile(const std::string FILENAME) : speed(0.001)
{
  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
  x = sprite.getPosition().x;
  y = sprite.getPosition().y;
}

// Fonctions d'observations
void Projectile::affiche()
{
  cout<<"\nx projectile: "<<x<<endl;
  cout<<"y projectile: "<<y<<endl;
  cout<<"nbDegats projectile: "<<nbDegats<<endl;
  cout<<"x de la texture: "<<texture.getSize().x<<endl;
  cout<<"y de la texture: "<<texture.getSize().y<<endl;
  cout<<"x du sprite: "<<sprite.getPosition().x<<endl;
  cout<<"y du sprite: "<<sprite.getPosition().y<<endl;
}

sf::Sprite Projectile::getSprite()
{
  return sprite;
}

float Projectile::getPosition()
{
  return sprite.getPosition().x;
}

sf::Texture Projectile::getTexture()
{
  return texture;
}



// Fonctions de transformations
void Projectile::move(float x, float y)
{
  sprite.move(x,y);
}

void Projectile::setTexture(const std::string FILENAME)
{
    texture.loadFromFile(FILENAME);
    sprite.setTexture(texture);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    sprite.setScale(0.25,0.25);
}

void Projectile::setPosition(float x,float y)
{
  sprite.setPosition(x,y);
}
