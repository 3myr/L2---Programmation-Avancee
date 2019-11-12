#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Menu.h"


using namespace std;

class MainMenu : public Menu
{

  protected:
    sf::Texture texture;
    sf::Sprite sprite;

  public:

  // Constructeurs
  MainMenu();
  MainMenu(float width, float height);

  // Fonctions d'observations
  int getEnter();
  sf::Sprite getSprite();

  // Fonctions de transformations
  void setTexture();
  void choix();


};
#endif
