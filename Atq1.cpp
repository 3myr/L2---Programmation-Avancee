#include "header/Atq1.h"

// Methode constructive

Atq1::Atq1() : Attaque()
{

}


//Fonctions d'observations

//Fonctions de transmorfations
void Atq1::moveP(float b)
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

void Atq1::moveE(float b)
{
  for(int i=0;i<projectiles.size();i++) // Proj
  {
    projectiles[i].move(0,0);
    if(projectiles[i].getPosition() > b)
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
}
