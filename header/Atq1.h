#ifndef ATQ1_H
#define ATQ1_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Attaque.h"


using namespace std;

class Atq1 : public Attaque
{

  protected:
    // Attribut

  public:

  // Constructeurs
  Atq1();

  // Fonctions d'observations

  // Fonctions de transformations
  void moveP(float b);
  void moveE(float b);



};
#endif
