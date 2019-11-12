#include "header/Attaque.h"

// Methode constructive

Attaque::Attaque()
{

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
  for(int i=0;i<projectiles.size();i++) // Proj
  {
    projectiles[i].move(30,0);
    if(projectiles[i].getPosition() > b)
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
}

void Attaque::moveE(float b)
{
  for(int i=0;i<projectiles.size();i++) // Proj
  {
    projectiles[i].move(-5,0);
    if(projectiles[i].getPosition() > b)
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
}
