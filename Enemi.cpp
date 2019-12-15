#include "header/Enemi.h"

// Methode constructive -----------------------------------------------------
/**
* \brief Instancie un enemi
*/
Enemi::Enemi() : Vaisseau()
{

}

/**
* \brief Instancie un enemi
*/
Enemi::Enemi(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed) : Vaisseau(x,y,texture,pv,atqSpeed,speed)
{

}

/**
* \brief Instancie un enemi
*/
Enemi::Enemi(const std::string FILENAME,int NbLigneInTxt) : Vaisseau(FILENAME,NbLigneInTxt)
{

}

// ---------------------------------------------------------------------------



//Fonctions d'observations ---------------------------------------------------

/**
* \brief Charge les données d'un enemi a partir d'un fichier texte
*/
void Enemi::loadVar(const std::string FILENAME,int NbLigneInTxt)
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

// ---------------------------------------------------------------------------




//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Gere le deplacement d'un enemi
*/
void Enemi::deplacement(Background b)
{
  // Si l'enemi n'est pas dans le champ de la camera
  if(sprite.getPosition().x<b.getView().getCenter().x-(b.getWitdhView()/1.5))
  {
  }
  else{
    sprite.move(-speed,0);
  }

}

/**
* \brief Gestion de l'attaque d'un enemi
*/
void Enemi::attaque(Background b)
{
  if ( this->getShootTime() >= this->getAtqSpeed())
    {
      if(atqs.size()<3)
      {
        Attaque* atq = new Atq3("Projectile/Projectile.png");

        //Defini les différentes variables ( a remplacer par des variables )
        float posX = this->getSprite().getPosition().x;
        float posY = this->getSprite().getPosition().y-3;
        float scaleX = this->getSprite().getScale().x;
        float scaleY = this->getSprite().getScale().y;
        float widthSprite = this->getTexture().getSize().x;

        atq->addProj(posX, posY, scaleX, scaleY, widthSprite);

        atqs.push_back(atq);
        this->setShootTime(-1);
      }
    }

    this->freeAtq(b);

}

/**
* \brief
*/
void Enemi::setPosition(float x, float y)
{
  this->x = x;
  this->y = y;
}

/**
* \brief Supprime les attaques et les projectiles en arretant le sons de chaque attaques
*/
void Enemi::freeAtq(Background b)
{
  for(int i=0;i<atqs.size();i++)
  {
    // Permet de faire sortir les projectiles du champ de la caméra
    atqs[i]->moveE(b.getView().getCenter().x-b.getWitdhView());
    if(atqs[i]->getSizeProj()<1)
    {
      // Arrete le son des attaques
      atqs[i]->stopSound();
      // Supprime la memoire d'une attaque
      delete atqs[i];
      // Supprime l'attaque de la liste ( dans l'ordre inverse, erreur de segmentation )
      atqs.erase(atqs.begin()+i);
    }
  }
}

// ---------------------------------------------------------------------------
