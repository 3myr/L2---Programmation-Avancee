#include "header/Manage.h"

// Methode constructive

Manage::Manage()
{

}

// Fonctions d'observations


// Fonctions de transformations
int Manage::mainMenu(sf::RenderWindow* window, MainMenu* m)
{
  if(m->getMenuEtat()==1)
  {
    m->choix();
    if(m->getEnter()==3)
    {
      //Charge les données du jeux par défault
      //Liberer la mémoire
      exit(EXIT_SUCCESS);
    }
    window->clear();
    window->draw(m->getSprite());
    for(int i=0;i<4;i++)
    {
      window->draw(m->getText(i));
    }
    window->display();
    return 1; // Le menu est active
  }
  return 0; // Le menu n'est pas active
}

int Manage::pauseMenu(sf::RenderWindow* window, PauseMenu* m, MainMenu* mm)
{
  m->choix();
  if(m->getMenuEtat()==1)
  {
    m->choix();
    if(m->getEnter()==2)
    {
      mm->setTime(-1);
      mm->setMenuEtat(1);
    }

    m->choix(); // Probleme le jeux ne se quitte plus dans le menu pause
    if(m->getEnter()==3)
    {
      //Charge les données du jeux par défault
      //Liberer la mémoire
      exit(EXIT_SUCCESS);
    }

    window->clear();
    for(int i=0;i<4;i++)
    {
      window->draw(m->getText(i));
    }
    window->display();
    return 1; // Le menu est active
  }
  return 0; // Le menu n'est pas active
}
