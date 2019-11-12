#ifndef PAUSENMENU_H
#define PAUSENMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Menu.h"


using namespace std;

class PauseMenu : public Menu
{

  protected:
    sf::Texture texture;
    sf::Sprite sprite;

  public:

  // Constructeurs
  PauseMenu();
  PauseMenu(float width, float height);

  // Fonctions d'observations
  int getEnter();
  sf::Sprite getSprite();

  // Fonctions de transformations
  void setTexture();
  void choix();
  void setPosition(float x, float y);




};
#endif
