#include "header/Vaisseau.h"

// Methode constructive -----------------------------------------------------

Vaisseau::Vaisseau() : shootTime(0)
{

}

Vaisseau::Vaisseau(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed ) : x(x), y(y), texture(texture), pv(pv), atqSpeed(atqSpeed), speed(speed), shootTime(0)
{

}

Vaisseau::Vaisseau(const std::string FILENAME,int NbLigneInTxt) : shootTime(0)
{
  this->loadVar(FILENAME,NbLigneInTxt);
  texture.loadFromFile(filename);
  sprite.setScale(0.25,0.25);
}

// ---------------------------------------------------------------------------





//Fonctions d'observations ---------------------------------------------------

void Vaisseau::affiche()
{
  cout<<"\nx : "<<x<<endl;
  cout<<"y : "<<y<<endl;
  cout<<"x de la texture: "<<texture.getSize().x<<endl;
  cout<<"x de la texture: "<<texture.getSize().y<<endl;
  cout<<"pv : "<<pv<<endl;
  cout<<"atqSpeed : "<<atqSpeed<<endl;
  cout<<"speed : " <<speed<<endl;
}

sf::Sprite Vaisseau::getSprite()
{
  return sprite;
}

sf::Texture Vaisseau::getTexture()
{
  return texture;
}

float Vaisseau::getShootTime()
{
  return shootTime;
}

int Vaisseau::getAtqSpeed()
{
  return atqSpeed;
}

sf::Sprite Vaisseau::getSpritePro(int i) // CHANGER TOUT CA
{
  return atqs[i]->getSpritePro(i);
}

int Vaisseau::getSizeProj(int i)
{
  return atqs[i]->getSizeProj();
}

Projectile Vaisseau::getProjectile(int i)
{
  return atqs[i]->getProjectile(i);
}

vector<Projectile> Vaisseau::getProjectiles(int i)
{
  return atqs[i]->getProjectiles();
}

int Vaisseau::getSizeAtqs()
{
  return atqs.size();
}

int Vaisseau::getPv()
{
  return pv;
}

float Vaisseau::getSpeed()
{
  return speed;
}

float Vaisseau::getPosition()
{
  return sprite.getPosition().x;
}

// ---------------------------------------------------------------------------






//Fonctions de transmorfations -----------------------------------------------

void Vaisseau::setTexture()
{
  sprite.setTexture(texture);
  sprite.setPosition(x,y);
}

int Vaisseau::collision(Vaisseau* v2)
{
  if(    this->getSprite().getPosition().x < v2->getSprite().getPosition().x + v2->getTexture().getSize().x * v2->getSprite().getScale().x
      && this->getSprite().getPosition().x + this->getTexture().getSize().x * this->getSprite().getScale().x > v2->getSprite().getPosition().x
      && this->getSprite().getPosition().y < v2->getSprite().getPosition().y + v2->getTexture().getSize().y * v2->getSprite().getScale().y
      && this->getSprite().getPosition().y + this->getTexture().getSize().y * this->getSprite().getScale().y > v2->getSprite().getPosition().y)
  {
    return 1;
  }
  return 0;
}

int Vaisseau::collision(Projectile p)
{

  if(    this->getSprite().getPosition().x < p.getSprite().getPosition().x + p.getTexture().getSize().x * p.getSprite().getScale().x
      && this->getSprite().getPosition().x + this->getTexture().getSize().x * this->getSprite().getScale().x > p.getSprite().getPosition().x
      && this->getSprite().getPosition().y < p.getSprite().getPosition().y + p.getTexture().getSize().y * p.getSprite().getScale().y
      && this->getSprite().getPosition().y + this->getTexture().getSize().y * this->getSprite().getScale().y > p.getSprite().getPosition().y)
  {
    return 1;
  }
  return 0;
}

void Vaisseau::loadVar(const std::string FILENAME,int NbLigneInTxt)
{
  //Allocation de mémoire pour les tableaux stockant les valeurs des variables du fichier .txt
  string* line;
  line = new string[NbLigneInTxt];

  // Ouverture du fichier et recupération des lignes dans un tableau ( tmp )
  ifstream myfile2 (FILENAME);

  if (myfile2.is_open())
  {
    for(int k=0;k<NbLigneInTxt-1;k++) // Permet de charger les lignes dans un tableau
    {
      getline (myfile2,line[k],'=');
      getline (myfile2,line[k],' ');
      getline (myfile2,line[k],';');
    }
    getline(myfile2,line[NbLigneInTxt-1],'"'); // Permet de ne prendre que la valeur de la variable
    getline(myfile2,line[NbLigneInTxt-1],'"');

    // Affectation des valeurs dans leur variable
    x = stod(line[0]);
    y = stod(line[1]);
    pv = stod(line[2]);
    atqSpeed = stod(line[3]);
    speed = stod(line[4]);
    filename = line[5];

    myfile2.close();

  }
  else
  {
    cout << "Impossible d'ouvrir le fichier";
  }
  //free(line); // Probleme de liberation de memoire
}

void Vaisseau::setShootTime(float VAL)
{
  if(VAL==-1)
  {
    shootTime = 0;
  }
  else
  {
    shootTime = shootTime + VAL;
  }
}

void Vaisseau::attaque(Background b)
{

}

void Vaisseau::deplacement(Background b)
{

}

void Vaisseau::stayInScreen(Background b)
{
  if(this->sprite.getPosition().x < b.getView().getCenter().x-b.getWitdhView()/2)
  {
    sprite.move(b.getMainView().getSpeed(),0);
  }
}

void Vaisseau::drawAttaque(sf::RenderWindow* window,int i)
{
  for(int j=0;j<atqs[i]->getSizeProj();j++)
  {
     window->draw(atqs[i]->getSpritePro(j));
  }
}

void Vaisseau::free()
{
  for (auto p : atqs)
   {
     delete p;
   }
   atqs.clear();

}

void Vaisseau::setScale(float x,float y)
{
  sprite.setScale(x,y);
}

// ---------------------------------------------------------------------------
