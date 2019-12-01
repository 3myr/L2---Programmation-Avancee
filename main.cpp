#include "Vaisseau.cpp"
#include "Attaque.cpp"
#include "Player.cpp"
#include "Enemi.cpp"
#include "Projectile.cpp"
#include "Background.cpp"
#include "View.cpp"
#include "Atq1.cpp"
#include "Atq2.cpp"
#include "Menu.cpp"
#include "MainMenu.cpp"
#include "PauseMenu.cpp"
#include "Couche.cpp"
#include "Game.cpp"
#include "Interface.cpp"
#include "Liste/linkedListe.cpp"




using namespace sf;

//#include "Collide.cpp"

int main(int argc, char* argv[])
{
  //Declaration des variables
  sf::RenderWindow window(sf::VideoMode(1240 , 720), "Space Shooter",sf::Style::Default); // Permet d'afficher une fenetre de 12120 par 720 pixels
  sf::Clock clock;

  Game game(&window);
  game.start();

  return 0;
}
