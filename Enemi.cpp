#include "header/Enemi.h"

// Methode constructive
Enemi::Enemi() : Vaisseau()
{

}

Enemi::Enemi(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed) : Vaisseau(x,y,texture,pv,atqSpeed,speed)
{

}

Enemi::Enemi(const std::string FILENAME,int NbLigneInTxt) : Vaisseau(FILENAME,NbLigneInTxt)
{

}

//Fonctions d'observations
void Enemi::affiche()
{
  cout<<"\nVaisseau enemi: "<<endl;
  Vaisseau::affiche();

}

//Fonctions de transformations
void Enemi::setTexture()
{
  sprite.setTexture(texture);
  sprite.setPosition(x,y);
  atq = (Atq2*)new Atq2[1];
  atq->setTextureProj("Projectile/Projectile2.png"); // A changer si texture de projectile différentes
}

void Enemi::deplacement()
{
  sprite.move(-speed,0);
}

void Enemi::attaque(Background b)
{
  if ( this->getShootTime() >= this->getAtqSpeed())
    {
      atq->setPosition(this->getSprite().getPosition().x+this->getTexture().getSize().x * this->getSprite().getScale().x,this->getSprite().getPosition().y+15*this->getSprite().getScale().y);
      atq->push_back();
      this->setShootTime(-1);
    }
    atq->moveE(b.getView().getCenter().x+b.getWitdhView());

}
