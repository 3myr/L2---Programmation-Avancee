#include "header/View.h"

// Methode constructive
View::View() : width(238), height(160), speed(0.2)
{
  mainView.setSize(width,height);
  mainView.setCenter(width/2,height/2);
}

View::View(const std::string FILENAME,int NbLigneInTxt)
{
  this->loadVar(FILENAME,NbLigneInTxt);
  mainView.setSize(width,height);
  mainView.setCenter(width/2,height/2);
}


// Fonctions d'observations
void View::affiche()
{
  cout<<"largeur view: "<<width<<endl;
  cout<<"hauteur view: "<<height<<endl;
  cout<<"center view: "<<mainView.getCenter().x<<endl;
  cout<<"size view: "<<mainView.getSize().x<<endl;
}

sf::View View::getView()
{
  return mainView;
}

float View::getWidth() const
{
  return width;
}

float View::getHeight() const
{
  return height;
}

float View::getSpeed()
{
  return speed;
}




// Fonctions de transformations
void View::loadVar(const std::string FILENAME,int NbLigneInTxt)
{
  //Allocation de mémoire pour les tableaux stockant les valeurs des variables du fichier .txt
  string* line;
  line = new string[NbLigneInTxt];

  // Ouverture du fichier et recupération des lignes dans un tableau ( tmp )
  ifstream myfile2 (FILENAME);

  if (myfile2.is_open())
  {
    for(int k=0;k<NbLigneInTxt;k++) // Permet de charger les lignes dans un tableau
    {
      getline (myfile2,line[k],'=');
      getline (myfile2,line[k],' ');
      getline (myfile2,line[k],';');
    }

    // Affectation des valeurs dans leur variable
    width = stod(line[0]);
    height = stod(line[1]);
    speed = stod(line[2]);

    myfile2.close();

  }
  else
  {
    cout << "Impossible d'ouvrir le fichier";
  }
  //free(line); // Probleme de liberation de memoire
}

void View::setWidth(int VIEWWIDTH)
{
  width = VIEWWIDTH;
}

void View::setHeight(int VIEWHEIGHT)
{
  height = VIEWHEIGHT;
}

void View::movingView()
{
  if(mainView.getCenter().x < 1785 && mainView.getCenter().y >=80)
  {
    mainView.move(speed,0);
  }
}
