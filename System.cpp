#include "System.h"

// Methode constructive
System::System()
{
}

// Fonctions d'obversations
sf::View System::getView() const
{
  return mainView;
}

int System::getSizeX() const
{
  return sizeX;
}

int System::getSizeY() const
{
    return sizeY;
}

int* System::openMap(const std::string FILENAME)
{
  string varRemovable;
  string line[width*height];
  int m=0;
  ifstream myfile2 (FILENAME);
  for(int i=0;i<width*height-1;i++)
  {
    line_int[i] = 0;
  }
  if (myfile2.is_open())
  {
      //getline (myfile2,varRemovable); // permet de ne pas gerer la premiere ligne
    for(int k=0;k<2;k++) // Permet de charger les lignes ( ici 2 lignes ) dans un tableau
    {
      getline (myfile2,line[k]);
    }
    myfile2.close();
  }
  else
  {
    cout << "Impossible d'ouvrir le fichier";
  }

  for(int k=1;k<2;k++) // Charge la première ligne ( en partant de 0 )
  {
    for(int j=0;j<line[k].length();j++)
    {
      if(line[k].at(j) == '0')
      {
        line_int[m] = line_int[m]*10+0;
      }
      if(line[k].at(j) == '1')
      {
        line_int[m] = line_int[m]*10+1;
      }
      if(line[k].at(j) == '2')
      {
        line_int[m] = line_int[m]*10+2;
      }
      if(line[k].at(j) == '3')
      {
        line_int[m] = line_int[m]*10+3;
      }
      if(line[k].at(j) == '4')
      {
        line_int[m] = line_int[m]*10+4;
      }
      if(line[k].at(j) == '5')
      {
        line_int[m] = line_int[m]*10+5;
      }
      if(line[k].at(j) == '6')
      {
        line_int[m] = line_int[m]*10+6;
      }
      if(line[k].at(j) == '7')
      {
        line_int[m] = line_int[m]*10+7;
      }
      if(line[k].at(j) == '8')
      {
        line_int[m] = line_int[m]*10+8;
      }
      if(line[k].at(j) == '9')
      {
        line_int[m] = line_int[m]*10+9;
      }
      if(line[k].at(j) == ',')
      {
        m++; // Permet de savoir quand un nombre est "fini"
      }
    }
  }
  return line_int;
}



// Fonctions de transformations
void System::setView(sf::View VIEW)
{
  mainView = VIEW;
}

void System::centerPlayer(Player PLAYER)
{

  // REMPLACER LES VALEURS NUMERIQUE PAR DES VARIABLES
  if(PLAYER.getX()<155 && PLAYER.getY()<120)
  {
    mainView.setCenter(155,120);
    return;
  }

  if(PLAYER.getX()<155 && PLAYER.getY()>840)
  {
    mainView.setCenter(155,840);
  }

  if(PLAYER.getY()<120 && PLAYER.getX()>1093)
  {
    mainView.setCenter(1093,120);
    return;
  }

  if(PLAYER.getX()>1093 && PLAYER.getY()>840)
  {
    mainView.setCenter(1093,840);
    return;
  }

  if(PLAYER.getX()>155 && PLAYER.getY()<120)
  {
    mainView.setCenter(PLAYER.getX(),120);
    return;
  }

  if(PLAYER.getX()<155 && PLAYER.getY()<840)
  {
    mainView.setCenter(155,PLAYER.getY());
    return;
  }

  if(PLAYER.getX()>155 && PLAYER.getY()>840)
  {
    mainView.setCenter(PLAYER.getX(),840);
    return;
  }

  if(PLAYER.getX()>1093 && PLAYER.getY()>120)
  {
    mainView.setCenter(1093,PLAYER.getY());
    return;
  }

  if(PLAYER.getX()>155 && PLAYER.getY()>120 && PLAYER.getX()<1093 && PLAYER.getY()<840)
  {
    mainView.setCenter(PLAYER.getSprite().getPosition());
  }
}

void System::setSizeX(int SIZEX)
{
  sizeX = SIZEX;
}

void System::setSizeY(int SIZEY)
{
  sizeY = SIZEY;
}

void System::initialisate()
{
  mainView.setSize(sizeX,sizeY);
}

void System::animationCounter(Player JOUEUR, int COUNTERWALKING, int ANIMATIONCOUNTER)
{
  if (ANIMATIONCOUNTER >= JOUEUR.getFrameDuration()) // Comparaison pour savoir si l'on passe au sprite suivant de l'animation
  {
    ANIMATIONCOUNTER =0;
    COUNTERWALKING++;
    if (COUNTERWALKING == 6) // Permet de choisir le bon sprite pour que l'animation soit fluide et cohérente
    {
      COUNTERWALKING = 0;
    }
  }
}

void System::saveMap(int* MAP,const std::string FILENAME)
{
  myMap.open (FILENAME);
  myMap << "map["<< width*height <<"] = { \n";
  for(int i=0;i<width*height-2;i++)
  {
      myMap << MAP[i] << ",";
  }
  myMap << MAP[width*height-1];
  myMap << " } ";
  myMap.close();
}
