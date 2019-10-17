#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace std;

class Camera
{

private:
  // Attribut
  sf::View mainView;

  int viewWidth;
  int viewHeight;

public:

  // Constructeurs
  Camera();
  // Fonctions d'observations
  sf::View getView() const;
  int getViewWidth() const;
  int getViewHeight() const;

  // Fonctions de transformations
  void setView(sf::View VIEW);
  void setViewWidth(int VIEWWIDTH);
  void setViewHeight(int VIEWHEIGHT);
  void movingView();

};
#endif
