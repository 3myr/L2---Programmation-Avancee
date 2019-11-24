#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"

using namespace std;

class Player : public Vaisseau
{
  protected:

  public:

  // Constructeurs
  Player();
  Player(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed);
  Player(const std::string FILENAME,int NbLigneInTxt);

  // Fonctions d'observations
  void affiche();
  Attaque* getAttque(int i);

  // Fonctions de transformations
  void deplacement(Background b);
  void attaque(Background b);
  void collisionProjectile(Vaisseau e);

}
;
#endif
