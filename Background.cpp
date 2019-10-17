#include "header/Background.h"

// Methode constructive
Background::Background() : movingTime(0)
{

}

Background::Background(const std::string FILENAME,const std::string FILENAMEVIEW,int NbLigneInTxt,int NbLigneInTxtView) : movingTime(0)
{
  this->loadVar(FILENAME,NbLigneInTxt);
  texture.loadFromFile(filename);
  this->setView(View(FILENAMEVIEW,NbLigneInTxtView));
}


// Fonctions d'observations
void Background::affiche()
{
  cout<<"largeur background: "<<this->getWitdh()<<endl;
  cout<<"hauteur background: "<<this->getHeight()<<endl;
  mainView.affiche();

}

float Background::getWitdh()
{
 return texture.getSize().x;
}

float Background::getHeight()
{
  return texture.getSize().y;
}

sf::Texture Background::getTexture()
{
  return texture;
}

sf::Sprite Background::getSprite()
{
  return sprite;
}

sf::View Background::getView()
{
  return mainView.getView();
}

float Background::getMovingTime()
{
  return movingTime;
}

float Background::getWitdhView()
{
  return mainView.getWidth();
}




// Fonctions de transformations
void Background::loadVar(const std::string FILENAME,int NbLigneInTxt)
{
  //Allocation de mémoire pour les tableaux stockant les valeurs des variables du fichier .txt
  string* line;
  line = new string[NbLigneInTxt];

  // Ouverture du fichier et recupération des lignes dans un tableau ( tmp )
  ifstream myfile2 (FILENAME);

  if (myfile2.is_open())
  {
    getline(myfile2,line[NbLigneInTxt-1],'"'); // Permet de ne prendre que la valeur de la variable
    getline(myfile2,line[NbLigneInTxt-1],'"');

    // Affectation des valeurs dans leur variable
    filename = line[0];

    myfile2.close();

  }
  else
  {
    cout << "Impossible d'ouvrir le fichier";
  }
  //free(line); // Probleme de liberation de memoire
}

void Background::setTexture()
{
  sprite.setTexture(texture);
  //sprite.setPosition(x,y);
}

void Background::setView(View VIEW)
{
  mainView = VIEW;
}

void Background::movingView()
{
  if(movingTime>1)
  {
    movingTime = 0;
    mainView.movingView();
  }
}

void Background::setMovingTime(float VAL)
{
  if(VAL==-1)
  {
    movingTime = 0;
  }
  else
  {
    movingTime = movingTime + VAL;
  }
}
