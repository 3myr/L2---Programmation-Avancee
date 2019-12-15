/**
 * \file Game.cpp
 * \author Demazieres Remy
 * \date 15 decembre 2019
 *
 */
#include "header/Game.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instanciation d'un jeu
*/
Game::Game(RenderWindow* window) : timer(0)
{
  this->window = window;

  // Charge le son quand le joueur se fait toucher
  if (!buffer.loadFromFile("Sounds/explosion.wav"))
  {
    cout<<"Le sond n'a pas pu être chargé !"<<endl;
    exit(EXIT_FAILURE);
  }
  sound.setBuffer(buffer);
}

// ---------------------------------------------------------------------------






//Fonctions d'observations ---------------------------------------------------

/**
* \brief Gestion du Menu Principal
*/
int Game::checkMainMenu()
{
  // Probleme sous VM, le setTime() du menu principal prend une valeur érroné ( -2.1597e+09 )
  mm->choix();
  if(mm->getMenuEtat()==1)
  {
    switch (mm->getEnter())
    {
      case 0:
        this->refreshVariables();
        if(p->getLevel()>=1)
        {
          cm->unlockLevel();
        }
        cm->setMenuEtat(1);
        cm->setTime(-1);
        break;

      case 1:
        this->newGameVariables();
        cm->setMenuEtat(1);
        cm->setTime(-1);
        break;

      case 2:
      mm->setMenuEtat(0);
      exit(EXIT_SUCCESS);
        break;
    }

    // Affichage des éléments composant le menu
    window->clear();
    window->draw(mm->getSprite());
    mm->drawUi(window);
    for(int i=0;i<3;i++)
    {
      window->draw(mm->getText(i));
    }
    window->display();

    return 1; // Le menu est active
  }
  return 0; // Le menu n'est pas active
}

/**
* \brief Gestion du Menu Pause
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
* \brief Gestion du Menu de choix de level
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
        if(p->getLevel()>=1)
        {
          cm->setMenuEtat(0);
          // Faire rentrer dans le level 2
        }
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
* \brief Initialise les variables du jeu
*
*/
void Game::initVariables()
{

  //Initialisation des personnages et du Décor
  this->p = new Player("Character/playerDefault.txt",9); // Nombre de ligne
  this->p->setTexture(); // Chercher a enlever
  this->enemisPero = linkedListe<Enemi>();
  this->placementEnemi();
  this->b = Background("Background/view.txt",3);
  this->boss = new Boss("Character/boss.txt",6);
  this->boss->setTexture();
  this->bonus = linkedListe<Bonus>();
  this->placementBonus();


  // Initialisation des menus
  this->mm = new MainMenu(this->b.getWitdhView(),this->b.getHeightView());
  this->mm->setTexture();
  this->pm = new PauseMenu(this->b.getWitdhView(),this->b.getHeightView());
  this->cm = new ChoiceMenu(this->b.getWitdhView(),this->b.getHeightView());
  this->cm->setTexture();
  this->ui = new Interface(this->b.getWitdhView(),this->b.getHeightView());
}

/**
* \brief Recharge les données du jeux
*
*/
void Game::refreshVariables()
{
  //Charge les données des personnages et du Décor
  this->p = new Player("Character/player.txt",9); // Nombre de ligne
  this->p->setTexture(); // Chercher a enlever
  this->enemisPero = linkedListe<Enemi>();
  this->placementEnemi();
  this->b = Background("Background/view.txt",3);
  this->boss = new Boss("Character/boss.txt",6);
  this->boss->setTexture();
  this->ui->setScore(p->getScore());
  this->bonus = linkedListe<Bonus>();
  this->placementBonus();

}

/**
* \brief Recharge les données du jeux avec les valeurs par défauts
*
*/
void Game::newGameVariables()
{
  //Charge les données des personnages et du Décor
  this->p = new Player("Character/playerDefault.txt",9); // Nombre de ligne
  this->p->setTexture(); // Chercher a enlever
  this->enemisPero = linkedListe<Enemi>();
  this->placementEnemi();
  this->b = Background("Background/view.txt",3);
  this->boss = new Boss("Character/boss.txt",6);
  this->boss->setTexture();
  this->ui->setScore(p->getScore());
  this->cm->lockedAllLevel();
  this->bonus = linkedListe<Bonus>();
  this->placementBonus();

}


/**
* \brief Permet de mettre une clock pour les différentes classes
*
*/
void Game::setTime()
{
  //Recupération du temps pour les différents événements

  // Clock pour les menus
  this->mm->setTime(this->clock.getElapsedTime().asMilliseconds());
  this->cm->setTime(this->clock.getElapsedTime().asMilliseconds());
  this->pm->setTime(this->clock.getElapsedTime().asMilliseconds());

  //Clock pour le deplacement de la vue
  this->b.setMovingTime(this->clock.getElapsedTime().asMilliseconds());

  //Clock pour les vaisseaux
    // Joueur
  this->p->setShootTime(this->clock.getElapsedTime().asMilliseconds());
    // Enemis
  for(int i=0;i<enemisPero.size();i++)
  {
    this->enemisPero.get(i)->setShootTime(this->clock.getElapsedTime().asMilliseconds());
  }
    // Boss
  this->boss->setTime(this->clock.getElapsedTime().asMilliseconds());
  this->boss->setShootTime(this->clock.getElapsedTime().asMilliseconds());



  this->clock.restart();
}

/**
* \brief Fonctions affichant tout les éléments du jeu
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
  for(int i=0;i<p->getSizeAtqs();i++)
  {
    p->drawAttaque(window,i);
  }

  // Affiche les attaques du boss
  //cout<<boss->getSizeAtqs()<<endl;
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
  window->draw(p->getSprite());

  // Affiche le Boss
  window->draw(boss->getSprite());

  // Affiche les enemis
  for(int j=0;j<enemisPero.size();j++)
  {
    window->draw(enemisPero.get(j)->getSprite());
  }

  // Affiche les bonus
  for(int j=0;j<bonus.size();j++)
  {
    window->draw(bonus.get(j)->getSprite());
  }

  // Affiche les FPS
   ui->drawFPS(window);
   ui->drawScore(window);

  // Affiche le score
  for(int i=0;i<ui->size();i++)
  {
    window->draw(ui->getText(i));
  }

}

/**
* \brief Fonctions gerant les déplacement et tirs des différents vaisseau
*
*/
void Game::evenement()
{

  //Deplacement de la caméra
  b.movingView();

  // Verifie si le boss est vaincu ou non
  if(!boss->getEtat())
  {
    // Deplacement du joueur
    p->deplacement(b);

    // Attaque du joueur
    p->attaque(b);

    // ENEMI ---------------------------------------------------------------------------
    // Deplacement et attaques des enemis
    for(int i=0;i<enemisPero.size();i++)
    {
      // Condition qui verifie que les enemis sont dans la vue
      if(enemisPero.get(i)->getPosition() < b.getView().getCenter().x+b.getWitdhView()/2)
      {
        enemisPero.get(i)->deplacement(b);
        enemisPero.get(i)->attaque(b);

        // Quand le joueur se fait toucher
        if(enemisPero.get(i)->collisionProjectile(p))
        {
          // A CHANGER
          sound.play();
          while(timer<3000)
          {
            timer = this->clock.getElapsedTime().asMilliseconds();
          }
          this->refreshVariables();
          sound.stop();
          timer = 0;
        }

        // Collision entre le joueur et un enemi
        p->collision(enemisPero.get(i));

        // Quand un projectile atteint un vaiseeau Enemi / Boss
        if(p->collisionProjectile(enemisPero.get(i))==1)
        {
          p->setScore(10);
          enemisPero.supprimer(i);
        }
        if(enemisPero.get(i)->getPosition() < b.getView().getCenter().x-(b.getWitdhView()/1.5))
        {
          enemisPero.supprimer(i);
          p->setScore(-5);
        }
      }
    }
    // ------------------------------------------------------------------------------------

      // BOSS -------------------------------------------------------------------
      // Condition qui verifie que le boss est dans la vue
      if(boss->getPosition() < b.getView().getCenter().x+b.getWitdhView()/2)
      {
        // Collision entre le joueur du joueur et le boss
        p->collision(boss);

        // Deplacement du Boss
        boss->deplacement(b);

        // Attaque du Boss
        boss->attaque(b);

        // Collision entre un projectile du boss et le joueur
        if(boss->collisionProjectile(p))
        {
          p->setScore(-5);
          // A CHANGER
          sound.play();
          while(timer<3000)
          {
            timer = this->clock.getElapsedTime().asMilliseconds();
          }
          this->refreshVariables();
          sound.stop();
          timer = 0;
        }
      }
      //-------------------------------------------------------------------------


      // BONUS ------------------------------------------------------------------
      // Condition qui verifie que le bonus est dans la vue
      for(int j=0;j<bonus.size();j++)
      {
        if(bonus.get(j)->getPosition() < b.getView().getCenter().x+b.getWitdhView()/0.5)
        {
          bonus.get(j)->deplacement(b);
          if(p->collisionBonus(bonus.get(j)))
          {
            bonus.supprimer(j);
          }
          else
          {
            // Suppresions des bonus qui sortent de la vue
            if(bonus.get(j)->getPosition() < b.getView().getCenter().x-(b.getWitdhView()/1.5))
            {
              bonus.supprimer(j);
            }
          }
        }
      }
      //-------------------------------------------------------------------------


      if(p->collisionProjectile(boss))
      {
        if(boss->getPv()<=0)
        {
          p->setScore(75);
          boss->setEtat(1);
          cm->unlockLevel();
          p->setLevel(1); // Generaliser
        }
        else
        {
          boss->setPv(-1);
        }
      }



    // Permet de restreinte la zone de deplacement du joueur
    p->stayInScreen(b);
  }
  else
  {
    if(boss->dead(b))
    {
      cm->setMenuEtat(1);
      cm->setTime(-1);
      this->refreshVariables();
    }
    p->freeAtq(b);
    this->save();
  }

  // Gestion de l'interface et du menu de pause
  pm->setPosition(b.getView().getCenter().x-20,60);
  ui->setPosition(b.getView().getCenter().x+85,0);
  ui->setPositionFPS(b.getView().getCenter().x-162,0);
  ui->setScore(p->getScore());

}

/**
* \brief Permet de jouer au jeu
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
        //this->free();
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
}

/**
* \brief Permet de sauvegarder le jeu
*
*/
void Game::save()
{
  ofstream file;
  file.open("Character/player.txt");
  file << "x = "<< 20 <<";\n";
  file << "y = "<< 30 <<";\n";
  file << "pv = "<< p->getPv() << ";\n";
  file << "atqSpeed = "<< p->getAtqSpeed() << ";\n";
  file << "speed = "<< p->getSpeed() << ";\n";
  file << "score = "<<ui->getScore() << ";\n";
  file << "level = "<<p->getLevel() << ";\n";
  file << "bonus = "<<p->getBonus() << ";\n";
  file << "texture = \""<<p->getFilename()<<"\";\n"<<endl;;
  file.close();
}

/**
* \brief Permet de liberer la memoire du jeu
*
*/
void Game::free()
{

  p->free();
  p->freeAtq(b);
  cm->stopSound();
  mm->stopSound();
  pm->stopSound();


  for(int i=0;i<b.getCouches().size();i++)
  {
    b.getCouche(i)->free();
  }

  if(bonus.size()>0)
  {
    for(int i=0;i<bonus.size();i++)
    {
      delete bonus.get(i);
    }
  }


  delete boss;
  delete mm;
  delete cm;
  delete pm;
  delete ui;
  delete p;
  for(int i=0;i<enemisPero.size();i++)
  {
    if(enemisPero.size()>0)
    {
      delete enemisPero.get(i);
    }
  }
}

/**
* \brief Permet de placer les enemis sur la carte
*
*/
void Game::placementEnemi()
{
  Enemi* e = new Enemi("Character/enemi.txt",6);
  e->setPosition(628,80);
  e->setTexture();
  //enemisPero.ajouter(e);

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
  e6->setScale(0.2,0.2);
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



}

/**
* \brief Permet de placer les enemis sur la carte
*
*/
void Game::placementBonus()
{
  Bonus* b1 = new Bonus("Projectile/bonus1.txt",5);
  //b1->setPosition(628,80);
  b1->setTexture();
  this->bonus.ajouter(b1);

  Bonus* b2 = new Bonus("Projectile/bonus2.txt",5);
  //b2->setPosition(1000,80);
  b2->setTexture();
  this->bonus.ajouter(b2);

}


// ---------------------------------------------------------------------------
