#include "header/View.h"

// Methode constructive -----------------------------------------------------

/**
* \brief Instanciation d'une camera
*/
View::View() : width(238), height(160), speed(0.2)
{
  mainView.setSize(width,height);
  mainView.setCenter(width/2,height/2);
}

/**
* \brief Instanciation d'une camera
*/
View::View(const std::string FILENAME,int NbLigneInTxt)
{
  try
  {
    this->loadVar(FILENAME,NbLigneInTxt);
  }
  catch(std::exception const& e)
  {
    cout<<"CHAMP INCORRECT, MODIFIER LE FICHIER TXT !"<<endl;
    exit(EXIT_FAILURE);
  }
  mainView.setSize(width,height);
  mainView.setCenter(width/2,height/2);
}

// ---------------------------------------------------------------------------




//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
sf::View View::getView()
{
  return mainView;
}

/**
* \brief
*/
float View::getWidth() const
{
  return width;
}

/**
* \brief
*/
float View::getHeight() const
{
  return height;
}

/**
* \brief
*/
float View::getSpeed()
{
  return speed;
}

// ---------------------------------------------------------------------------






//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Charge les informations relative a la camera avec des informations contenu dans un txt
*/
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
  delete [] line;
}

/**
* \brief
*/
void View::setWidth(int VIEWWIDTH)
{
  width = VIEWWIDTH;
}

/**
* \brief
*/
void View::setHeight(int VIEWHEIGHT)
{
  height = VIEWHEIGHT;
}

/**
* \brief
*/
void View::movingView()
{
  // Arrete le deplacement quand la caméra arrive au bord de la carte
  if(mainView.getCenter().x < 1739 && mainView.getCenter().y >=80)
  {
    mainView.move(speed,0);
  }
}

// ---------------------------------------------------------------------------
