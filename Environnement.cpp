#include "Environnement.h"

// Methode constructive
Environnement::Environnement()
{
}

// Fonctions d'obversations
int Environnement::getMapWitdh() const
{
  return mapWidth;
}

int Environnement::getMapHeight() const
{
  return mapHeight;
}

int Environnement::getSpriteLar() const
{
  return spriteLar;
}

int Environnement::getSpriteLon() const
{
  return spriteLon;
}

sf::Texture Environnement::getTexture() const
{
  return texture;
}

sf::Sprite Environnement::getSprite() const
{
  return sprite;
}

int *Environnement::getMap() // On utilise un pointeur pour retourner l'adresse du tableau ( pas sur du fonctionnement )
{
  return map;
}



// Fonctions de transformations
void Environnement::setMapWitdh(int WIDTH)
{
  mapWidth = WIDTH;
}

void Environnement::setMapHeight(int HEIGHT)
{
  mapHeight = HEIGHT;
}

void Environnement::setSpriteLar(float LARGEUR)
{
  spriteLar = LARGEUR;
}

void Environnement::setSpriteLon(float LONGUEUR)
{
  spriteLon = LONGUEUR;
}

void Environnement::setTexture(const std::string FILENAME, sf::RenderWindow* WINDOW, int* map) // Permet un rendu 2d de la map ( texture + sprite )
{

  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
  int tilecount =-1;

  for (int y = 0; y < mapHeight ; y++)
  {
    for (int x = 0; x < mapWidth ;  x++)
    {
      tilecount++;
      int colonne = map[tilecount] % tilsetWidth; // Le resultat du modulo donne la colonne du sprite ( transforme un tableau 1D en 2D)
      int ligne = map[tilecount] / tilsetWidth; // Le resultat de la division euclidienne donne la ligne du sprite


      sprite.setPosition(x * spriteLar, y * spriteLon); // Position du sprite sur la carte
      sprite.setTextureRect(sf::IntRect(colonne * spriteLar , ligne * spriteLon, spriteLar, spriteLon)); // Position de la texture correspondant au sprite dans le fichier PNG

      WINDOW->draw(sprite); // Affiche les sprites avec leur texture
    }
  }
}
