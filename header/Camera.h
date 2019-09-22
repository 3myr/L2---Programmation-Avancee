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

  int viewWidth; //310
  int viewHeight; //240

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
  void setViewCenterPlayer(Player PLAYER);

};
#endif
