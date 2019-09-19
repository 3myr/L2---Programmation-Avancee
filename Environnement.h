#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "System.h"
using namespace std;

class Environnement
{

private:
  // Attribut

  // Taille de la carte
  int mapWidth = 52; //26
  int mapHeight = 60; //30

  // Taille des sprites
  float spriteLar = 24; //48
  float spriteLon = 16; //32

  // Taille de la tileset*
  int tilsetWidth = 28;
  int tilsetHeight = 37;

  // Rendu 2D de la carte
  sf::Texture texture;
  sf::Sprite sprite;
  sf::VertexArray vertices;

  int map[3120]; // CHANGER
  int mapCollide[3120];


public:

  // Constructeurs
    Environnement();

  // Fonctions d'observations
  int getMapWitdh() const;
  int getMapHeight() const;
  int getSpriteLar() const;
  int getSpriteLon() const;
  sf::Texture getTexture() const;
  sf::Sprite getSprite() const;
  int *getMap();

  // Fonctions de transformations
  void setMapWitdh(int WIDTH);
  void setMapHeight(int HEIGHT);
  void setSpriteLar(float LARGEUR);
  void setSpriteLon(float LONGUEUR);
  void setTexture(const std::string FILENAME, sf::RenderWindow* WINDOW, int* map); // Permet un rendu 2d de la map ( texture + sprite )
  void collision(Player PLAYER);

};
#endif
