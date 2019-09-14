#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player
{

private:
  // Coordonées sur la carte 2D
  float x;
  float y;

  // Vie du personnage
  int pv;

  // Argent du personnage
  int money;

  // Joueur entrain d'attaquer ou non
  bool attack;

  // Joueur entrain de courir ou de marcher
  bool sprint;

  // Vitesse du joueur
  float speed = 1.0f;
  float speedSprint = 0.2f;

  // Rendu 2d du personnage
  sf::Texture texture;
  sf::Sprite sprite;

  // Animation du personnage
  int frameDuration = 100;

  // Orientation du personnage
  bool lookRight;
  bool lookLeft;
  bool lookTop;
  bool lookBot;

public:

  // Constructeurs
  Player();

  // Fonctions d'observations
  float getX() const;
  float getY() const;
  int getPv() const;
  int getMoney() const;
  bool getAttack() const;
  bool getSprint() const;
  float getSpeed() const;
  float getSpeedSprint() const;
  sf::Texture getTexture() const;
  sf::Sprite getSprite() const;
  int getFrameDuration() const;
  bool getLookRight() const;
  bool getLookLeft() const;
  bool getLookTop() const;
  bool getLookBot() const;

  // Fonctions de transformations
  void setX(float X);
  void setY(float Y);
  void setPv(int PV);
  void setMoney(int MONEY);
  void setAttack(bool ATTACK);
  void setSprint(bool SPRINT);
  void setSpeed(float SPEED);
  void setSpeedSprint(float SPEEDSPRINT);
  void setLookRight(bool LOOK);
  void setLookLeft(bool LOOK);
  void setLookTop(bool LOOK);
  void setLookBot(bool LOOK);
  void setTexture(const std::string FILENAME,int* COUNTERWALKING); // Permet un rendu 2d du personnage ( texture + sprite )
  void setAnimation(int ROW,int COUNTERWALKING);
  void setFrameDuration(int FRAMEDURATION);
  void movement(int* COUNTERWALKING);


};
#endif
