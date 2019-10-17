#include "header/Attaque.h"

// Methode constructive
Attaque::Attaque()
{
  projectile = Projectile("Projectile/Projectile.png"); // Proj
}

//Fonctions d'observations


float Attaque::getTimeCastProj()
{
  return timeCastProj;
}

Projectile Attaque::getProjectile()
{
  return projectile;
}

vector<Projectile> Attaque::getProjectiles()
{
  return projectiles;
}

sf::Sprite Attaque::getSpriteProjectiles(int i)
{
  return projectiles[i].getSprite();
}



//Fonctions de transmorfations
void Attaque::setProjectile()
{
  //Emplacement du projectile
  projectile = Projectile("Projectile/Projectile.png");
  projectiles.push_back(Projectile(projectile));
  cout<<"size : "<<projectiles.size()<<endl;
}

void Attaque::setTimeCastProj(float VAL)
{
  timeCastProj = VAL;
}

void Attaque::moveProjectile(int i)
{
  projectiles[i].move(0.1,0);
}

void Attaque::setPositionProjectile(float x, float y)
{
  projectile.setPosition(x,y);
}

void Attaque::push_backProjectile(Projectile projectile)
{
  projectiles.push_back(Projectile(projectile));

}
