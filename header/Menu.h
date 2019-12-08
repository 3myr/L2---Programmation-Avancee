#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Audio.hpp>
#include "../Liste/linkedListe.h"


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

    //Musique des menus
    sf::SoundBuffer buffer;
    sf::Sound sound;
    int playing;

    // UI
    vector<sf::Sprite> titreSprite;
    sf::Texture titleTexture;
    sf::Sprite titleSprite;

  public:

  // Constructeurs
  Menu();
  Menu(float width, float height);

  // Fonctions d'observations
  sf::Text getText(int i);
  int getMenuEtat();
  float getTime();
  int isPlaying();
  int getSelectedItemIndex();

  // Fonctions de transformations
  void setTime(float VAL);
  void setPosition(float x, float y);
  void setMenuEtat(int val);
  void setPlaying();
  void playSound();
  void stopSound();
  void pauseSound();
  void drawUi(sf::RenderWindow* window);





};
#endif
