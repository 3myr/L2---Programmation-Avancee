#include "header/Atq1.h"

// Methode constructive

Atq1::Atq1(const std::string FILENAME) : Attaque(FILENAME)
{
  name="ATQ1";
  nbProjectiles = 2;
}


//Fonctions d'observations

//Fonctions de transmorfations
void Atq1::moveP(float b)
{
  for(int i=0;i<projectiles.size();i++) // Proj // PROBLEME LA SIZE EST DE 0
  {
    projectiles[i].move(5,0);
    if(projectiles[i].getPosition() > b)
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
}

void Atq1::moveE(float b)
{
  for(int i=0;i<projectiles.size();i++) // Proj
  {
    projectiles[i].move(-5,0);
    if(projectiles[i].getPosition() < b)
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
}

void Atq1::addProj(float posX, float poxY, float scaleX, float scaleY, float widthSprite)
{
  for(int i=0;i<nbProjectiles;i++)
  {
    projectile.setPosition(posX+widthSprite*scaleX,poxY+(15+i*11)*scaleY);
    projectiles.push_back(Projectile(projectile));
  }
}
