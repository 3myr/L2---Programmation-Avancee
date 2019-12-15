#ifndef VIEW_H
#define VIEW_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class View
{

  protected:

    sf::View mainView;

    int width;
    int height;

    float speed;


  public:

  // Constructeurs
  View();
  View(const std::string FILENAME,int NbLigneInTxt);


  // Fonctions d'observations
  sf::View getView();
  float getWidth() const;
  float getHeight() const;
  float getCenter() const;
  float getSpeed();

  // Fonctions de transformations
  void loadVar(const std::string FILENAME,int NbLigneInTxt);
  void setWidth(int VIEWWIDTH);
  void setHeight(int VIEWHEIGHT);
  void setView(sf::View VIEW);
  void movingView();


}
;
#endif
