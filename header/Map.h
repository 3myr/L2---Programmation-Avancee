#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
using namespace std;

class Map
{

private:
  // Attribut

  // Taille de la carte
  int mapWidth; //52
  int mapHeight; //60

  // Taille des sprites
  float spriteLar; //24
  float spriteLon; //16

  // Taille de la tileset
  int tilsetWidth; //28
  int tilsetHeight; //37

  // Rendu 2D de la carte
  sf::Texture texture;
  sf::Sprite sprite;

  // Map du jeu
  int *map;

public:

  // Constructeurs
  Map();

  // Fonctions d'observations
  int getMapWitdh() const;
  int getMapHeight() const;
  int getSpriteLar() const;
  int getSpriteLon() const;
  sf::Texture getTexture() const;
  sf::Sprite getSprite() const;
  int *getMap();
  int* openMap(const std::string FILENAME);


  // Fonctions de transformations
  void setMapWitdh(int WIDTH);
  void setMapHeight(int HEIGHT);
  void setSpriteLar(float LARGEUR);
  void setSpriteLon(float LONGUEUR);
  void setTexture(const std::string FILENAME, sf::RenderWindow* WINDOW,int* MAP); // Permet un rendu 2d de la map ( texture + sprite )
  void saveMap(int* MAP,const std::string FILENAME); // PROBLEME ICI
  void loadMap(const std::string TILESETFILENAME,sf::RenderWindow* WINDOW, const std::string TXTFILENAME);


};
#endif
