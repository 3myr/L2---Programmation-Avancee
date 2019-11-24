#include "header/Attaque.h"

// Methode constructive

Attaque::Attaque(const std::string FILENAME)
{
  projectile.setTexture(FILENAME);
}


//Fonctions d'observations
sf::Sprite Attaque::getSpritePro(int i)
{
  return projectiles[i].getSprite();
}

int Attaque::getSizeProj()
{
  return projectiles.size();
}

Projectile Attaque::getProjectile(int i)
{
  return projectiles[i];
}

vector<Projectile> Attaque::getProjectiles()
{
  return projectiles;
}

string Attaque::getName()
{
  return name;
}


//Fonctions de transmorfations
void Attaque::setTextureProj(const std::string FILENAME)
{
  projectile.setTexture(FILENAME);
}

void Attaque::setPosition(float x, float y)
{
  projectile.setPosition(x,y);
}

void Attaque::push_back()
{
  projectiles.push_back(Projectile(projectile));
}

void Attaque::moveP(float b)
{

}

void Attaque::moveE(float b)
{

}

void Attaque::addProj(float posX, float poxY, float scaleX, float scaleY, float widthSprite)
{

}

void Attaque::erase(int i)
{
  projectiles.erase(projectiles.begin()+i);
}
