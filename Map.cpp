#include "header/Map.h"

// Methode constructive
Map::Map()
{
  this->loadVar("Map/level1.txt",2);
  map = (int*)malloc((mapWidth*mapHeight) * sizeof(int)); // Allocation de mapWidth*mapHeight mémoire de type int
}

// Fonctions d'observations
int Map::getMapWitdh() const
{
  return mapWidth;
}

int Map::getMapHeight() const
{
  return mapHeight;
}

sf::Texture Map::getTexture() const
{
  return texture;
}

sf::Sprite Map::getSprite() const
{
  return sprite;
}

int *Map::getMap() // On utilise un pointeur pour retourner l'adresse du tableau ( pas sur du fonctionnement )
{
  return map;
}

void Map::loadVar(const std::string FILENAME, int NbLigneInTxt)
{
  int m=0;

  //Allocation de mémoire pour les tableaux stockant les valeurs des variables du fichier .txt
  string* line;
  line = new string[NbLigneInTxt];
  int* tmp;
  tmp = new int[NbLigneInTxt];

  for(int i=0;i<NbLigneInTxt;i++)
  {
    tmp[i] = 0;
  }

  ifstream myfile2 (FILENAME);

  if (myfile2.is_open())
  {
    for(int k=0;k<NbLigneInTxt;k++) // Permet de charger les lignes ( ici 2 lignes ) dans un tableau
    {
      getline (myfile2,line[k]);
    }
    myfile2.close();
  }
  else
  {
    cout << "Impossible d'ouvrir le fichier";
  }

  for(int k=0;k<NbLigneInTxt;k++) // Charge la première ligne ( en partant de 0 )
  {
    for(int j=0;j<line[k].length();j++)
    {
      if(line[k].at(j) == '0')
      {
        tmp[m] = tmp[m]*10+0;
      }
      if(line[k].at(j) == '1')
      {
        tmp[m] = tmp[m]*10+1;
      }
      if(line[k].at(j) == '2')
      {
        tmp[m] = tmp[m]*10+2;
      }
      if(line[k].at(j) == '3')
      {
        tmp[m] = tmp[m]*10+3;
      }
      if(line[k].at(j) == '4')
      {
        tmp[m] = tmp[m]*10+4;
      }
      if(line[k].at(j) == '5')
      {
        tmp[m] = tmp[m]*10+5;
      }
      if(line[k].at(j) == '6')
      {
        tmp[m] = tmp[m]*10+6;
      }
      if(line[k].at(j) == '7')
      {
        tmp[m] = tmp[m]*10+7;
      }
      if(line[k].at(j) == '8')
      {
        tmp[m] = tmp[m]*10+8;
      }
      if(line[k].at(j) == '9')
      {
        tmp[m] = tmp[m]*10+9;
      }
      if(line[k].at(j) == ';')
      {
        m++; // Permet de savoir quand un nombre est "fini"
      }
    }
  }
  this->setMapWitdh(tmp[0]); // Stocke la première valeur dans mapWidth
  this->setMapHeight(tmp[1]); // Stocke la première valeur dans mapHeight
  free(tmp);
  //free(line); // Probleme de liberation de memoire
}
/*
int Map::getTile(float X, float Y) const
{
  int playerTileX = (int)X/spriteLar;
  int playerTileY = (int)Y/spriteLon;
  int spriteNumber = mapWidth*playerTileY+playerTileX;
  return spriteNumber;
}
*/
// Fonctions de transformations
void Map::setMapWitdh(int WIDTH)
{
  mapWidth = WIDTH;
}

void Map::setMapHeight(int HEIGHT)
{
  mapHeight = HEIGHT;
}

void Map::setTexture(const std::string FILENAME) // Permet un rendu 2d de la map ( texture + sprite )
{

  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
}

void Map::saveMap(int* MAP,const std::string FILENAME)
{
  ofstream myMap;
  //myMap.open (FILENAME);
  myMap << "map["<< mapWidth*mapHeight <<"] = { \n";
  for(int i=0;i<mapWidth*mapHeight-2;i++)
  {
      myMap << MAP[i] << ",";
  }
  myMap << MAP[mapWidth*mapHeight-1];
  myMap << " } ";
  myMap.close();
}


// Liberation de memoire

void Map::memFree()
{
  //free(map);
}
