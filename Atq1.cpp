#include "header/Atq1.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instancié une attaque
*/
Atq1::Atq1(const std::string FILENAME) : Attaque(FILENAME)
{
  name="ATQ1";
  nbProjectiles = 2;
  // Charge le son pour les tires
  if(!buffer.loadFromFile("Sounds/tir.ogg"))
  {
    cout<<"Le sond n'a pas pu être chargé !"<<endl;
    exit(EXIT_FAILURE);
  }
  sound.setBuffer(buffer);
}

// ---------------------------------------------------------------------------





//Fonctions d'observations ---------------------------------------------------

// ---------------------------------------------------------------------------






//Fonctions de transmorfations -----------------------------------------------
/**
* \brief Deplacement du projectile pour un joueur
*/
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

/**
* \brief Deplacement du projectile pour un enemi
*/
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

/**
* \brief Ajoute un projectile a une position précise
*/
void Atq1::addProj(float posX, float poxY, float scaleX, float scaleY, float widthSprite)
{
  for(int i=0;i<nbProjectiles;i++)
  {
    projectile.setPosition(posX+widthSprite*scaleX,poxY+(15+i*11)*scaleY);
    projectiles.push_back(Projectile(projectile));
    sound.play(); // Joue le son de tir
  }
}

// ---------------------------------------------------------------------------
