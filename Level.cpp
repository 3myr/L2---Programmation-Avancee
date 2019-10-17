#include "header/Level.h"

// Methode constructive
Level::Level() : Background()
{

}


Level::Level(const std::string FILENAME,const std::string FILENAMEVIEW,int NbLigneInTxt,int NbLigneInTxtView) : Background(FILENAME,FILENAMEVIEW,NbLigneInTxt,NbLigneInTxtView)
{

}

// Fonctions d'observations
void Level::affiche()
{
  cout<<"\nLevel: "<<endl;
  Background::affiche();
}
