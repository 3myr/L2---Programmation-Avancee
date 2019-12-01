#ifndef GAME_H
#define GAME_H

#include "Vaisseau.h"
#include "Attaque.h"
#include "Player.h"
#include "Enemi.h"
#include "Projectile.h"
#include "Background.h"
#include "View.h"
#include "Atq1.h"
#include "Atq2.h"
#include "Menu.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "Couche.h"
#include "Interface.h"
#include "../Liste/linkedListe.h"

using namespace std;
using namespace sf;

class Game
{

  protected:
    // Attribut
    sf::RenderWindow* window;
    sf::Clock clock;

    sf::Font font;
    sf::Text text;

    Player p;
    vector<Enemi*> enemis;
    Background b;
    Couche c1,c2,c3,c4,c5,c6;
    MainMenu* mm;
    PauseMenu* pm;
    Interface* ui;

  public:

  // Constructeurs
  Game(RenderWindow* window);

  // Fonctions d'observations

  // Fonctions de transformations
  void start();
  void initVariables();
  void setTime();
  void draw();
  void quit();
  int checkMainMenu();
  int checkPauseMenu();
  void save();




};
#endif
