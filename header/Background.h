#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "View.h"
#include "Couche.h"

using namespace std;

class Background
{

  protected:

    // Texture de la map
    sf::Texture texture;
    sf::Sprite sprite;
    string filename;

    // La camera
    View mainView;
    float movingTime;

    // Couche de la map
    vector<Couche*> couches;

  public:

  // Constructeurs
  Background();
  Background(const std::string FILENAMEVIEW,int NbLigneInTxtView);


  // Fonctions d'observations
  float getWitdh();
  float getHeight();
  sf::View getView();
  float getWitdhView();
  float getHeightView();
  float getMovingTime();
  View getMainView();
  Couche* getCouche(int i);
  vector<Couche*> getCouches();

  // Fonctions de transformations
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  void setView(View VIEW);
  void movingView();
  void setMovingTime(float VAL);


}
;
#endif
