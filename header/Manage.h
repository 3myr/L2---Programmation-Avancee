#ifndef MANAGE_H
#define MANAGE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "MainMenu.h"
#include "PauseMenu.h"


using namespace std;

class Manage
{

  protected:
    // Attribut

  public:

  // Constructeurs
  Manage();

  // Fonctions d'observations

  // Fonctions de transformations
  int mainMenu(sf::RenderWindow* window, MainMenu* m);
  int pauseMenu(sf::RenderWindow* window, PauseMenu* m, MainMenu* mm);



};
#endif
