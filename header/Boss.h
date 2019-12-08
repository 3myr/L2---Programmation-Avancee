#ifndef BOSS_H
#define BOSS_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"

using namespace std;

class Boss : public Vaisseau
{
  protected:
    float animationTime;
    int isAttaq;

  public:

  // Constructeurs
  Boss();
  Boss(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed);
  Boss(const std::string FILENAME,int NbLigneInTxt);

  // Fonctions d'observations


  // Fonctions de transformations
  void deplacement(Background b);
  void attaque(Background b);
  void setPosition(float x, float y);
  void animation(int ROW);
  void setTime(float VAL);
  void setTexture();

};
#endif
