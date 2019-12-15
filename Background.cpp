/**
 * \file Background.cpp
 * \author Demazieres Remy
 * \date 15 decembre 2019
 *
 */
#include "header/Background.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instancie un level
*/
Background::Background()
{

}

/**
* \brief Instancie un level avec ces différentes "couches"
*/
Background::Background(const std::string FILENAMEVIEW,int NbLigneInTxtView)
{
  // Charge les données de la caméra ( taille, vitesse, etc..)
  this->setView(View(FILENAMEVIEW,NbLigneInTxtView));

  movingTime = 0;

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

/**
* \brief
*/
sf::View Background::getView()
{
  return mainView.getView();
}

/**
* \brief Retourne la clock pour gerer le deplacement de la camera
*/
float Background::getMovingTime()
{
  return movingTime;
}

/**
* \brief Retourne la largeur de la camera
*/
float Background::getWitdhView()
{
  return mainView.getWidth();
}

/**
* \brief Retourne la hauteur de la camera
*/
float Background::getHeightView()
{
  return mainView.getHeight();
}

/**
* \brief Retounre la camera ( l'objet )
*/
View Background::getMainView()
{
  return mainView;
}

/**
* \brief
*/
Couche* Background::getCouche(int i)
{
  return couches[i];
}

/**
* \brief Retourne toutes les couches
*/
vector<Couche*> Background::getCouches()
{
  return couches;
}

// ---------------------------------------------------------------------------





//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Charge les données présente dans un fichier texte
*/
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

/**
* \brief
*/
void Background::setView(View VIEW)
{
  mainView = VIEW;
}

/**
* \brief Deplace la camera
*/
void Background::movingView()
{
  if(movingTime>1)
  {
    movingTime = 0;
    mainView.movingView();
  }
}

/**
* \brief
*/
void Background::setMovingTime(float VAL)
{
  // Reinitialisation de la clock a 0
  if(VAL==-1)
  {
    movingTime = 0;
  }
  else
  {
    movingTime = movingTime + VAL;
  }
}


// ---------------------------------------------------------------------------
