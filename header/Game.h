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
#include "Boss.h"
#include "ChoiceMenu.h"
#include "Bonus.h"

using namespace std;
using namespace sf;

class Game
{

  protected:
    // Attribut
    sf::RenderWindow* window;
    sf::Clock clock;
    sf::Clock clock2;

    sf::Font font;
    sf::Text text;

    Player* p;
    linkedListe<Enemi> enemisPero;
    Background b;
    Boss* boss;
    MainMenu* mm;
    PauseMenu* pm;
    ChoiceMenu* cm;
    Interface* ui;
    linkedListe<Bonus> bonus;

    float timer;
    sf::SoundBuffer buffer;
    sf::Sound sound;

  public:

  // Constructeurs
  Game(RenderWindow* window);

  // Fonctions d'observations

  // Fonctions de transformations
  void start();
  void initVariables();
  void refreshVariables();
  void newGameVariables();
  void setTime();
  void draw();
  void quit();
  int checkMainMenu();
  int checkPauseMenu();
  int checkChoiceMenu();
  void save();
  void placementEnemi();
  void placementBonus();
  void evenement();
  void free();




};
#endif
