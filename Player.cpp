/**
 * \file Player.cpp
 * \author Demazieres Remy
 * \date 15 decembre 2019
 *
 */
#include "header/Player.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instancie un joueur
*/
Player::Player() : Vaisseau()
{

}

/**
* \brief Instancie un joueur
*/
Player::Player(float x, float y, sf::Texture texture, int pv, int atqSpeed, float speed) : Vaisseau(x,y,texture,pv,atqSpeed,speed), score(0), level(0)
{

}

/**
* \brief Instancie un joueur
*/
Player::Player(const std::string FILENAME,int NbLigneInTxt) : score(0), level(0)
{

  this->loadVar(FILENAME,NbLigneInTxt);
  texture.loadFromFile(filename);
  sprite.setScale(0.25,0.25);
}

// ---------------------------------------------------------------------------





//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
Attaque* Player::getAttque(int i)
{
  return atqs[i];
}

/**
* \brief
*/
int Player::getScore()
{
  return score;
}

/**
* \brief Charge les données d'un joueur a partir d'un fichier texte
*/
void Player::loadVar(const std::string FILENAME,int NbLigneInTxt)
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
    score = stod(line[5]);
    level = stod(line[6]);
    bonus = line[7];
    filename = line[8];

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
string Player::getFilename()
{
  return filename;
}

/**
* \brief
*/
int Player::getLevel()
{
  return level;
}

/**
* \brief
*/
string Player::getBonus()
{
  return bonus;
}


// ---------------------------------------------------------------------------




//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Gere le deplacement d'un joueur
*/
void Player::deplacement(Background b)
{
  // Gère la gestion d'une manette ou d'un clavier
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 60.0) // Deplacement a la manette ou au clavier
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

/**
* \brief Gestion de l'attaque d'un joueur
*/
void Player::attaque(Background b)
{
  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Joystick::isButtonPressed(0, 0) )&& this->getShootTime() >= this->getAtqSpeed())
  {
    Attaque* atq;
    if(atqs.size()<3)
    {
      // Gestion des bonus ramassé
      if(this->bonus.compare("bonus1") == 0)
      {
         atq = new Atq1("Projectile/Projectile2.png");
      }
      else
      {
        if(this->bonus.compare("bonus2") == 0)
        {
           atq = new Atq2("Projectile/Projectile2.png");
        }
        else
        {
          atq = new Atq3("Projectile/Projectile2.png");
        }
      }

      //Defini les différentes variables ( a remplacer par des variables )
      float posX = this->getSprite().getPosition().x;
      float posY = this->getSprite().getPosition().y;
      float scaleX = this->getSprite().getScale().x;
      float scaleY = this->getSprite().getScale().y;
      float widthSprite = this->getTexture().getSize().x;


      atq->addProj(posX, posY, scaleX, scaleY, widthSprite);

      atqs.push_back(atq);
      this->setShootTime(-1);
      score -=1;
    }
  }
  this->freeAtq(b);
}

/**
* \brief Supprime les attaques et les projectiles en arretant le sons de chaque attaques
*/
void Player::freeAtq(Background b)
{
  for(int i=0;i<atqs.size();i++)
  {
    atqs[i]->moveP(b.getView().getCenter().x+b.getWitdhView()); // Formule pas encore au top
    if(atqs[i]->getSizeProj()<1)
    {
      atqs[i]->stopSound();
      delete atqs[i];
      atqs.erase(atqs.begin()+i);
    }
  }
}

/**
* \brief Gestion de collisions avec un bonus
*/
int Player::collisionBonus(Bonus* b)
{
  if(    this->getSprite().getPosition().x < b->getSprite().getPosition().x + b->getSprite().getGlobalBounds().width
      && this->getSprite().getPosition().x + this->getSprite().getGlobalBounds().width > b->getSprite().getPosition().x
      && this->getSprite().getPosition().y < b->getSprite().getPosition().y + b->getSprite().getGlobalBounds().height
      && this->getSprite().getPosition().y + this->getSprite().getGlobalBounds().height > b->getSprite().getPosition().y)
  {
    // Le joueur prend le nom du bonus
    this->bonus = b->getName();
    return 1;
  }
  return 0;
}

/**
* \brief
*/
void Player::setScore(int i)
{
  score += i;
}

/**
* \brief
*/
void Player::setLevel(int i)
{
  level = i;
}
// ---------------------------------------------------------------------------
