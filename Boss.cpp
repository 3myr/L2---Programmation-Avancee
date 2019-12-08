#include "header/Boss.h"

// Methode constructive -----------------------------------------------------

Boss::Boss() : Vaisseau()
{

}

Boss::Boss(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed) : Vaisseau(x,y,texture,pv,atqSpeed,speed)
{

}

Boss::Boss(const std::string FILENAME,int NbLigneInTxt) : Vaisseau(FILENAME,NbLigneInTxt), isAttaq(0)
{

}

// ---------------------------------------------------------------------------



//Fonctions d'observations ---------------------------------------------------


// ---------------------------------------------------------------------------




//Fonctions de transmorfations -----------------------------------------------

void Boss::deplacement(Background b)
{
  if(sprite.getPosition().x<b.getView().getCenter().x-(b.getWitdhView()/1.5))
  {
    //cout<<"L'enemi doit etre supprimé"<<endl;
  }
  else{
    sprite.setPosition(b.getView().getCenter().x,b.getView().getCenter().y);
  }

}

void Boss::attaque(Background b)
{
  if(animationTime<200)
  {
    this->animation(0);
  }
  else
  {
    if(animationTime>200 && animationTime<400)
    {
      this->animation(1);
    }
    else
    {
      if(animationTime>400 && animationTime<600)
      {
        this->animation(2);
      }
      else
      {
        if(animationTime>600)
        {
          this->animation(3);
          animationTime = 0;
          isAttaq = 1;
        }
      }
    }
  }

  if(isAttaq)
  {
    if ( this->getShootTime() >= this->getAtqSpeed())
      {

        if(atqs.size()<1)
        {
          Attaque* atq = new Atq1("Projectile/Projectile3.png");

          //Defini les différentes variables ( a remplacer par des variables )
          float posX = this->getSprite().getPosition().x/3;
          float posY = this->getSprite().getPosition().y-3;
          float scaleX = this->getSprite().getScale().x;
          float scaleY = this->getSprite().getScale().y;
          float widthSprite = this->getTexture().getSize().x;

          atq->addProj(posX, posY, scaleX, scaleY, widthSprite);

          atqs.push_back(atq);
          this->setShootTime(-1);
          isAttaq = 0;
        }
      }
    }

    // Supprimes les attaques qui sont hors de la vue
    for(int i=0;i<atqs.size();i++)
    {
      atqs[i]->moveE(b.getView().getCenter().x-b.getWitdhView()); // Formule pas encore au top
      if(atqs[i]->getSizeProj()<1)
      {
        delete atqs[i];
        atqs.erase(atqs.begin()+i);
      }
    }

    // Supprime l'attaque après x temps
}

void Boss::setPosition(float x, float y)
{
  this->x = x;
  this->y = y;
}

void Boss::animation(int ROW)
{
  switch (ROW)
  {
    case 0:
    sprite.setTextureRect(sf::IntRect(0,  0 , 150, 58));
    break;

    case 1:
    sprite.setTextureRect(sf::IntRect(150,  0 , 150, 58));
    break;

    case 2:
    sprite.setTextureRect(sf::IntRect(300,  0 , 150, 58));
    break;

    case 3:
    sprite.setTextureRect(sf::IntRect(450,  0 , 150, 58));
    break;
  }

}

void Boss::setTime(float VAL)
{
  if(VAL==-1)
  {
    animationTime = 0;
  }
  else
  {
    animationTime = animationTime + VAL;
  }
}

void Boss::setTexture()
{
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 150, 58));
  sprite.setPosition(x,y);
}


// ---------------------------------------------------------------------------
