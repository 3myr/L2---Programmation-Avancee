#include "header/Animation.h"

// Methode constructive
Animation::Animation()
{
  frameDuration = 100;
  counterWalking = 0;
}

// Fonctions d'observations
int Animation::getFrameDuration() const
{
  return frameDuration;
}

int Animation::getCounterWalking() const
{
  return counterWalking;
}


// Fonctions de transformations
void Animation::setFrameDuration(int FRAMEDURATION)
{
  frameDuration = FRAMEDURATION;
}

void Animation::setCounterWalking(int COUNTERWALKING)
{
  counterWalking = COUNTERWALKING;
}


void Animation::setCounterWalkingAdd1()
{
  counterWalking = counterWalking+1;
}

void Animation::setCounterWalkingAt0()
{
  counterWalking = 0;
}

void Animation::durationAnimation(int* ANIMATIONCOUNTER,Player PLAYER)
{
  //cout << *counterWalking << endl;

  if (*ANIMATIONCOUNTER >= PLAYER.getFrameDuration()) // Comparaison pour savoir si l'on passe au sprite suivant de l'animation
  {
    *ANIMATIONCOUNTER =0;
    counterWalking++;
    if (counterWalking == 6) // Permet de choisir le bon sprite pour que l'animation soit fluide et cohérente
    {
      counterWalking = 0;
    }
  }
}
