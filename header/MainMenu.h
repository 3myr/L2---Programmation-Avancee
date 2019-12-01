#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Menu.h"
#include "../Liste/linkedListe.h"


using namespace std;

class MainMenu : public Menu
{

  protected:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Texture textureUI;
    sf::Sprite spriteUI;

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
