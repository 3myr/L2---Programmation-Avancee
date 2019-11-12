#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


using namespace std;

class Menu
{

  protected:
    // Attribut
    int selectedItemIndex;
    sf::Font font; // Style de caractère
    vector<sf::Text> texts; // Titre des options cliquable
    int menuIsOn;
    float Time;

  public:

  // Constructeurs
  Menu();
  Menu(float width, float height);

  // Fonctions d'observations
  sf::Text getText(int i);
  int getMenuEtat();
  float getTime();

  // Fonctions de transformations
  void setTime(float VAL);
  void setPosition(float x, float y);
  void setMenuEtat(int val);




};
#endif
