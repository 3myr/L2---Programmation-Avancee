#include "Player.cpp"

int main(int argc, char* argv[])
{
  // Variables
  Player joueur;
  sf::RenderWindow window(sf::VideoMode(1280 , 720), "SFML | Tileset"); // Permet d'afficher une fenetre de 1280 par 720 pixels

  // Programme
  // Chargement des textures du personnage
  joueur.setTexture("Character/player.png");

  // Ouverture de fenetre
  while (window.isOpen())
  {
  sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    joueur.movement();
    window.clear();
    window.draw(joueur.getSprite());
    window.display();
  }


  return 0;
}
