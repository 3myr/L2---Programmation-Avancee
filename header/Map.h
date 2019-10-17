#ifndef MAP_H
#define MAP_H


#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace std;

class Map
{

private:
  // Attribut

  // Taille de la carte
  int mapWidth; //52
  int mapHeight; //60

  // Rendu 2D de la carte
  sf::Texture texture;
  sf::Sprite sprite;

  // Map du jeu
  int* map;

public:

  // Constructeurs
  Map();

  // Fonctions d'observations
  int getMapWitdh() const;
  int getMapHeight() const;
  sf::Texture getTexture() const;
  sf::Sprite getSprite() const;
  int *getMap();
  //int getTile(float X, float Y) const;



  // Fonctions de transformations
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  void setMapWitdh(int WIDTH);
  void setMapHeight(int HEIGHT);
  void setTexture(const std::string FILENAME);
  void saveMap(int* MAP,const std::string FILENAME); // PROBLEME ICI
  void loadMap(const std::string TILESETFILENAME,sf::RenderWindow* WINDOW, int* MAPOPEN);

  // Liberation de memoire
  void memFree();

};
#endif
