#ifndef ATQ1_H
#define ATQ1_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Attaque.h"
#include <SFML/Audio.hpp>


using namespace std;

class Atq1 : public Attaque
{

  protected:
    // Attribut

  public:

  // Constructeurs ----------------------------

  Atq1(const std::string FILENAME);

  // ------------------------------------------

  // Fonctions d'observations -----------------

  // ------------------------------------------


  // Fonctions de transformations -------------
  
  void moveP(float b);
  void moveE(float b);
  void addProj(float posX, float poxY, float scaleX, float scaleY, float widthSprite);

  // ------------------------------------------



};
#endif
