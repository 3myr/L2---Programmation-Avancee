#include "header/Game.h"

// Methode constructive -----------------------------------------------------

Game::Game(RenderWindow* window)
{
  this->window = window;
}

// ---------------------------------------------------------------------------






//Fonctions d'observations ---------------------------------------------------

/**
* Gestion du Menu Principal
*
*/
int Game::checkMainMenu()
{
  mm->choix();
  if(mm->getMenuEtat()==1)
  {
    switch (mm->getEnter())
    {
      case 1:
        cm->setMenuEtat(1);
        cm->setTime(-1);
        break;

      case 2:
        cm->setMenuEtat(1);
        cm->setTime(-1);
        break;

      case 3:
        mm->setMenuEtat(0);
        exit(EXIT_SUCCESS);
        break;
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
    switch (pm->getEnter())
    {
      case 0:
        pm->setMenuEtat(0);
        break;

      case 1:
        this->save();
        break;

      case 2:
        pm->setMenuEtat(0);
        mm->setTime(-1);
        mm->setMenuEtat(1);
        break;

      case 3:
        pm->setMenuEtat(0);
        window->close();
        break;
    }

    // Affichage du menu
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
* Gestion du Menu de choix de level
*
*/
int Game::checkChoiceMenu()
{
  cm->choix();
  if(cm->getMenuEtat()==1)
  {
    switch (cm->getEnter())
    {
      case 0:
        cm->setMenuEtat(0);
        // Faire rentrer dans le level 1
        break;

      case 1:
        cm->setMenuEtat(0);
        // Faire rentrer dans le level 2
        break;

      case 2:

        break;

      case 3:

        break;

      case 4:

        break;

    }

    // Affichage des éléments composant le menu
    window->clear();
    window->draw(cm->getSprite());
    cm->drawUi(window);
    window->draw(cm->getText(0));
    window->display();

    return 1; // Le menu est active
  }
  return 0; // Le menu n'est pas active
}

// ---------------------------------------------------------------------------






//Fonctions de transmorfations -----------------------------------------------

/**
* Initialise les variables du jeu
*
*/
void Game::initVariables()
{

  //Initialisation des personnages et du Décor
  this->p = Player("Character/player.txt",6); // Nombre de ligne
  this->p.setTexture(); // Chercher a enlever
  this->enemisPero = linkedListe<Enemi>();
  this->placementEnemi();
  this->b = Background("Background/view.txt",3);
  this->boss = new Boss("Character/boss.txt",6);
  this->boss->setTexture();


  // Initialisation des menus
  this->mm = new MainMenu(this->b.getWitdhView(),this->b.getHeightView());
  this->mm->setTexture();
  this->pm = new PauseMenu(this->b.getWitdhView(),this->b.getHeightView());
  this->cm = new ChoiceMenu(this->b.getWitdhView(),this->b.getHeightView());
  this->cm->setTexture();
  this->ui = new Interface(this->b.getWitdhView(),this->b.getHeightView());

}

/**
* Permet de mettre une clock pour les différentes classes
*
*/
void Game::setTime()
{
  //Recupération du temps pour les différents événements

  //Clock pour le deplacement de la vue
  this->b.setMovingTime(this->clock.getElapsedTime().asMilliseconds());

  //Clock pour les vaisseaux
    // Joueur
  this->p.setShootTime(this->clock.getElapsedTime().asMilliseconds());
    // Enemis
  for(int i=0;i<enemisPero.size();i++)
  {
    this->enemisPero.get(i)->setShootTime(this->clock.getElapsedTime().asMilliseconds());
  }
    // Boss
  this->boss->setTime(this->clock.getElapsedTime().asMilliseconds());

  // Clock pour les menus
  this->cm->setTime(this->clock.getElapsedTime().asMilliseconds());
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
  // Affiche les couches qui composent la map
  for(int i=0;i<b.getCouches().size();i++)
  {
    b.getCouche(i)->drawMap(window);
  }

  // Affiche les attaques du joueur
  for(int i=0;i<p.getSizeAtqs();i++)
  {
    p.drawAttaque(window,i);
  }

  // Affiche les attaques du boss
  for(int i=0;i<boss->getSizeAtqs();i++)
  {
    boss->drawAttaque(window,i);
  }

  // Affiche les attaques des enemis
  for(int j=0;j<enemisPero.size();j++)
  {
    for(int i=0;i<enemisPero.get(j)->getSizeAtqs();i++)
    {
      enemisPero.get(j)->drawAttaque(window,i);
    }
  }


  // Affiche le joueur
  window->draw(p.getSprite());

  // Affiche le Boss
  window->draw(boss->getSprite());

  // Affiche les enemis
  for(int j=0;j<enemisPero.size();j++)
  {
    window->draw(enemisPero.get(j)->getSprite());
  }


  // Affiche les FPS
   ui->drawFPS(window);

  // Affiche le score
  for(int i=0;i<ui->size();i++)
  {
    window->draw(ui->getText(i));
  }

}

/**
* Fonctions gerant les déplacement et tirs des différents vaisseau
*
*/
void Game::evenement()
{
  //Deplacement de la caméra
  b.movingView();

  // Deplacement du joueur
  p.deplacement(b);

  // Attaque du joueur
  p.attaque(b);


  // Deplacement et attaques des enemis
  for(int i=0;i<enemisPero.size();i++)
  {
    if(enemisPero.get(i)->getPosition() < b.getView().getCenter().x+b.getWitdhView()/2)
    {
      enemisPero.get(i)->deplacement(b); // Supprimer e quand COLLISION ( sinon baisse constante de fps )
      enemisPero.get(i)->attaque(b,p);
    }
    // Peut etre a modifier
    if(p.collisionProjectile(enemisPero.get(i))==1 || enemisPero.get(i)->getPosition() < b.getView().getCenter().x-(b.getWitdhView()/1.5))
    {
      delete enemisPero.get(i);
      enemisPero.supprimer(i);
    }
    p.collision(enemisPero.get(i));
  }



  // Permet de restreinte la zone de deplacement du joueur
  p.stayInScreen(b);

  /*
  // Gestion des collisions entre le joueur et les enemis
  for(int i=0;i<enemisPero.size();i++)
  {
    p.collision(enemisPero.get(i));
  }
  */

  /*
  // Gestion des projectiles enemis et des enemis
  for(int i=0;i<enemisPero.size();i++)
  {
    if(p.collisionProjectile(enemisPero.get(i))==1 || enemisPero.get(i)->getPosition() < b.getView().getCenter().x-(b.getWitdhView()/1.5))
    {
      delete enemisPero.get(i);
      enemisPero.supprimer(i);
    }
  }
  */

  // Attaque du Boss
  boss->attaque(b);

  // Gestion de l'interface et du menu de pause
  pm->setPosition(b.getView().getCenter().x-20,60);
  ui->setPosition(b.getView().getCenter().x+85,0);
  ui->setPositionFPS(b.getView().getCenter().x-162,0);

}

/**
* Permet de jouer au jeu
*
*/
void Game::start()
{
  // Reglage de la fenetre de jeux
  window->setVerticalSyncEnabled(false);
  window->setFramerateLimit(60);


  //Initialisation des variables
  this->initVariables();


  while ( window->isOpen())
  {
    // Determination des FPS
    ui->setFrameTime(&clock);
    ui->setFPS();

    sf::Event event;
    while ( window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        this->free();
        window->close();
      }
    }

    // Fixe une clock pour chaque entité du jeu
    this->setTime();

    // Verification si le Menu principal est ouvert
    if(this->checkMainMenu()==1)
    {
      // Joue la musique
      if(mm->isPlaying()!=1)
      {
        mm->playSound();
        mm->setPlaying();
      }
      // Change la vue quand on est dans le menu principal
      window->setView(window->getDefaultView());
    }
    else // Cas dans lequel on n'est plus dans le menu principal
    {
      // Cas dans lequel le menu de choix de level est ouvert
      if(this->checkChoiceMenu()==1)
      {
        window->setView(window->getDefaultView());
      }
      else // Cas dans lequel on a quitter le menu de choix de level
      {
        // Cas dans lequel le menu de pause est ouvert
        if(this->checkPauseMenu()==0)
        {

          //"Nettoye" la fenetre des anciens pixels présent
           window->clear();


          //Evenements
           this->evenement();

           //Affiche les éléments
           this->draw();
        }
        window->setView(b.getView());
      }


      // Affichage des éléments
      window->display();
    }
  }
  // Libere la mémoire des attaques de enemis
  this->free();
}

/**
* Permet de sauvegarder le jeu
*
*/
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


void Game::free()
{

  p.free();
  mm->stopSound();
  pm->stopSound();
  enemisPero.free();
}


void Game::placementEnemi()
{
  Enemi* e = new Enemi("Character/enemi.txt",6);
  e->setPosition(628,80);
  e->setTexture();
  enemisPero.ajouter(e);

  Enemi* e1 = new Enemi(628,120,e->getTexture(),e->getPv(),e->getAtqSpeed(),e->getSpeed());
  e1->setScale(0.2,0.2);
  e1->setTexture();
  enemisPero.ajouter(e1);


  Enemi* e2 = new Enemi(503,50,e->getTexture(),e->getPv(),e->getAtqSpeed(),e->getSpeed());
  e2->setScale(0.2,0.2);
  e2->setTexture();
  enemisPero.ajouter(e2);


  Enemi* e3 = new Enemi(400,70,e->getTexture(),e->getPv(),e->getAtqSpeed(),e->getSpeed());
  e3->setScale(0.2,0.2);
  e3->setTexture();
  enemisPero.ajouter(e3);


  Enemi* e4 = new Enemi(500,80,e->getTexture(),e->getPv(),e->getAtqSpeed(),e->getSpeed());
  e4->setScale(0.2,0.2);
  e4->setTexture();
  enemisPero.ajouter(e4);


  Enemi* e5 = new Enemi(900,70,e->getTexture(),e->getPv(),e->getAtqSpeed(),e->getSpeed());
  e5->setScale(0.2,0.2);
  e5->setTexture();
  enemisPero.ajouter(e5);


  Enemi* e6 = new Enemi("Character/enemi2.txt",6);
  e6->setPosition(800,30);
  e6->setTexture();
  enemisPero.ajouter(e6);


  Enemi* e7 = new Enemi(850,120,e6->getTexture(),e6->getPv(),e6->getAtqSpeed(),e6->getSpeed());
  e7->setScale(0.2,0.2);
  e7->setTexture();
  enemisPero.ajouter(e7);


  Enemi* e8 = new Enemi(278,50,e6->getTexture(),e6->getPv(),e6->getAtqSpeed(),e6->getSpeed());
  e8->setScale(0.2,0.2);
  e8->setTexture();
  enemisPero.ajouter(e8);


  Enemi* e9 = new Enemi(904,30,e6->getTexture(),e6->getPv(),e6->getAtqSpeed(),e6->getSpeed());
  e9->setScale(0.2,0.2);
  e9->setTexture();
  enemisPero.ajouter(e9);


  Enemi* e10 = new Enemi(904,60,e6->getTexture(),e6->getPv(),e6->getAtqSpeed(),e6->getSpeed());
  e10->setScale(0.2,0.2);
  e10->setTexture();
  enemisPero.ajouter(e10);


  Enemi* e11 = new Enemi(1020,30,e6->getTexture(),e6->getPv(),e6->getAtqSpeed(),e6->getSpeed());
  e11->setScale(0.2,0.2);
  e11->setTexture();
  enemisPero.ajouter(e11);



}

// ---------------------------------------------------------------------------
