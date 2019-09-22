#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace std;

class Animation
{

private:
  // Attribut
  int frameDuration; //100
  int counterWalking;


public:

  // Constructeurs
  Animation();
  // Fonctions d'observations
  int getFrameDuration() const;
  int getCounterWalking() const;
  void durationAnimation(int* ANIMATIONCOUNTER,Player PLAYER);

  // Fonctions de transformations
  void setFrameDuration(int FRAMEDURATION);
  void setCounterWalking(int COUNTERWALKING);
  void setCounterWalkingAdd1();
  void setCounterWalkingAt0();

};
#endif
