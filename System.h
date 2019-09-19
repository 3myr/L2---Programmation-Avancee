#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Environnement.h"
using namespace std;

class System
{

private:

  // Camera de jeu
  sf::View mainView;

  int sizeX = 310;
  int sizeY = 240;

  // Enregistrement de la carte REFAIRE LES CLASSES
  ofstream myMap;
  int width = 52;
  int height = 60;

  // Lecture de la carte
  int line_int[3120]={0};

public:

  // Constructeurs
    System();

  // Fonctions d'observations
  sf::View getView() const;
  int getSizeX() const;
  int getSizeY() const;
  int* openMap(const std::string FILENAME);


  // Fonctions de transformations
  void setView(sf::View VIEW);
  void centerPlayer(Player PLAYER);
  void setSizeX(int SIZEX);
  void setSizeY(int SIZEY);
  void initialisate();
  void animationCounter(Player JOUEUR, int COUNTERWALKING, int ANIMATIONCOUNTER);
  void saveMap(int* MAP,const std::string FILENAME); // PROBLEME ICI

};
#endif
