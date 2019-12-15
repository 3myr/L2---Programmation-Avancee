#include "Vaisseau.cpp"
#include "Attaque.cpp"
#include "Player.cpp"
#include "Enemi.cpp"
#include "Projectile.cpp"
#include "Background.cpp"
#include "View.cpp"
#include "Atq1.cpp"
#include "Atq2.cpp"
#include "Atq3.cpp"
#include "Menu.cpp"
#include "MainMenu.cpp"
#include "PauseMenu.cpp"
#include "Couche.cpp"
#include "Interface.cpp"
#include "Liste/linkedListe.cpp"
#include "Boss.cpp"
#include "ChoiceMenu.cpp"
#include "Bonus.cpp"
#include "Game.cpp"

using namespace sf;

int main(int argc, char* argv[])
{
  //Declaration des variables
  sf::RenderWindow window(sf::VideoMode(1240 , 720), "Space Shooter",sf::Style::Default); // Permet d'afficher une fenetre de 12120 par 720 pixels
  sf::Clock clock;

  Game* game = new Game(&window);
  game->start();
  game->free();
  delete game;
  return 0;
}
