#include "header/Game.h"

Game::Game(RenderWindow* window)
{
  this->window = window;
}

/**
* Initialise les variables du jeu
*
*/
void Game::initVariables()
{
  //Initialisation des personnages et du Décor
  this->p = Player("Character/player.txt",6); // Nombre de ligne
  this->p.setTexture(); // Chercher a enlever
  Enemi* e = new Enemi("Character/enemi.txt",6);
  e->setTexture(); // Chercher a enlever
  enemis.push_back((e));
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
  this->ui = new Interface(this->b.getWitdhView(),this->b.getHeightView());

}

/**
* Permet de mettre une clock pour les différentes classes
*
*/
void Game::setTime()
{
  //Recupération du temps pour les différents événements
  this->b.setMovingTime(this->clock.getElapsedTime().asMilliseconds());
  this->p.setShootTime(this->clock.getElapsedTime().asMilliseconds());
  for(int i=0;i<enemis.size();i++)
  {
    this->enemis[i]->setShootTime(this->clock.getElapsedTime().asMilliseconds());
  }
  this->pm->setTime(this->clock.getElapsedTime().asMilliseconds());
  this->mm->setTime(this->clock.getElapsedTime().asMilliseconds());
  this->clock.restart();
}

/**
* Fonctions affichant tout les éléments du jeu
*
*/
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
  for(int j=0;j<enemis.size();j++)
  {
    for(int i=0;i<enemis[j]->getSizeAtqs();i++)
    {
      enemis[j]->drawAttaque(window,i);
    }
  }

  window->draw(p.getSprite());
  for(int j=0;j<enemis.size();j++)
  {
    window->draw(enemis[j]->getSprite());
  }

   ui->drawFPS(window);

  for(int i=0;i<ui->size();i++)
  {
    window->draw(ui->getText(i));
  }
}

/**
* Gestion du Menu Principal
*
*/
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
    mm->drawUi(window);
    for(int i=0;i<4;i++)
    {
      window->draw(mm->getText(i));
    }
    window->display();

    return 1; // Le menu est active
  }
  return 0; // Le menu n'est pas active
}

/**
* Gestion du Menu Pause
*
*/
int Game::checkPauseMenu()
{
  pm->choix();
  if(pm->getMenuEtat()==1)
  {
    if(pm->getEnter()==1)
    {
      this->save();
    }
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

    mm->pauseSound();
    window->clear();
    for(int i=0;i<4;i++)
    {
      window->draw(pm->getText(i));
    }
    window->display();
    return 1; // Le menu est active
  }
  if(mm->isPlaying()!=1)
  {
    mm->playSound();
  }
  return 0; // Le menu n'est pas active
}

/**
* Permet de jouer au jeu
*
*/
void Game::start()
{
  window->setVerticalSyncEnabled(false);
  window->setFramerateLimit(60);

  //Initialisation des variables
  this->initVariables();


  while ( window->isOpen())
  {

    ui->setFrameTime(&clock);
    ui->setFPS();

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
      if(mm->isPlaying()!=1)
      {
        mm->playSound();
        mm->setPlaying();
      }
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
         for(int i=0;i<enemis.size();i++)
         {
           enemis[i]->deplacement(b); // Supprimer e quand COLLISION ( sinon baisse constante de fps )
         }

         p.stayInScreen(b);

         for(int i=0;i<enemis.size();i++)
         {
           p.collision(enemis[i]);
         }

         p.attaque(b);

         for(int i=0;i<enemis.size();i++)
         {
           enemis[i]->attaque(b,p);
           if(p.collisionProjectile(enemis[i])==1)
           {
             enemis.erase(enemis.begin()+i);
           } // Cette fonction produit une baisse extreme de FPS quand il y a beaucoup de projectiles
         }


         pm->setPosition(b.getView().getCenter().x-20,60);
         ui->setPosition(b.getView().getCenter().x+85,0);
         ui->setPositionFPS(b.getView().getCenter().x-162,0);

         this->draw();
         }

      // Affichage des éléments
      window->setView(b.getView());
      window->display();
    }
  }
}

void Game::save()
{
  ofstream file;
  file.open("Character/playerTestSave.txt");
  file << "x = "<< 20 <<";\n";
  file << "y = "<< 30 <<";\n";
  file << "pv = "<< p.getPv() << ";\n";
  file << "atqSpeed = "<< p.getAtqSpeed() << ";\n";

  file.close();
}
