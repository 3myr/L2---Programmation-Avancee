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

    // Texture de la map
    sf::Texture texture;
    sf::Sprite sprite;
    string filename;

    // La camera
    View mainView;
    float movingTime;

    // la map
    sf::Texture tileSetTexture;
    sf::Sprite tileSetSprite;
    string tileSetTextureName;
    int height;
    int width;
    int spriteLarg;
    int spriteLong;
    int tileSetWidth;
    int tileSetHeight;
    int* map;

  public:

  // Constructeurs
  Background();
  Background(const std::string FILENAMEVIEW,int NbLigneInTxtView);


  // Fonctions d'observations
  void affiche();
  float getWitdh();
  float getHeight();
  sf::Texture getTexture();
  sf::Sprite getSprite();
  sf::View getView();
  float getWitdhView();
  float getHeightView();
  float getMovingTime();
  View getMainView();
  void openMap(const std::string FILENAME, int NbLigneInTxt);


  // Fonctions de transformations
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  void setTexture();
  void setView(View VIEW);
  void movingView();
  void setMovingTime(float VAL);
  void drawMap(sf::RenderWindow* WINDOW);
  void setTextureTileSet();


}
;
#endif
