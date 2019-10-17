#ifndef LEVEL_H
#define LEVEL_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Background.h"

using namespace std;

class Level : public Background
{

  protected:
    string nom;

  public:

  // Constructeurs
  Level();
  Level(const std::string FILENAME,const std::string FILENAMEVIEW,int NbLigneInTxt,int NbLigneInTxtView);


  // Fonctions d'observations
  void affiche();

  // Fonctions de transformations

}
;
#endif
