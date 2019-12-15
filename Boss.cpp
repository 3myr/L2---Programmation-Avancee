#include "header/Boss.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Initialisation d'un boss
*/
Boss::Boss() : Vaisseau()
{

}

/**
* \brief Initialisation d'un boss
*/
Boss::Boss(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed) : Vaisseau(x,y,texture,pv,atqSpeed,speed)
{

}

/**
* \brief Initialisation d'un boss
*/
Boss::Boss(const std::string FILENAME,int NbLigneInTxt) : Vaisseau(FILENAME,NbLigneInTxt), isAttaq(0), descente(0), vaincu(0)
{
  sprite.setScale(0.5,0.5);
}

// ---------------------------------------------------------------------------



//Fonctions d'observations ---------------------------------------------------

/**
*
*/
int Boss::getEtat()
{
  return vaincu;
}

/**
* \brief Charge les informations relative au Boss avec des informations contenu dans un txt
*/
void Boss::loadVar(const std::string FILENAME,int NbLigneInTxt)
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
* \brief Fonction qui gère le deplacement d'un boss
*/
void Boss::deplacement(Background b)
{
  // Si le boss n'est pas dans le champ de la caméra
  if(sprite.getPosition().x<b.getView().getCenter().x-(b.getWitdhView()/1.5))
  {
  }
  else
  {
    // Si le boss n'est pas arrivé en bas du champ de la caméra et qu'il descent
    if(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height <= b.getView().getCenter().y +  b.getView().getCenter().y && descente)
    {
      // Deplacement vers le bas
      sprite.move(0,speed);
    }
    else
    {
      // Choisit une vitesse de deplacement aléatoire entre 0 et 2 avec un pas de 0.3
      srand((unsigned)time(0));
      speed = (rand()%2)+0.3;
      descente = 0;
    }
    // Si le boss n'est pas arrivé en haut du champ de la caméra et qu'il monte
    if(sprite.getGlobalBounds().top >= b.getView().getCenter().y - b.getView().getCenter().y && !descente)
    {
      sprite.move(0,-speed);
    }
    else
    {
      // Choisit une vitesse de deplacement aléatoire entre 0 et 2 avec un pas de 0.
      srand((unsigned)time(0));
      speed = (rand()%2)+0.3;
      descente = 1;
    }
  }

}

/**
* \brief Permet de gerer l'attaque d'un boss
*/
void Boss::attaque(Background b)
{
  // Si le boss n'attaque pas, joue l'animation d'attaque
  if(!isAttaq)
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
            isAttaq = 1;
          }
        }
      }
    }
  }
  else // Le boss attaque donc la clock se remet a 0
  {
    animationTime = 0;
  }

  // si le boss attaque
  if(isAttaq)
  {
    if ( this->getShootTime() >= this->getAtqSpeed()) // Permet de gérer sa vitesse d'attaque
      {
        if(atqs.size()<2) // Permet de ne tirer que 2 attaques ( attaques != projectile )
        {
          Attaque* atq;
          // Si ca vie est en dessous d'un certain seuil
          if(pv<15)
          {
            atq = new Atq2("Projectile/Projectile3.png");
          }
          else
          {
            atq = new Atq1("Projectile/Projectile3.png");
          }

          //Defini les différentes variables ( a remplacer par des variables )
          float posX = this->getSprite().getPosition().x-350;
          float posY = this->getSprite().getPosition().y+10;
          float scaleX = this->getSprite().getScale().x;
          float scaleY = this->getSprite().getScale().y;
          float widthSprite = this->getTexture().getSize().x;

          atq->addProj(posX, posY, scaleX, scaleY, widthSprite); // Ajoute un projectile a l'attaque
          atqs.push_back(atq); // Ajoute l'attaque dans la liste des attaques du boss

          this->setShootTime(-1);
          isAttaq = 0;
        }
      }
    }
    // Supprimes les attaques qui sont hors de la vue
    this->freeAtq(b);
}

/**
* \brief
*/
void Boss::setPosition(float x, float y)
{
  this->x = x;
  this->y = y;
}

/**
* \brief Gere l'animation du boss
* \param ROW Choix de l'image permattant son animation
*/
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

/**
* \brief Fixe le temps de la clock pour gérer l'animation
*/
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

/**
* \brief
*/
void Boss::setTexture()
{
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 150, 58)); // Gere le sprite par défault ( sans animation )
  sprite.setPosition(x,y);
}

/**
* \brief Fixe si le boss est vaincu ou non
*/
void Boss::setEtat(int x)
{
  vaincu = x;
}

/**
* \brief Fonction qui gere les actions lors de la mort du boss
*/
int Boss::dead(Background b)
{
  // Supprimes les attaques
  this->freeAtq(b);
  // Gere l'animation de mort
  this->animation(2);

  // Quand le boss meurt, il sort du champ de la caméra en se deplacent vers le bas
  if(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height <= b.getView().getCenter().y +  b.getView().getCenter().y  + 50)
  {
    sprite.move(0,0.5);
    return 0;
  }
  else
  {
    return 1;
  }
}

/**
* \brief Supprime les attaques et les projectiles en arretant le sons de chaque attaques
*/
void Boss::freeAtq(Background b)
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
