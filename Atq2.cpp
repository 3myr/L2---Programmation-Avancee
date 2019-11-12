#include "header/Atq2.h"

// Methode constructive

Atq2::Atq2() : Attaque()
{

}


//Fonctions d'observations

//Fonctions de transmorfations
void Atq2::moveP(float b)
{

  for(int i=0;i<projectiles.size();i++) // Proj
  {
    projectiles[i].move(100,0);
    if(projectiles[i].getPosition() > b)
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
}

void Atq2::moveE(float b)
{
  for(int i=0;i<projectiles.size();i++) // Proj
  {
    projectiles[i].move(-50,0);
    if(projectiles[i].getPosition() > b)
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
}

void Atq2::initAtq(float posX, float poxY, float scaleX, float scaleY, float widthSprite)
{
  for(int i=0;i<this->getSizeProj();i++)
  {
    projectile.setPosition(posX+widthSprite*scaleX,poxY+(12+i*15)*scaleY);
    projectiles.push_back(Projectile(projectile));
  }
}
