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

void Enemi::affiche()
{
  cout<<"\nVaisseau enemi: "<<endl;
  Vaisseau::affiche();

}

void Enemi::deplacement()
{
  sprite.move(-speed,0);
}

void Enemi::attaque()
{
  if (this->getShootTime() >= atqSpeed)
    {
      // On lance une attaque ( qui lance des projectiles )

      this->setShootTime(-1);
    }
}
