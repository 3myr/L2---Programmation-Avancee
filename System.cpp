#include "System.h"

// Methode constructive
System::System()
{
}

// Fonctions d'obversations
sf::View System::getView() const
{
  return mainView;
}

int System::getSizeX() const
{
  return sizeX;
}

int System::getSizeY() const
{
    return sizeY;
}



// Fonctions de transformations
void System::setView(sf::View VIEW)
{
  mainView = VIEW;
}

void System::centerPlayer(Player PLAYER)
{

  // REMPLACER LES VALEURS NUMERIQUE PAR DES VARIABLES
  if(PLAYER.getX()<155 && PLAYER.getY()<120)
  {
    mainView.setCenter(155,120);
    return;
  }

  if(PLAYER.getX()<155 && PLAYER.getY()>840)
  {
    mainView.setCenter(155,840);
  }

  if(PLAYER.getY()<120 && PLAYER.getX()>1093)
  {
    mainView.setCenter(1093,120);
    return;
  }

  if(PLAYER.getX()>1093 && PLAYER.getY()>840)
  {
    mainView.setCenter(1093,840);
    return;
  }

  if(PLAYER.getX()>155 && PLAYER.getY()<120)
  {
    mainView.setCenter(PLAYER.getX(),120);
    return;
  }

  if(PLAYER.getX()<155 && PLAYER.getY()<840)
  {
    mainView.setCenter(155,PLAYER.getY());
    return;
  }

  if(PLAYER.getX()>155 && PLAYER.getY()>840)
  {
    mainView.setCenter(PLAYER.getX(),840);
    return;
  }

  if(PLAYER.getX()>1093 && PLAYER.getY()>120)
  {
    mainView.setCenter(1093,PLAYER.getY());
    return;
  }

  if(PLAYER.getX()>155 && PLAYER.getY()>120 && PLAYER.getX()<1093 && PLAYER.getY()<840)
  {
    mainView.setCenter(PLAYER.getSprite().getPosition());
  }
}

void System::setSizeX(int SIZEX)
{
  sizeX = SIZEX;
}

void System::setSizeY(int SIZEY)
{
  sizeY = SIZEY;
}

void System::initialisate()
{
  mainView.setSize(sizeX,sizeY);
}

void animationCounter(Player JOUEUR, int COUNTERWALKING, int ANIMATIONCOUNTER)
{
  if (ANIMATIONCOUNTER >= JOUEUR.getFrameDuration()) // Comparaison pour savoir si l'on passe au sprite suivant de l'animation
  {
    ANIMATIONCOUNTER =0;
    COUNTERWALKING++;
    if (COUNTERWALKING == 6) // Permet de choisir le bon sprite pour que l'animation soit fluide et cohérente
    {
      COUNTERWALKING = 0;
    }
  }
}
