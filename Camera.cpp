#include "header/Camera.h"

// Methode constructive
Camera::Camera()
{
  viewWidth = 238;
  viewHeight = 160;
  mainView.setSize(viewWidth,viewHeight);
  mainView.setCenter(viewWidth/2,viewHeight/2);
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

void Camera::movingView()
{
  mainView.move(0.3,0);
  //cout<<"x: " << mainView.getCenter().x<<endl;


}
