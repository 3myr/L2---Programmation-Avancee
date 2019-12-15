#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"
#include "Bonus.h"

using namespace std;

class Player : public Vaisseau
{
  protected:

    int level;
    int score;
    string bonus;

  public:

  // Constructeurs
  Player();
  Player(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed);
  Player(const std::string FILENAME,int NbLigneInTxt);

  // Fonctions d'observations
  Attaque* getAttque(int i);
  int getScore();
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  string getFilename();
  int getLevel();
  string getBonus();

  // Fonctions de transformations
  void deplacement(Background b);
  void attaque(Background b);
  void freeAtq(Background b);
  int collisionBonus(Bonus* b);
  void setScore(int i);
  void setLevel(int i);

}
;
#endif
