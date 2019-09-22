#include "Map.cpp"
#include "Player.cpp"
#include "Animation.cpp"
#include "Monster.cpp"
#include "Camera.cpp"
#include "Collide.cpp"

int main(int argc, char* argv[])
{
  // Variables de classes
  sf::RenderWindow window(sf::VideoMode(1248 , 960), "SFML | Tileset"); // Permet d'afficher une fenetre de 12120 par 720 pixels
  sf::Clock clock;
  Player joueur;
  Map map;
  Camera view;
  Animation playerAnimation;
  Collide collisionManagement;

  //Initialisation
  joueur = Player();
  joueur.setTexture("Character/alundrawalk.png");
  //joueur.setTexture("Character/redrectangle.png");
  map = Map();
  view = Camera();
  playerAnimation = Animation();
  collisionManagement = Collide();


  //Variables secondaires
  int animationCounter = 0;

  // Programme
  while (window.isOpen())
  {
    view.setViewCenterPlayer(joueur); // Centre la vue sur le joueur

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    //cout << "Actual X: " << joueur.getX() << endl;
    //cout << "Old X: " << joueur.getOldX() << endl;

    joueur.movement(playerAnimation.getCounterWalking()); // Gere les touches de clavier / joystick pour déplacer le personnage
    collisionManagement.collision(&joueur);

    animationCounter += clock.restart().asMilliseconds();
    playerAnimation.durationAnimation(&animationCounter,joueur); // Permet de déterminé la vitesse de l'animation du personnage
    window.clear(); // "Nettoye" la fenetre des anciens pixels présent
    window.setView(view.getView()); // Applique la vue de la caméra
    collisionManagement.loadMap("Background/collide.png",&window,"Map/inoaVillageCollide.txt");
    map.loadMap("Background/tileSetVillage.png",&window,"Map/inoaVillage.txt");
    window.draw(map.getSprite());
    window.draw(joueur.getSprite());
    window.display();
  }
  return 0;
}
