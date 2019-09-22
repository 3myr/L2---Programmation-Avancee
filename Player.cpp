#include "header/Player.h"

// Methode constructive
Player::Player()
{
  x = this->getX();
  y = this->getY();
  speed = 3.0;
  speedSprint = 6.0;
  frameDuration = 100;

  // Alloue et initilialise un tableau 1D de 2 cases contenant les coordonnées X et Y des points
  coinEnBasAGauche = (float*)malloc(2.0 * sizeof(float));
  coinEnHautADroite = (float*)malloc(2.0 * sizeof(float));
  coinEnBasADroite = (float*)malloc(2.0 * sizeof(float));
  coinEnHautAGauche = (float*)malloc(2.0 * sizeof(float));
  coinCentre = (float*)malloc(2.0 * sizeof(float));

  coinEnBasAGauche[0] = this->getX();
  coinEnHautADroite[0] =this->getX()+26;
  coinEnBasADroite[0] =this->getX()+26;
  coinEnHautAGauche[0] =this->getX();
  coinCentre[0] = this->getX()+13;

  coinEnBasAGauche[1] =this->getY()+44;
  coinEnHautADroite[1] =this->getY();
  coinEnBasADroite[1] =this->getY();
  coinEnHautAGauche[1] =this->getY()+44;
  coinCentre[1] = this->getY()+22;

  collisionTop = false;
  collisionBot = false;
  collisionLeft = false;
  collisionRight = false;

  sprite.setPosition(200,100);

}

// Fonctions d'observations

// Fonctions d'observations
float Player::getX() const
{
  return sprite.getPosition().x;
}

float Player::getY() const
{
  return sprite.getPosition().y;
}

int Player::getPv() const
{
  return pv;
}
int Player::getMoney() const
{
  return money;
}

bool Player::getAttack() const
{
  return attack;
}

bool Player::getSprint() const
{
  return sprint;
}

float Player::getSpeed() const
{
  return speed;
}

float Player::getSpeedSprint() const
{
  return speedSprint;
}

sf::Texture Player::getTexture() const
{
 return texture;
}

sf::Sprite Player::getSprite() const
{
  return sprite;
}

bool Player::getLookRight() const
{
  return lookRight;
}

bool Player::getLookLeft() const
{
  return lookLeft;
}

bool Player::getLookTop() const
{
  return lookTop;
}

bool Player::getLookBot() const
{
  return lookBot;
}

int Player::getFrameDuration() const
{
  return frameDuration;
}

float Player::getCoinEnBasAGaucheX() const
{
  return this->getX();
}

float Player::getCoinEnBasADroiteX() const
{
  return this->getX()+21.5;
}

float Player::getCoinEnHautAGaucheX() const
{
  return this->getX();
}

float Player::getCoinEnHautADroiteX() const
{
  return this->getX()+21.5;
}

float Player::getCoinEnBasAGaucheY() const
{
  return this->getY()+44;
}

float Player::getCoinEnBasADroiteY() const
{
  return this->getY()+44;
}

float Player::getCoinEnHautAGaucheY() const
{
  return this->getY()+23;
}

float Player::getCoinEnHautADroiteY() const
{
  return this->getY()+23;
}

float Player::getCoinCentreX() const
{
  return this->getX()+13;
}

float Player::getCoinCentreY() const
{
  return this->getX()+22;
}

bool Player::getCollisionTop() const
{
  return collisionTop;
}
bool Player::getCollisionBot() const
{
  return collisionBot;
}
bool Player::getCollisionLeft() const
{
  return collisionRight;
}
bool Player::getCollisionRight() const
{
  return collisionLeft;
}

float Player::getOldX() const
{
  return oldX;
}
float Player::getOldY() const
{
  return oldY;
}




// Fonctions de transformations
void Player::setX(float X)
{
  x = X;
}

void Player::setY(float Y)
{
 y = Y;
}

void Player::setPv(int PV)
{
 pv = PV;
}

void Player::setMoney(int MONEY)
{
  money = MONEY;
}

void Player::setAttack(bool ATTACK)
{
  attack = ATTACK;
}

void Player::setSprint(bool SPRINT)
{
  sprint = SPRINT;
}

void Player::setSpeed(float SPEED)
{
  speed = SPEED;
}

void Player::setSpeedSprint(float SPEEDSPRINT)
{
 speedSprint = SPEEDSPRINT;
}

void Player::setLookRight(bool LOOK)
{
  lookRight = LOOK;
}

void Player::setLookLeft(bool LOOK)
{
  lookLeft = LOOK;
}

void Player::setLookTop(bool LOOK)
{
  lookTop = LOOK;
}

void Player::setLookBot(bool LOOK)
{
  lookBot = LOOK;
}

void Player::setTexture(const std::string FILENAME)
{
  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
}

void Player::movement(int COUNTERWALKING)
{
  // Gère la gestion d'une manette ou d'un clavier
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 60.0)
  {
    frameDuration = 100;
    this->setOldX(this->getX());
    this->setOldY(this->getY());
    sprite.move(speed,0);
    lookRight = 1;
    lookLeft = 0;
    lookTop = 0;
    lookBot = 0;
    this->setAnimationPlayer(3, COUNTERWALKING);
    return;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -60.0)
  {
    frameDuration = 100;
    this->setOldX(this->getX());
    this->setOldY(this->getY());
    sprite.move(-speed,0);
    lookRight = 0;
    lookLeft = 1;
    lookTop = 0;
    lookBot = 0;
    this->setAnimationPlayer(2, COUNTERWALKING);
    return;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -60.0)
  {
    frameDuration = 100;
    this->setOldX(this->getX());
    this->setOldY(this->getY());
    sprite.move(0,-speed);
    lookRight = 0;
    lookLeft = 0;
    lookTop = 1;
    lookBot = 0;
    this->setAnimationPlayer(1, COUNTERWALKING);
    return;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 60.0)
  {
    frameDuration = 100;
    this->setOldX(this->getX());
    this->setOldY(this->getY());
    sprite.move(0,speed);
    lookRight = 0;
    lookLeft = 0;
    lookTop = 0;
    lookBot = 1;
    this->setAnimationPlayer(0, COUNTERWALKING);
    return;
  }
  frameDuration = 300;
  this->setAnimationPlayer(4, COUNTERWALKING);

}

void Player::setAnimationPlayer(int ROW,int COUNTERWALKING)
{
  //REMPLACER LES VALEURS NUMERIQUE
  switch (ROW)
  {
    case 0:
    sprite.setTextureRect(sf::IntRect(COUNTERWALKING*26,  0 , 26, 42));
    break;

    case 1:
    sprite.setTextureRect(sf::IntRect(COUNTERWALKING*24,  42 , 24, 44));
    break;

    case 2:
    sprite.setTextureRect(sf::IntRect(COUNTERWALKING*29,  86 , 29, 44));
    break;

    case 3:
    sprite.setTextureRect(sf::IntRect(COUNTERWALKING*29,  130 , 29, 44));
    break;

    case 4:
    sprite.setTextureRect(sf::IntRect(COUNTERWALKING*23, 174 , 23, 41));
    break;

    case 5:
    sprite.setTextureRect(sf::IntRect(COUNTERWALKING*29, ROW * 105 , 95, 103));
    break;

    case 6:
    sprite.setTextureRect(sf::IntRect(COUNTERWALKING*29, ROW * 105 , 95, 103));
    break;

    default:
    sprite.setTextureRect(sf::IntRect(COUNTERWALKING*29, 0, 95, 103));
  }
}

void Player::setFrameDuration(int FRAMEDURATION)
{
  frameDuration = FRAMEDURATION;
}

void Player::setCollisionTop(bool VAL)
{
  collisionTop = VAL;
}

void Player::setCollisionBot(bool VAL)
{
  collisionBot = VAL;
}

void Player::setCollisionRight(bool VAL)
{
  collisionRight = VAL;
}

void Player::setCollisionLeft(bool VAL)
{
  collisionLeft = VAL;
}

void Player::setOldX(float OLDX)
{
  oldX = OLDX;
}
void Player::setOldY(float OLDY)
{
  oldY = OLDY;
}

void Player::setCollisionPos(float OLDX, float OLDY)
{
  sprite.setPosition(OLDX,OLDY);
}
