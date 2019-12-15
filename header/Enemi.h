#ifndef ENEMI_H
#define ENEMI_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"

using namespace std;

class Enemi : public Vaisseau
{
  protected:

  public:

  // Constructeurs
  Enemi();
  Enemi(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed);
  Enemi(const std::string FILENAME,int NbLigneInTxt);

  // Fonctions d'observations
  void loadVar(const std::string FILENAME,int NbLigneInTxt);


  // Fonctions de transformations
  void deplacement(Background b);
  void attaque(Background b);
  void setPosition(float x, float y);
  void freeAtq(Background b);

};
#endif
