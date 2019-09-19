#include "Player.cpp"
#include "Environnement.cpp"
#include "System.cpp"

int main(int argc, char* argv[])
{

  // Variables
  Player joueur;
  Environnement background;
  Environnement decor;
  Environnement collide;
  System mainView;
  sf::RenderWindow window(sf::VideoMode(1248 , 960), "SFML | Tileset"); // Permet d'afficher une fenetre de 12120 par 720 pixels
  sf::Clock clock;
  int animationCounter = 0;
  int counterWalking =0;

  // Programme
  // Chargement des textures du personnage
  joueur.setTexture("Character/alundrawalk.png", &counterWalking);
  mainView.initialisate();
  // Ouverture de fenetre
  while (window.isOpen())
  {

    mainView.centerPlayer(joueur);
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    joueur.movement(&counterWalking);
    animationCounter += clock.restart().asMilliseconds();
    //animationCounter(joueur,&counterWalking,&animationCounter);
    // A METTRE EN FONCTION MAIS PROBLEME
    if (animationCounter >= joueur.getFrameDuration()) // Comparaison pour savoir si l'on passe au sprite suivant de l'animation
    {
      animationCounter =0;
      counterWalking++;
      if (counterWalking == 6) // Permet de choisir le bon sprite pour que l'animation soit fluide et cohérente
      {
        counterWalking = 0;
      }
    }


    window.clear();
    window.setView(mainView.getView());
    background.setTexture("Background/tileSetVillage.png",&window, mainView.openMap("Map/inoaVillage.txt"));
    collide.setTexture("Background/collide.png",&window,mainView.openMap("Map/inoaVillageCollide.txt"));
    collide.collision(joueur);
    window.draw(background.getSprite());
    window.draw(joueur.getSprite());
    decor.setTexture("Background/tileSetVillage.png", &window, mainView.openMap("Map/inoaVillage2.txt"));
    window.setView(window.getDefaultView()); // Inutile ?
    window.display();
  }
  mainView.saveMap(background.getMap(),"Map/inoaVillage3.txt");


  return 0;
}
