#include "header/Camera.h"

// Methode constructive
Camera::Camera()
{
  viewWidth = 310;
  viewHeight = 240;
  mainView.setSize(viewWidth,viewHeight);
}

// Fonctions d'observations
sf::View Camera::getView() const
{
  return mainView;
}

int Camera::getViewWidth() const
{
  return viewWidth;
}

int Camera::getViewHeight() const
{
    return viewHeight;
}

// Fonctions de transformations
void Camera::setView(sf::View VIEW)
{
  mainView = VIEW;
}

void Camera::setViewWidth(int VIEWWIDTH)
{
  viewWidth = VIEWWIDTH;
}

void Camera::setViewHeight(int VIEWHEIGHT)
{
  viewHeight = VIEWHEIGHT;
}

void Camera::setViewCenterPlayer(Player PLAYER)
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
