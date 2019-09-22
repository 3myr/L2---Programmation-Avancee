#include "header/Moving.h"

// Methode constructive
Moving::Moving()
{
}

// Fonctions d'observations

// Fonctions de transformations
void Moving::getCounterWalking(int* ANIMATIONCOUNTER,Player PLAYER,Animation* ANIMATION)
{
  //cout << *counterWalking << endl;

  if (*ANIMATIONCOUNTER >= PLAYER.getFrameDuration()) // Comparaison pour savoir si l'on passe au sprite suivant de l'animation
  {
    *ANIMATIONCOUNTER =0;
    ANIMATION->setCounterWalkingAdd1();
    cout << ANIMATION->getCounterWalking() << endl;

    if (ANIMATION->getCounterWalking() == 6) // Permet de choisir le bon sprite pour que l'animation soit fluide et cohérente
    {
      ANIMATION->setCounterWalkingAt0();
    }
  }
}
