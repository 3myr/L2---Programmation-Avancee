#include "header/Map.h"

// Methode constructive
Map::Map()
{
  mapWidth = 52;
  mapHeight = 60;
  spriteLar = 24;
  spriteLon = 16;
  tilsetWidth = 28;
  tilsetHeight = 37;
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

int Map::getSpriteLar() const
{
  return spriteLar;
}

int Map::getSpriteLon() const
{
  return spriteLon;
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

int* Map::openMap(const std::string FILENAME)
{
  int m=0;

  //Allocation de mémoire pour les tableaux stockant les valeurs des variables du fichier .txt
  string* line;
  int tailleLine = mapWidth*mapHeight;
  int tailleLineInt = mapWidth*mapHeight;
  line = new string[tailleLine];
  //line = (string*)malloc((mapWidth*mapHeight) * sizeof(string));
  int* line_int;
  line_int = (int*)malloc((mapWidth*mapHeight) * sizeof(int));
  //line_int = new int[tailleLineInt];

  ifstream myfile2 (FILENAME);

  for(int i=0;i<mapWidth*mapHeight-1;i++)
  {
    line_int[i] = 0;
  }
  if (myfile2.is_open())
  {
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
  //free(line); // Desalloue la mémoire du tableau servant à récuperer les valeurs des variables du .txt
  return line_int;
}

// Fonctions de transformations
void Map::setMapWitdh(int WIDTH)
{
  mapWidth = WIDTH;
}

void Map::setMapHeight(int HEIGHT)
{
  mapHeight = HEIGHT;
}

void Map::setSpriteLar(float LARGEUR)
{
  spriteLar = LARGEUR;
}

void Map::setSpriteLon(float LONGUEUR)
{
  spriteLon = LONGUEUR;
}

void Map::setTexture(const std::string FILENAME, sf::RenderWindow* WINDOW, int* MAP) // Permet un rendu 2d de la map ( texture + sprite )
{

  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);

  int tilecount =-1;

  for (int y = 0; y < mapHeight ; y++) //double boucle pour permettant de parcourir toutes les cases du tableau map
  {
    for (int x = 0; x < mapWidth ;  x++)
    {
      tilecount++;
      int colonne = MAP[tilecount] % tilsetWidth; // Le resultat du modulo donne la colonne du sprite ( transforme un tableau 1D en 2D)
      int ligne = MAP[tilecount] / tilsetWidth; // Le resultat de la division euclidienne donne la ligne du sprite


      sprite.setPosition(x * spriteLar, y * spriteLon); // Position du sprite sur la carte
      sprite.setTextureRect(sf::IntRect(colonne * spriteLar , ligne * spriteLon, spriteLar, spriteLon)); // Position de la texture correspondant au sprite dans le fichier PNG

      WINDOW->draw(sprite); // Affiche les sprites avec leur texture
    }
  }
}

void Map::saveMap(int* MAP,const std::string FILENAME)
{
  ofstream myMap;
  myMap.open (FILENAME);
  myMap << "map["<< mapWidth*mapHeight <<"] = { \n";
  for(int i=0;i<mapWidth*mapHeight-2;i++)
  {
      myMap << MAP[i] << ",";
  }
  myMap << MAP[mapWidth*mapHeight-1];
  myMap << " } ";
  myMap.close();
}

void Map::loadMap(const std::string TILESETFILENAME, sf::RenderWindow* WINDOW, const std::string TXTFILENAME)
{
  this->setTexture(TILESETFILENAME,WINDOW,this->openMap(TXTFILENAME));
}
