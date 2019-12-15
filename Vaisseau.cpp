/**
 * \file Vaisseau.cpp
 * \author Demazieres Remy
 * \date 15 decembre 2019
 *
 */
#include "header/Vaisseau.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instanciation d'un vaisseau
*/
Vaisseau::Vaisseau() : shootTime(0)
{

}

/**
* \brief Instanciation d'un vaisseau
*/
Vaisseau::Vaisseau(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed ) : x(x), y(y), texture(texture), pv(pv), atqSpeed(atqSpeed), speed(speed), shootTime(0)
{

}

/**
* \brief Instanciation d'un vaisseau
*/
Vaisseau::Vaisseau(const std::string FILENAME,int NbLigneInTxt) : shootTime(0)
{
  try
  {
    this->loadVar(FILENAME,NbLigneInTxt);
    texture.loadFromFile(filename);
  }
  catch(std::exception const& e)
  {
    cout<<"CHAMP INCORRECT, MODIFIER LE FICHIER TXT !"<<endl;
    exit(EXIT_FAILURE);
  }
}

// ---------------------------------------------------------------------------





//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
sf::Sprite Vaisseau::getSprite()
{
  return sprite;
}

/**
* \brief
*/
sf::Texture Vaisseau::getTexture()
{
  return texture;
}

/**
* \brief
*/
float Vaisseau::getShootTime()
{
  return shootTime;
}

/**
* \brief
*/
int Vaisseau::getAtqSpeed()
{
  return atqSpeed;
}

/**
* \brief
*/
sf::Sprite Vaisseau::getSpritePro(int i) // CHANGER TOUT CA
{
  return atqs[i]->getSpritePro(i);
}

/**
* \brief
*/
int Vaisseau::getSizeProj(int i)
{
  return atqs[i]->getSizeProj();
}

/**
* \brief
*/
Projectile Vaisseau::getProjectile(int i)
{
  return atqs[i]->getProjectile(i);
}

/**
* \brief
*/
vector<Projectile> Vaisseau::getProjectiles(int i)
{
  return atqs[i]->getProjectiles();
}

/**
* \brief
*/
int Vaisseau::getSizeAtqs()
{
  return atqs.size();
}

/**
* \brief
*/
int Vaisseau::getPv()
{
  return pv;
}

/**
* \brief
*/
float Vaisseau::getSpeed()
{
  return speed;
}

/**
* \brief
*/
float Vaisseau::getPosition()
{
  return sprite.getPosition().x;
}

// ---------------------------------------------------------------------------






//Fonctions de transmorfations -----------------------------------------------

/**
* \brief
*/
void Vaisseau::setTexture()
{
  sprite.setTexture(texture);
  sprite.setPosition(x,y);
}

/**
* \brief Gere collision entre deux vaisseau
*/
int Vaisseau::collision(Vaisseau* v2)
{
  if(    this->getSprite().getPosition().x < v2->getSprite().getPosition().x + v2->getSprite().getGlobalBounds().width
      && this->getSprite().getPosition().x + this->getSprite().getGlobalBounds().width > v2->getSprite().getPosition().x
      && this->getSprite().getPosition().y < v2->getSprite().getPosition().y + v2->getSprite().getGlobalBounds().height
      && this->getSprite().getPosition().y + this->getSprite().getGlobalBounds().height > v2->getSprite().getPosition().y)
  {
    return 1;
  }
  return 0;
}

/**
* \brief Gere collision avec un projectile
*/
int Vaisseau::collision(Projectile p)
{

  if(    this->getSprite().getPosition().x < p.getSprite().getPosition().x + p.getSprite().getGlobalBounds().width
      && this->getSprite().getPosition().x + this->getSprite().getGlobalBounds().width > p.getSprite().getPosition().x
      && this->getSprite().getPosition().y < p.getSprite().getPosition().y + p.getSprite().getGlobalBounds().height
      && this->getSprite().getPosition().y + this->getSprite().getGlobalBounds().height > p.getSprite().getPosition().y)
  {
    return 1;
  }
  return 0;
}

/**
* \brief Gere collision avec un projectile du joueur et un enemi
*/
int Vaisseau::collisionProjectile(Vaisseau* e)
{
  // Pour optimiser la recherche de collisions, on regarde la distance entre le premier projectile tiré et la distance entre celui-ci et le vaisseau enemi ainsi que la distance entre un vaisseau enemi et le player
  if(atqs.size()>0)
  {
    if(atqs[0]->getProjectile(0).getPosition() - e->getSprite().getPosition().x < 50 || this->getSprite().getPosition().x - e->getSprite().getPosition().x < 20)
    //if(true)
    {
      for(int i=0;i<atqs.size();i++)
      {
        for(int j=0;j<atqs[i]->getSizeProj();j++)
        {
          if(e->collision(atqs[i]->getProjectile(j))==1)
          {
            atqs[i]->erase(j);
            return 1; // efface vaisseau
          }
        }
      }
    }
  }
  return 0;
}

/**
* \brief Charge les informations relative a un vaisseau avec des informations contenu dans un txt
*/
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
  delete [] line;
}

/**
* \brief
*/
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

/**
* \brief
*/
void Vaisseau::attaque(Background b)
{

}

/**
* \brief Fonction qui gère le deplacement d'un vaisseau
*/
void Vaisseau::deplacement(Background b)
{

}

/**
* \brief Restreint la zone de deplacement d'un vaisseau en fonction de la camera
*/
void Vaisseau::stayInScreen(Background b)
{

  if(this->sprite.getPosition().x < b.getView().getCenter().x-b.getWitdhView()/2)
  {
    sprite.move(b.getMainView().getSpeed(),0);
  }
}

/**
* \brief Affiche les attaques
*/
void Vaisseau::drawAttaque(sf::RenderWindow* window,int i)
{
  for(int j=0;j<atqs[i]->getSizeProj();j++)
  {
     window->draw(atqs[i]->getSpritePro(j));
  }
}

/**
* \brief
*/
void Vaisseau::free()
{
  for (auto p : atqs)
   {
     delete p;
   }
   atqs.clear();

}

/**
* \brief
*/
void Vaisseau::setScale(float x,float y)
{
  sprite.setScale(x,y);
}

/**
* \brief
*/
void Vaisseau::setPv(float x)
{
  pv = pv + x;
}

/**
* \brief
*/
void Vaisseau::freeAtq(Background b)
{

}

// ---------------------------------------------------------------------------
