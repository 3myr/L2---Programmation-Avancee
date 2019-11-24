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

void Enemi::deplacement(Background b)
{
  if(sprite.getPosition().x<b.getView().getCenter().x-(b.getWitdhView()/1.5))
  {
    cout<<"L'enemi doit etre supprimé"<<endl;
  }
  else{
    sprite.move(-speed,0);
  }

}

void Enemi::attaque(Background b, Vaisseau v)
{
  if ( this->getShootTime() >= this->getAtqSpeed())
    {
      Attaque* atq = new Atq1("Projectile/Projectile.png");

      //Defini les différentes variables ( a remplacer par des variables )
      float posX = this->getSprite().getPosition().x;
      float posY = this->getSprite().getPosition().y-3;
      float scaleX = this->getSprite().getScale().x;
      float scaleY = this->getSprite().getScale().y;
      float widthSprite = this->getTexture().getSize().x;


      atq->addProj(posX, posY, scaleX, scaleY, widthSprite);

      //PROBLEME ICI CAR LES PROJECTILE SE RETROUVENT TOUS AU MEME ENDROIT ( ? )
      //atq->setPosition(this->getSprite().getPosition().x+this->getTexture().getSize().x * this->getSprite().getScale().x,this->getSprite().getPosition().y+15*this->getSprite().getScale().y);
      atqs.push_back(atq);
      this->setShootTime(-1);
    }

    for(int i=0;i<atqs.size();i++)
    {
      atqs[i]->moveE(b.getView().getCenter().x-b.getWitdhView()); // Formule pas encore au top
      if(atqs[i]->getSizeProj()<1)
      {
        atqs.erase(atqs.begin()+i);
      }
    }

    // Cas ou un projectiles rencontre un projectile


}
