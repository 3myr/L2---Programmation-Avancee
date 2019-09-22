#ifndef MOVING_H
#define MOVING_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
using namespace std;

class Moving
{

private:
  // Attribut

public:

  // Constructeurs
  Moving();
  // Fonctions d'observations

  // Fonctions de transformations
  void getCounterWalking(int* ANIMATIONCOUNTER,Player PLAYER,Animation* ANIMATION);

};
#endif
