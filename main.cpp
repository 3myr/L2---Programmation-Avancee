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
#include "otherLinkedList.cpp"
#include "LinkedList.cpp"
#include "Interface.cpp"




using namespace sf;

//#include "Collide.cpp"

int main(int argc, char* argv[])
{
  //Declaration des variables
  sf::RenderWindow window(sf::VideoMode(1240 , 720), "Space Shooter",sf::Style::Default); // Permet d'afficher une fenetre de 12120 par 720 pixels
  sf::Clock clock;


  // TEST DE LA LINKEDLIST
  /*
  Player p = Player("Character/player.txt",6);
  p.setTexture();
  Player p2 = Player("Character/player2.txt",6);
  p2.setTexture();
  Player p3 = Player("Character/player2.txt",6);
  p3.setTexture();

  otherLinkedList<Player> l;
  l.add(p);
  l.add(p2);
  l.add(p3);

  LinkedList<Player> pList;
  pList.insertAtBack(p);
  pList.insertAtBack(p2);


  cout<<l.size()<<endl; // Plante quand taille >1

  */

  Game game(&window);
  game.start();

  return 0;
}
