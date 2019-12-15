/**
 * \file Attaque.cpp
 * \author Demazieres Remy
 * \date 15 decembre 2019
 *
 */
#include "header/Attaque.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instancie une attaque
*/
Attaque::Attaque(const std::string FILENAME)
{
  projectile.setTexture(FILENAME);
}

// ---------------------------------------------------------------------------






//Fonctions d'observations ---------------------------------------------------
/**
* \brief
*/
sf::Sprite Attaque::getSpritePro(int i)
{
  return projectiles[i].getSprite();
}

/**
* \brief
*/
int Attaque::getSizeProj()
{
  return projectiles.size();
}

/**
* \brief
*/
Projectile Attaque::getProjectile(int i)
{
  return projectiles[i];
}

/**
* \brief
*/
vector<Projectile> Attaque::getProjectiles()
{
  return projectiles;
}

/**
* \brief
*/
string Attaque::getName()
{
  return name;
}


// ---------------------------------------------------------------------------




//Fonctions de transmorfations -----------------------------------------------
/**
* \brief Defini la texture d'un projectile
*/
void Attaque::setTextureProj(const std::string FILENAME)
{
  projectile.setTexture(FILENAME);
}

/**
* \brief
*/
void Attaque::setPosition(float x, float y)
{
  projectile.setPosition(x,y);
}

/**
* \brief Place le projectile dans l'attaque
*/
void Attaque::push_back()
{
  projectiles.push_back(Projectile(projectile));
}

/**
* \brief Deplacement du projectile pour un joueur
*/
void Attaque::moveP(float b)
{

}

/**
* \brief Deplacement du projectile pour un enemi
*/
void Attaque::moveE(float b)
{

}

/**
* \brief Ajoute un projectile a une position précise
*/
void Attaque::addProj(float posX, float poxY, float scaleX, float scaleY, float widthSprite)
{

}

/**
* \brief Supprime un projectile d'une attaque
*/
void Attaque::erase(int i)
{
  projectiles.erase(projectiles.begin()+i);
}

/**
* \brief Arrete le sons d'une attaque
*/
void Attaque::stopSound()
{
  sound.stop();
}


// ---------------------------------------------------------------------------
