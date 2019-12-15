#ifndef BOSS_H
#define BOSS_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"
#include <cstdlib>
#include <ctime>


using namespace std;

class Boss : public Vaisseau
{
  protected:
    float animationTime;
    int isAttaq;
    int descente;
    int nbOfProjectile;
    string nameAtq;
    int vaincu;

  public:

  // Constructeurs
  Boss();
  Boss(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed);
  Boss(const std::string FILENAME,int NbLigneInTxt);

  // Fonctions d'observations
  int getEtat();
  void loadVar(const std::string FILENAME,int NbLigneInTxt);

  // Fonctions de transformations
  void deplacement(Background b);
  void attaque(Background b);
  void setPosition(float x, float y);
  void animation(int ROW);
  void setTime(float VAL);
  void setTexture();
  void setEtat(int x);
  int dead(Background b);
  void freeAtq(Background b);

};
#endif
