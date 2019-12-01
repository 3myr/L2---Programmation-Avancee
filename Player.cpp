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

// Fonctions d'observations

void Player::affiche()
{
  cout<<"\nVaisseau Joueur: "<<endl;
  Vaisseau::affiche();
}

Attaque* Player::getAttque(int i)
{
  return atqs[i];
}


// Fonctions de transformations

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

void Player::attaque(Background b)
{
  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Joystick::isButtonPressed(0, 0) )&& this->getShootTime() >= this->getAtqSpeed())
  {
    Attaque* atq = new Atq2("Projectile/Projectile2.png");

    //Defini les différentes variables ( a remplacer par des variables )
    float posX = this->getSprite().getPosition().x;
    float posY = this->getSprite().getPosition().y;
    float scaleX = this->getSprite().getScale().x;
    float scaleY = this->getSprite().getScale().y;
    float widthSprite = this->getTexture().getSize().x;


    atq->addProj(posX, posY, scaleX, scaleY, widthSprite);

    atqs.push_back(atq);
    this->setShootTime(-1);
  }
  for(int i=0;i<atqs.size();i++)
  {
    atqs[i]->moveP(b.getView().getCenter().x+b.getWitdhView());
    if(atqs[i]->getSizeProj()<1)
    {
      atqs.erase(atqs.begin()+i);
    }
  }
}

int Player::collisionProjectile(Vaisseau* e)
{
  // Pour optimiser la recherche de collisions, on regarde la distance entre le premier projectile tiré et la distance entre celui-ci et le vaisseau enemi ainsi que la distance entre un vaisseau enemi et le player
  if(atqs.size()>0)
  {
    if(atqs[0]->getProjectile(0).getPosition() - e->getSprite().getPosition().x < 50 || this->getSprite().getPosition().x - e->getSprite().getPosition().x < 20)
    {
      for(int i=0;i<atqs.size();i++)
      {
        for(int j=0;j<atqs[i]->getSizeProj();j++)
        {
          if(e->collision(atqs[i]->getProjectile(j))==1)
          {
            atqs[i]->erase(j);
            //e->erase();
            return 1; // efface vaisseau
          }
        }
      }
    }
  }
  return 0;
}
