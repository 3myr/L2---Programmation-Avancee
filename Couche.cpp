#include "header/Couche.h"

// Methode constructive -----------------------------------------------------
/**
* \brief Instancie une couche
*/
Couche::Couche()
{

}

/**
* \brief Instancie une couche
*/
Couche::Couche(const std::string FILENAME,int NbLigneInTxt)
{
  // Gere les ereurs quand les champs dans le fichier txt ne sont pas corrects
  try
  {
    this->loadVar(FILENAME,NbLigneInTxt);
    this->openMap(FILENAME,NbLigneInTxt);
  }
  catch(std::exception const& e)
  {
    cout<<"CHAMP INCORRECT, MODIFIER LE FICHIER TXT !"<<endl;
    exit(EXIT_FAILURE);
  }
}

// ---------------------------------------------------------------------------






//Fonctions d'observations ---------------------------------------------------

/**
* \brief
*/
float Couche::getWitdh()
{
 return texture.getSize().x;
}

/**
* \brief
*/
float Couche::getHeight()
{
  return texture.getSize().y;
}

/**
* \brief
*/
sf::Texture Couche::getTexture()
{
  return texture;
}

/**
* \brief
*/
sf::Sprite Couche::getSprite()
{
  return sprite;
}

/**
* \brief Charge une map en fonction des données d'un fichier texte
*/
void Couche::openMap(const std::string FILENAME,int NbLigneInTxt)
{

  //Allocation de mémoire pour les tableaux stockant les valeurs des variables du fichier .txt
  string* line;
  line = new string[NbLigneInTxt];
  int nbSprite;

  // Ouverture du fichier et recupération des lignes dans un tableau ( tmp )
  ifstream myfile2 (FILENAME);

  if (myfile2.is_open())
  {
    for(int k=0;k<NbLigneInTxt-1;k++) // Permet de charger les lignes dans un tableau
    {
      getline (myfile2,line[k],'=');
      getline (myfile2,line[k],' ');
      getline (myfile2,line[k],';');
    }

    getline(myfile2,line[NbLigneInTxt-1],'"'); // Permet de ne prendre que la valeur de la variable
    getline(myfile2,line[NbLigneInTxt-1],'"');

    // Affectation des valeurs dans leur variable

    //Recupere le chemin d'acces de la texture
    tileSetTextureName = line[6];


    getline(myfile2,line[NbLigneInTxt-1],'['); // Permet de ne prendre que la valeur de la variable
    getline(myfile2,line[NbLigneInTxt-1],']');

    //Initialisation de int* map
    nbSprite = stod(line[6]);
    map = (int*)malloc(nbSprite * sizeof(int));

    getline(myfile2,line[NbLigneInTxt-1],'{');
    getline(myfile2,line[NbLigneInTxt-1],' ');


    for(int i=0;i<nbSprite;i++)
    {
      getline(myfile2,line[NbLigneInTxt-1],',');
      map[i] = stod(line[NbLigneInTxt-1]);
    }

    myfile2.close();

  }
  else
  {
    cout << "Impossible d'ouvrir le fichier";
  }

  // Affectation des valeurs dans leur variable

  height = stod(line[0]);
  width = stod(line[1]);
  spriteLarg = stod(line[2]);
  spriteLong = stod(line[3]);
  tileSetWidth = stod(line[4]);
  tileSetHeight = stod(line[5]);

  delete [] line;

}

// ---------------------------------------------------------------------------







//Fonctions de transmorfations -----------------------------------------------

/**
* \brief Charge les informations relative a une couche avec des informations contenu dans un txt
*/
void Couche::loadVar(const std::string FILENAME,int NbLigneInTxt)
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
void Couche::setTexture()
{
  sprite.setTexture(texture);
  //sprite.setPosition(x,y);
}

/**
* \brief
*/
void Couche::setTextureTileSet()
{
  tileSetTexture.loadFromFile(tileSetTextureName);
  tileSetSprite.setTexture(tileSetTexture);
}

/**
* \brief
*/
void Couche::drawMap(sf::RenderWindow* WINDOW)
{
  int tilecount =-1;

  for (int y = 0; y < height ; y++) //double boucle pour permettant de parcourir toutes les cases du tableau map
  {
    for (int x = 0; x < width ;  x++)
    {
      tilecount++;
      int colonne = map[tilecount] % tileSetWidth; // Le resultat du modulo donne la colonne du sprite ( transforme un tableau 1D en 2D)
      int ligne = map[tilecount] / tileSetWidth; // Le resultat de la division euclidienne donne la ligne du sprite


      tileSetSprite.setPosition(x * spriteLarg, y * spriteLong); // Position du sprite sur la carte
      tileSetSprite.setTextureRect(sf::IntRect(colonne * spriteLarg , ligne * spriteLong, spriteLarg, spriteLong)); // Position de la texture correspondant au sprite dans le fichier PNG

      WINDOW->draw(tileSetSprite); // Affiche les sprites avec leur texture
    }
  }
}

/**
* \brief
*/
void Couche::free()
{
  delete [] map;
}

// ---------------------------------------------------------------------------
