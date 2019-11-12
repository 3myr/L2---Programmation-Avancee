#ifndef ATQ2_H
#define ATQ2_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Attaque.h"


using namespace std;

class Atq2 : public Attaque
{

  protected:
    // Attribut

  public:

  // Constructeurs
  Atq2();

  // Fonctions d'observations

  // Fonctions de transformations
  void moveP(float b);
  void moveE(float b);
  virtual void initAtq(float posX, float poxY, float scaleX, float scaleY, float widthSprite);



};
#endif
