#include "header/Player.h"

// Methode constructive
Player::Player() : Vaisseau()
{

}

Player::Player(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed) : Vaisseau(x,y,texture,pv,atqSpeed,speed)
{

}

Player::Player(const std::string FILENAME,int NbLigneInTxt) : Vaisseau(FILENAME,NbLigneInTxt)
{
}

void Player::affiche()
{
  cout<<"\nVaisseau Joueur: "<<endl;
  Vaisseau::affiche();
}

void Player::deplacement()
{
  // Gère la gestion d'une manette ou d'un clavier
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 60.0)
  {
    sprite.move(speed,0);
    return;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -60.0)
  {
    sprite.move(-speed,0);
    return;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -60.0)
  {
    sprite.move(0,-speed);
    return;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 60.0)
  {
    sprite.move(0,speed);
    return;
  }
}
