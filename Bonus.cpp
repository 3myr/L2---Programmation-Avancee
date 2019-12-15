#include "header/Bonus.h"

// Methode constructive -----------------------------------------------------
/**
* \brief Instanciaton d'un bonus
*/
Bonus::Bonus()
{

}

/**
* \brief Instanciaton d'un bonus
*/
Bonus::Bonus(float x, float y, sf::Texture texture, float speed ) : x(x), y(y), texture(texture), speed(speed)
{

}

/**
* \brief Instanciaton d'un bonus
*/
Bonus::Bonus(const std::string FILENAME,int NbLigneInTxt)
{
  this->loadVar(FILENAME,NbLigneInTxt);
  texture.loadFromFile(filename);
  sprite.setScale(0.5,0.5);
  descente = 0;
}

// ---------------------------------------------------------------------------





//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
sf::Sprite Bonus::getSprite()
{
  return sprite;
}

/**
* \brief
*/
sf::Texture Bonus::getTexture()
{
  return texture;
}

/**
* \brief
*/
float Bonus::getSpeed()
{
  return speed;
}

/**
* \brief
*/
float Bonus::getPosition()
{
  return sprite.getPosition().x;
}

/**
* \brief
*/
string Bonus::getName()
{
  return nom;
}

// ---------------------------------------------------------------------------






//Fonctions de transmorfations -----------------------------------------------

/**
* \brief
*/
void Bonus::setTexture()
{
  sprite.setTexture(texture);
  sprite.setPosition(x,y);
  sprite.scale(0.2,0.2);
}

/**
* \brief Gere la collision entre le bonus et le joueur
*/
int Bonus::collision(Vaisseau* v2)
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

/**
* \brief Gere les deplacement du bonus
*/
void Bonus::deplacement(Background b)
{
  // Si le bonus n'est pas dans le champ de la camera
  if(sprite.getPosition().x<b.getView().getCenter().x-(b.getWitdhView()/0.5))
  {
  }
  else
  {
    // Si il n'a pas encore atteint le bord bas de la camera
    if(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height <= b.getView().getCenter().y +  b.getView().getCenter().y && descente)
    {
      sprite.move(-speed,speed);
    }
    else
    {
      // Choisit une vitesse de deplacement aléatoire entre 0 et 2 avec un pas de 0.3
      srand((unsigned)time(0));
      speed = (rand()%2)+0.3;
      descente = 0;
    }
    // Si il n'a pas encore atteint le bord haut de la camera
    if(sprite.getGlobalBounds().top >= b.getView().getCenter().y - b.getView().getCenter().y && !descente)
    {
      sprite.move(-speed,-speed);
    }
    else
    {
      // Choisit une vitesse de deplacement aléatoire entre 0 et 2 avec un pas de 0.3
      srand((unsigned)time(0));
      speed = (rand()%2)+0.3;
      descente = 1;
    }
  }
}

/**
* \brief Charge les informations relative au bonus avec des informations contenu dans un txt
*/
void Bonus::loadVar(const std::string FILENAME,int NbLigneInTxt)
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
    nom = line[0];
    x = stod(line[1]);
    y = stod(line[2]);
    speed = stod(line[3]);
    filename = line[4];

    myfile2.close();

  }
  else
  {
    cout << "Impossible d'ouvrir le fichier";
  }
  delete [] line;
}


// ---------------------------------------------------------------------------
