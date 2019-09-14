#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Environnement.h"
using namespace std;

class System
{

private:

  // Camera de jeu
  sf::View mainView;

  int sizeX = 310;
  int sizeY = 240;


public:

  // Constructeurs
    System();

  // Fonctions d'observations
  sf::View getView() const;
  int getSizeX() const;
  int getSizeY() const;


  // Fonctions de transformations
  void setView(sf::View VIEW);
  void centerPlayer(Player PLAYER);
  void setSizeX(int SIZEX);
  void setSizeY(int SIZEY);
  void initialisate();
  void animationCounter(Player JOUEUR, int COUNTERWALKING, int ANIMATIONCOUNTER);
};
#endif
