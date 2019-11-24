#include "header/Game.h"

Game::Game(RenderWindow* window)
{
  this->window = window;
}

/**
* Initialise les variables
*
*/
void Game::initVariables()
{
  //Initialisation des personnages et du Décor
  this->p = Player("Character/player.txt",6); // Nombre de ligne
  this->p.setTexture(); // Chercher a enlever
  this->e = Enemi("Character/enemi.txt",6);
  this->e.setTexture(); // Chercher a enlever
  this->b = Background("Background/view.txt",3);

  // A METTRE DANS LA CLASSE BACKGROUND ------------
  this->c1 = Couche("Background/background.txt",7);
  this->c1.setTextureTileSet();
  this->c2 = Couche("Background/mountains1.txt",7);
  this->c2.setTextureTileSet();
  this->c3 = Couche("Background/mountains2.txt",7);
  this->c3.setTextureTileSet();
  this->c4 = Couche("Background/arbre1.txt",7);
  this->c4.setTextureTileSet();
  this->c5 = Couche("Background/arbre2.txt",7);
  this->c5.setTextureTileSet();
  this->c6 = Couche("Background/moon.txt",7);
  this->c6.setTextureTileSet();

  // Initialisation des menus
  this->mm = new MainMenu(this->b.getWitdhView(),this->b.getHeightView());
  this->mm->setTexture();
  this->pm = new PauseMenu(this->b.getWitdhView(),this->b.getHeightView());
  this->ui = Interface(this->b.getWitdhView(),this->b.getHeightView());

}

void Game::setTime()
{
  //Recupération du temps pour les différents événements
  this->b.setMovingTime(this->clock.getElapsedTime().asMilliseconds());
  this->p.setShootTime(this->clock.getElapsedTime().asMilliseconds());
  this->e.setShootTime(this->clock.getElapsedTime().asMilliseconds());
  this->pm->setTime(this->clock.getElapsedTime().asMilliseconds());
  this->mm->setTime(this->clock.getElapsedTime().asMilliseconds());
  this->clock.restart();
}

void Game::draw()
{
  // A METTRE DANS LA CLASSE BACKGROUND ------------
  c1.drawMap(window);
  c6.drawMap(window);
  c2.drawMap(window);
  c3.drawMap(window);
  c4.drawMap(window);
  c5.drawMap(window);
  // -----------------------------------------------

  for(int i=0;i<p.getSizeAtqs();i++)
  {
    p.drawAttaque(window,i);
  }
  for(int i=0;i<e.getSizeAtqs();i++)
  {
    e.drawAttaque(window,i);
  }

  window->draw(p.getSprite());
  window->draw(e.getSprite());

  // A mettre dans une classe-------------------------------------
   window->draw(text);
  //----------------------------------------------------------------

  // Probleme de segmentation ????
  /*
  for(int i=0;i<ui.size();i++)
  {
    window->draw(ui.getText(i));
  }
  */
}

int Game::checkMainMenu()
{
  mm->choix();
  if(mm->getMenuEtat()==1)
  {
    if(mm->getEnter()==3)
    {
      //Charge les données du jeux par défault

      //Liberer la mémoire

      exit(EXIT_SUCCESS);
    }

    // Affichage des éléments composant le menu
    window->clear();
    window->draw(mm->getSprite());
    for(int i=0;i<4;i++)
    {
      window->draw(mm->getText(i));
    }
    window->display();

    return 1; // Le menu est active
  }
  return 0; // Le menu n'est pas active
}

int Game::checkPauseMenu() // Probleme de view qui ne se deplace pas
{
  pm->choix();
  if(pm->getMenuEtat()==1)
  {
    if(pm->getEnter()==2)
    {
      mm->setTime(-1);
      mm->setMenuEtat(1);
    }
    if(pm->getEnter()==3)
    {
      //Charge les données du jeux par défault

      //Liberer la mémoire

      exit(EXIT_SUCCESS);
    }

    window->clear();
    for(int i=0;i<4;i++)
    {
      window->draw(pm->getText(i));
    }
    window->display();
    return 1; // Le menu est active
  }
  return 0; // Le menu n'est pas active
}

void Game::start()
{
  window->setVerticalSyncEnabled(false);
  window->setFramerateLimit(60);

  //Initialisation des variables
  this->initVariables();


  if(!this->font.loadFromFile("Font/VCR_OSD_MONO_1.001.ttf"))
  {
    cout<<"Impossible de charger la police d'écriture"<<endl;
  }
   text.setFont(font);

  while ( window->isOpen())
  {

    // A mettre dans une classe-------------------------------------
    sf::Time frameTime =  clock.getElapsedTime();
     text.setString("Fps: " + to_string(int(1/frameTime.asSeconds())));
     text.setScale(0.20,0.20);
    //----------------------------------------------------------------

    sf::Event event;
    while ( window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
         window->close();
      }
    }

    this->setTime();

    if(this->checkMainMenu()==1)
    {
      window->setView(window->getDefaultView());
    }
    else
    {
      if(this->checkPauseMenu()==0)
      {
        //Deplacement de la caméra

         b.movingView();


        // "Nettoye" la fenetre des anciens pixels présent
         window->clear();


        //Evenements
         p.deplacement(b);
         e.deplacement(b); // Supprimer e quand COLLISION ( sinon baisse constante de fps )
         p.stayInScreen(b);
         p.collision(e);

         p.attaque(b);
         e.attaque(b,p);
         p.collisionProjectile(e); // Cette fonction produit une baisse extreme de FPS quand il y a beaucoup de projectiles

         pm->setPosition(b.getView().getCenter().x-20,60);

         // A mettre dans une classe-------------------------------------
         text.setPosition(b.getView().getCenter().x-162,0);
        //----------------------------------------------------------------

         this->draw();
         }

      // Affichage des éléments
      window->setView(b.getView());
      window->display();
    }
  }
}
