#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player
{

private:
  // Attribut

  // Coordonées sur la carte 2D
  float x;
  float y;
  float oldX;
  float oldY;
  float* coinEnBasAGauche;
  float* coinEnHautADroite;
  float* coinEnBasADroite;
  float* coinEnHautAGauche;
  float* coinCentre;

  // Vie du personnage
  int pv;

  // Argent du personnage
  int money;

  // Joueur entrain d'attaquer ou non
  bool attack;

  // Joueur entrain de courir ou de marcher
  bool sprint;

  // Vitesse du joueur
  float speed;
  float speedSprint;

  // Rendu 2d du personnage
  sf::Texture texture;
  sf::Sprite sprite;

  // Orientation du personnage
  bool lookRight;
  bool lookLeft;
  bool lookTop;
  bool lookBot;

  //Animation personnage
  int frameDuration;

  //Gestion des collisions
  bool collisionTop;
  bool collisionBot;
  bool collisionRight;
  bool collisionLeft;


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
  bool getLookRight() const;
  bool getLookLeft() const;
  bool getLookTop() const;
  bool getLookBot() const;
  int getFrameDuration() const;
  float getCoinEnBasAGaucheX() const;
  float getCoinEnBasADroiteX() const;
  float getCoinEnHautAGaucheX() const;
  float getCoinEnHautADroiteX() const;
  float getCoinEnBasAGaucheY() const;
  float getCoinEnBasADroiteY() const;
  float getCoinEnHautAGaucheY() const;
  float getCoinEnHautADroiteY() const;
  float getCoinCentreX() const;
  float getCoinCentreY() const;
  bool getCollisionTop() const;
  bool getCollisionBot() const;
  bool getCollisionLeft() const;
  bool getCollisionRight() const;
  float getOldX() const;
  float getOldY() const;



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
  void setTexture(const std::string FILENAME); // Permet un rendu 2d du personnage ( texture + sprite )
  void movement(int COUNTERWALKING);
  void setAnimationPlayer(int ROW,int COUNTERWALKING);
  void setFrameDuration(int FRAMEDURATION);
  void setCollisionTop(bool VAL);
  void setCollisionBot(bool VAL);
  void setCollisionRight(bool VAL);
  void setCollisionLeft(bool VAL);
  void setOldX(float OLDX);
  void setOldY(float OLDY);
  void setCollisionPos(float OLDX,float OLDY);





};
#endif
