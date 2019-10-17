#include "Vaisseau.cpp"
//#include "Attaque.cpp"
#include "Player.cpp"
#include "Enemi.cpp"
#include "Projectile.cpp"
#include "Background.cpp"
#include "View.cpp"
#include "Level.cpp"

using namespace sf;

//#include "Collide.cpp"

int main(int argc, char* argv[])
{
  sf::RenderWindow window(sf::VideoMode(1240 , 720), "Space Shooter"); // Permet d'afficher une fenetre de 12120 par 720 pixels
  sf::Clock clock;
  sf::Clock clock2;
  Vaisseau v;
  Player p;
  Enemi e;
  Background b;

  //Level l1;

  // A mettre dans une classe-------------------------------------
  Projectile projectile;
  vector<Projectile> projectiles;
  //----------------------------------------------------------------

  sf::Window w;
  window.setFramerateLimit(60);

  p = Player("Character/player.txt",6); // Nombre de ligne
  p.setTexture(); // Chercher a enlever
  e = Enemi("Character/enemi.txt",6);
  e.setTexture(); // Chercher a enlever
  b = Background("Background/level.txt","Background/view.txt",1,3);
  b.setTexture(); // Chercher a enlever


  // A mettre dans une classe-------------------------------------
  projectile.setTexture("Projectile/Projectile.png");
  //----------------------------------------------------------------


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

  b.setMovingTime(clock.getElapsedTime().asMilliseconds());
  p.setShootTime(clock.getElapsedTime().asMilliseconds());
  e.setShootTime(clock.getElapsedTime().asMilliseconds());
  clock.restart();

  b.movingView();
  // A mettre dans une classe-------------------------------------
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && p.getShootTime() >= p.getAtqSpeed())
    {
      // On lance une attaque ( qui lance des projectiles )
      projectile.setPosition(p.getSprite().getPosition().x+p.getTexture().getSize().x * p.getSprite().getScale().x,p.getSprite().getPosition().y+15*p.getSprite().getScale().y);
      projectiles.push_back(Projectile(projectile));
      p.setShootTime(-1);
    }

  for(int i=0;i<projectiles.size();i++) // Proj
  {
    projectiles[i].move(15,0);
    if(projectiles[i].getPosition() > b.getView().getCenter().x+b.getWitdhView())
    {
      projectiles.erase(projectiles.begin()+i);
    }
  }
  //----------------------------------------------------------------



  window.clear(); // "Nettoye" la fenetre des anciens pixels présent

  //Evenement
  p.deplacement();
  e.deplacement();
  p.collision(e);
  p.attaque();
  e.attaque(); // A faire


  //Update
  window.draw(b.getSprite());
  window.draw(p.getSprite());
  window.draw(e.getSprite());
  window.setView(b.getView());

  // A mettre dans une classe-------------------------------------
  for(int i=0;i<projectiles.size();i++) // Proj
  {
    window.draw(projectiles[i].getSprite());
  }
  //----------------------------------------------------------------

  window.display();

}
  return 0;
}
