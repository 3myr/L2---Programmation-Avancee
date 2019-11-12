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

void Player::deplacement(Background b)
{
  // Gère la gestion d'une manette ou d'un clavier
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 60.0)
  {
    if(this->sprite.getPosition().x+this->sprite.getScale().x*this->texture.getSize().x > b.getView().getCenter().x+b.getWitdhView()/2)
    {
    }
    else
    {
      sprite.move(speed,0);
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -60.0)
  {
    if(this->sprite.getPosition().x < b.getView().getCenter().x-b.getWitdhView()/2)
    {
    }
    else
    {
      sprite.move(-speed,0);
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -60.0)
  {
    if(this->sprite.getPosition().y < b.getView().getCenter().y-b.getHeightView()/2)
    {
    }
    else
    {
      sprite.move(0,-speed);
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 60.0)
  {
    if(this->sprite.getPosition().y+this->sprite.getScale().y*this->texture.getSize().y > b.getView().getCenter().y+b.getHeightView()/2)
    {
    }
    else
    {
      sprite.move(0,speed);
    }
  }
}
