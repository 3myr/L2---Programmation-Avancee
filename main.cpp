#include "Vaisseau.cpp"
#include "Attaque.cpp"
#include "Player.cpp"
#include "Enemi.cpp"
#include "Projectile.cpp"
#include "Background.cpp"
#include "View.cpp"
#include "Level.cpp"
#include "Atq1.cpp"
#include "Atq2.cpp"
#include "Menu.cpp"
#include "MainMenu.cpp"
#include "PauseMenu.cpp"
#include "Manage.cpp"
#include "Couche.cpp"

using namespace sf;

//#include "Collide.cpp"

int main(int argc, char* argv[])
{
  //Declaration des variables
  sf::RenderWindow window(sf::VideoMode(1240 , 720), "Space Shooter",sf::Style::Default); // Permet d'afficher une fenetre de 12120 par 720 pixels
  sf::Clock clock;

  // A mettre dans une classe-------------------------------------
  sf::Font font;
  sf::Text text;
  //----------------------------------------------------------------

  Player p;
  Enemi e;
  Background b;
  Manage manage;
  Couche c1,c2,c3,c4,c5,c6;

  //Restrictins a 60FPS ( pour éviter les lags )
  window.setVerticalSyncEnabled(false);
  window.setFramerateLimit(60);

  //Initialisation des variables
  p = Player("Character/player.txt",6); // Nombre de ligne
  p.setTexture(); // Chercher a enlever
  e = Enemi("Character/enemi.txt",6);
  e.setTexture(); // Chercher a enlever
  b = Background("Background/view.txt",1);
  b.setTexture(); // Chercher a enlever

  // A METTRE DANS LA CLASSE BACKGROUND ------------
  c1 = Couche("Background/background.txt",7);
  c1.setTextureTileSet();
  c2 = Couche("Background/mountains1.txt",7);
  c2.setTextureTileSet();
  c3 = Couche("Background/mountains2.txt",7);
  c3.setTextureTileSet();
  c4 = Couche("Background/arbre1.txt",7);
  c4.setTextureTileSet();
  c5 = Couche("Background/arbre2.txt",7);
  c5.setTextureTileSet();
  c6 = Couche("Background/moon.txt",7);
  c6.setTextureTileSet();
  // -----------------------------------------------

  // A mettre dans une classe-------------------------------------
  if(!font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
  text.setFont(font);
    //----------------------------------------------------------------

  MainMenu mm(b.getWitdhView(),b.getHeightView());
  mm.setTexture();
  PauseMenu pm(b.getWitdhView(),b.getHeightView());

  //Boucle de jeu
  while (window.isOpen())
  {
    // A mettre dans une classe-------------------------------------
    sf::Time frameTime = clock.getElapsedTime();
    text.setString("Fps: " + to_string(int(1/frameTime.asSeconds())));
    text.setScale(0.20,0.20);
    //----------------------------------------------------------------

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    //Recupération du temps pour les différents événements
    b.setMovingTime(clock.getElapsedTime().asMilliseconds());
    p.setShootTime(clock.getElapsedTime().asMilliseconds());
    e.setShootTime(clock.getElapsedTime().asMilliseconds());
    pm.setTime(clock.getElapsedTime().asMilliseconds());
    mm.setTime(clock.getElapsedTime().asMilliseconds());
    clock.restart();


    if(manage.mainMenu(&window,&mm)==1)
    {
      window.setView(window.getDefaultView());
    }
    else
    {
      if(manage.pauseMenu(&window,&pm,&mm)==0)
      {

        //Deplacement de la caméra
        b.movingView();


        // "Nettoye" la fenetre des anciens pixels présent
        window.clear();


        //Evenements
        p.deplacement(b);
        e.deplacement(); // Supprimer e quand COLLISION ( sinon baisse constante de fps )
        p.stayInScreen(b);
        p.collision(e);
        p.attaque(b);
        e.attaque(b); // Supprimer e quand COLLISION ( sinon baisse constante de fps )
        pm.setPosition(b.getView().getCenter().x-20,60);

        // A mettre dans une classe-------------------------------------
        text.setPosition(b.getView().getCenter().x-162,0);
        //----------------------------------------------------------------


        // A mettre dans une classe-------------------------------------
        for(int i=0;i<p.getSizeProj();i++)
        {
          e.collision(p.getProjectile(i));
        }
        for(int i=0;i<e.getSizeProj();i++)
        {
          p.collision(e.getProjectile(i));
        }
        //----------------------------------------------------------------




        //Updates
        //window.draw(b.getSprite());
        for(int i=0;i<5;i++)
        {
        }

        // A METTRE DANS LA CLASSE BACKGROUND ------------
        c1.drawMap(&window);
        c6.drawMap(&window);
        c2.drawMap(&window);
        c3.drawMap(&window);
        c4.drawMap(&window);
        c5.drawMap(&window);
        // -----------------------------------------------

        window.draw(p.getSprite());
        window.draw(e.getSprite());

        // Emplacement du texte menu |
        //                           v


        // A mettre dans une classe-------------------------------------
        for(int i=0;i<p.getSizeProj();i++) // Proj
        {
          window.draw(p.getSpritePro(i));
        }
        for(int i=0;i<e.getSizeProj();i++) // Proj
        {
          window.draw(e.getSpritePro(i));
        }
        //----------------------------------------------------------------


        // A mettre dans une classe-------------------------------------
        window.draw(text);
        //----------------------------------------------------------------
      }

    // Affichage des éléments
    window.setView(b.getView());
    window.display();
    }
  }

  return 0;
}
