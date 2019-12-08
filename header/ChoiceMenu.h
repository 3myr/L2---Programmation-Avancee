#ifndef CHOICEMENU_H
#define CHOICEMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Menu.h"
#include "../Liste/linkedListe.h"


using namespace std;

class ChoiceMenu : public Menu
{

  protected:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Texture textureUI[5];
    sf::Sprite spriteUI;

  public:

  // Constructeurs
  ChoiceMenu();
  ChoiceMenu(float width, float height);

  // Fonctions d'observations
  int getEnter();
  sf::Sprite getSprite();

  // Fonctions de transformations
  void setTexture();
  void choix();


};
#endif
