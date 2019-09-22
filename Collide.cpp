#include "header/Collide.h"

// Methode constructive
Collide::Collide()
{
  mapWidth = 52;
  mapHeight = 60;
  spriteLar = 24;
  spriteLon = 16;
  tilsetWidth = 28;
  tilsetHeight = 37;
  //map = (int*)malloc((mapWidth*mapHeight) * sizeof(int)); // Allocation de mapWidth*mapHeight mémoire de type int
}

// Fonctions d'observations
int Collide::getTile(float X, float Y) const
{
  int playerTileX = (int)X/spriteLar;
  int playerTileY = (int)Y/spriteLon;
  int spriteNumber = mapWidth*playerTileY+playerTileX;
  return spriteNumber;
}
// Fonctions de transformations
void Collide::collision(Player* PLAYER)
{
  //if(map[this->getTile(PLAYER->getX(),PLAYER->getY())]==1 || map[this->getTile(PLAYER->getX()+24,PLAYER->getY())]==1 || map[this->getTile(PLAYER->getX(),PLAYER->getY()+44)]==1 || map[this->getTile(PLAYER->getX(),PLAYER->getY()+21)]==1)
  if( map[this->getTile(PLAYER->getCoinEnBasAGaucheX(),PLAYER->getCoinEnBasAGaucheY())]==1 ||
      map[this->getTile(PLAYER->getCoinEnBasADroiteX(),PLAYER->getCoinEnBasADroiteY()+PLAYER->getSpeed())]==1 ||
      map[this->getTile(PLAYER->getCoinEnHautADroiteX(),PLAYER->getCoinEnHautADroiteY()-PLAYER->getSpeed())]==1 ||
      map[this->getTile(PLAYER->getCoinEnHautAGaucheX(),PLAYER->getCoinEnHautAGaucheY())]==1)

  {
    //PLAYER->setTexture("Character/bluerectangle.png");
    PLAYER->setCollisionPos(PLAYER->getOldX(),PLAYER->getOldY());
    /*
    if(PLAYER->getLookTop())
    {
      PLAYER->setCollisionBot(false);
      PLAYER->setCollisionTop(true);
      PLAYER->setCollisionLeft(false);
      PLAYER->setCollisionRight(false);
    }
    if(PLAYER->getLookBot())
    {
      PLAYER->setCollisionBot(true);
      PLAYER->setCollisionTop(false);
      PLAYER->setCollisionLeft(false);
      PLAYER->setCollisionRight(false);
    }
    if(PLAYER->getLookRight())
    {
      PLAYER->setCollisionBot(false);
      PLAYER->setCollisionTop(false);
      PLAYER->setCollisionLeft(false);
      PLAYER->setCollisionRight(true);
    }
    if(PLAYER->getLookLeft())
    {
      PLAYER->setCollisionBot(false);
      PLAYER->setCollisionTop(false);
      PLAYER->setCollisionLeft(true);
      PLAYER->setCollisionRight(false);
    }
    */
  }
  else
  {
    //PLAYER->setTexture("Character/redrectangle.png");
  }
}

void Collide::setTexture(const std::string FILENAME, sf::RenderWindow* WINDOW, int* MAP) // Permet un rendu 2d de la map ( texture + sprite )
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

int* Collide::openMap(const std::string FILENAME)
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

void Collide::loadMap(const std::string TILESETFILENAME, sf::RenderWindow* WINDOW, const std::string TXTFILENAME)
{
  this->setTexture(TILESETFILENAME,WINDOW,this->openMap(TXTFILENAME));
}
