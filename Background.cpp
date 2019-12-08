#include "header/Background.h"

// Methode constructive -----------------------------------------------------

Background::Background()
{

}

Background::Background(const std::string FILENAMEVIEW,int NbLigneInTxtView)
{
  this->setView(View(FILENAMEVIEW,NbLigneInTxtView));

  // initialisation des couches
  Couche* c = new Couche("Background/background.txt",7);
  c->setTextureTileSet();
  couches.push_back(c);

  c = new Couche("Background/mountains1.txt",7);
  c->setTextureTileSet();
  couches.push_back(c);

  c = new Couche("Background/mountains2.txt",7);
  c->setTextureTileSet();
  couches.push_back(c);

  c = new Couche("Background/arbre1.txt",7);
  c->setTextureTileSet();
  couches.push_back(c);

  c = new Couche("Background/arbre2.txt",7);
  c->setTextureTileSet();
  couches.push_back(c);

  c = new Couche("Background/moon.txt",7);
  c->setTextureTileSet();
  couches.push_back(c);

}

// ---------------------------------------------------------------------------




//Fonctions d'observations ---------------------------------------------------

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

float Background::getHeightView()
{
  return mainView.getHeight();
}

View Background::getMainView()
{
  return mainView;
}

Couche* Background::getCouche(int i)
{
  return couches[i];
}

vector<Couche*> Background::getCouches()
{
  return couches;
}

// ---------------------------------------------------------------------------





//Fonctions de transmorfations -----------------------------------------------

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
  delete [] line;
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

void Background::setCouche(const std::string LEVELNAME)
{

}


// ---------------------------------------------------------------------------
