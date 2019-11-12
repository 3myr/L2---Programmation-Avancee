#ifndef COUCHE_H
#define COUCHE_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Couche
{

  protected:

    // Texture de la map
    sf::Texture texture;
    sf::Sprite sprite;
    string filename;

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
  Couche();
  Couche(const std::string FILENAME,int NbLigneInTxt);


  // Fonctions d'observations
  float getWitdh();
  float getHeight();
  sf::Texture getTexture();
  sf::Sprite getSprite();
  void openMap(const std::string FILENAME, int NbLigneInTxt);


  // Fonctions de transformations
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  void setTexture();
  void drawMap(sf::RenderWindow* WINDOW);
  void setTextureTileSet();


}
;
#endif
