#include "header/Atq2.h"

// Methode constructive

Atq2::Atq2(const std::string FILENAME) : Attaque(FILENAME)
{
  name = "AT2";
  nbProjectiles = 3;
  if(!buffer.loadFromFile("Sounds/tir.wav"))
  {
    cout<<"Le sond n'a pas pu être chargé !"<<endl;
    exit(EXIT_FAILURE);
  }
  sound.setBuffer(buffer);
}


//Fonctions d'observations

//Fonctions de transmorfations
void Atq2::moveP(float b)
{
  //cout<<this->getName()<<endl;

  for(int i=0;i<projectiles.size();i++) // Proj
  {
    if(i==0)
    {
      projectiles[i].move(5,-1);
    }
    else
    {
      if(i==1)
      {
        projectiles[i].move(5,0);
      }
      else{
        projectiles[i].move(5,1);
      }
    }
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
    projectiles[i].move(-5,0);
    if(projectiles[i].getPosition() < b)
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
}

void Atq2::addProj(float posX, float poxY, float scaleX, float scaleY, float widthSprite)
{
  for(int i=0;i<nbProjectiles;i++)
  {
    projectile.setPosition(posX+widthSprite*scaleX,poxY+(12+i*15)*scaleY);
    projectiles.push_back(Projectile(projectile));
    sound.play();
  }
}
