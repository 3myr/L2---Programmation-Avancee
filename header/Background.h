#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "View.h"

using namespace std;

class Background
{

  protected:

    sf::Texture texture;
    sf::Sprite sprite;
    string filename;

    View mainView;

    float movingTime;


  public:

  // Constructeurs
  Background();
  Background(const std::string FILENAME,const std::string FILENAMEVIEW,int NbLigneInTxt,int NbLigneInTxtView);


  // Fonctions d'observations
  void affiche();
  float getWitdh();
  float getHeight();
  sf::Texture getTexture();
  sf::Sprite getSprite();
  sf::View getView();
  float getWitdhView();
  float getMovingTime();

  // Fonctions de transformations
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  void setTexture();
  void setView(View VIEW);
  void movingView();
  void setMovingTime(float VAL);


}
;
#endif
