#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Background.h"
#include "Atq1.h"
#include "Atq2.h"

using namespace std;

class Vaisseau
{

protected:

  sf::Texture texture;
  sf::Sprite sprite;
  string filename;

  float x;
  float y;

  int pv;
  int atqSpeed;

  float speed;

  float shootTime;

  vector<Attaque*> atqs; // Allocation memoire; quand change attaque desalloué memoire puis refaire allocations


public:

  // Constructeurs
  Vaisseau();
  Vaisseau(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed );
  Vaisseau(const std::string FILENAME,int NbLigneInTxt);

  // Fonctions d'observations
  virtual void affiche();
  sf::Sprite getSprite();
  sf::Texture getTexture();
  float getShootTime();
  int getAtqSpeed();
  sf::Sprite getSpritePro(int i);
  int getSizeProj(int i);
  Projectile getProjectile(int i);
  vector<Projectile> getProjectiles(int i);
  int getSizeAtqs();
  int getPv();


  // Fonctions de transformations
  void setTexture();
  void setShootTime(float VAL);
  int collision(Vaisseau* v2);
  int collision(Projectile p);
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  virtual void attaque(Background b);
  virtual void deplacement(Background b);
  void stayInScreen(Background b);
  void drawAttaque(sf::RenderWindow* window,int i);
  Vaisseau copyVaisseau(Vaisseau* e);


};
#endif
