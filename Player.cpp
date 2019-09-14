#include "Player.h"

// Methode constructive
Player::Player()
{
}

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

int Player::getFrameDuration() const
{
  return frameDuration;
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

void Player::setTexture(const std::string FILENAME,int* COUNTERWALKING)
{
  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
  //sprite.setScale(0.3f,0.3f);
  setAnimation(4, *COUNTERWALKING);
}

void Player::setAnimation(int ROW,int COUNTERWALKING)
{
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

void Player::movement(int* COUNTERWALKING)
{
  // Gère la gestion d'une manette ou d'un clavier
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 60.0)
  {
    frameDuration = 100;
    sprite.move(speed,0);
    lookRight = 1;
    lookLeft = 0;
    lookTop = 0;
    lookBot = 0;
    setAnimation(3, *COUNTERWALKING);
    return;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -60.0)
  {
    frameDuration = 100;
    sprite.move(-speed,0);
    lookRight = 0;
    lookLeft = 1;
    lookTop = 0;
    lookBot = 0;
    setAnimation(2, *COUNTERWALKING);
    return;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -60.0)
  {
    frameDuration = 100;
    sprite.move(0,-speed);
    lookRight = 0;
    lookLeft = 0;
    lookTop = 1;
    lookBot = 0;
    setAnimation(1, *COUNTERWALKING);
    return;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 60.0)
  {
    frameDuration = 100;
    sprite.move(0,speed);
    lookRight = 0;
    lookLeft = 0;
    lookTop = 0;
    lookBot = 1;
    setAnimation(0, *COUNTERWALKING);
    return;
  }
  frameDuration = 300;
  setAnimation(4, *COUNTERWALKING);

}
