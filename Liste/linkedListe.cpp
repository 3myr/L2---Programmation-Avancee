#include "linkedListe.h"


using namespace std;

// Constructeur

/**
 * \brief Construction  de la liste vide
*/
template <class T>
linkedListe<T>::linkedListe()
{

  list = NULL;
  lvar = NULL;
  sizeList = 0;
}

/**
 * \brief Ajoute un element dans la liste
 *
*/
template <class T>
void linkedListe<T>::ajouter(T* v)
{

  //Creation de la liste à insérer dans la liste principale
  Liste<T>* val = new Liste<T>;
  val->suivant = NULL;
  val->premier = v;

  if ( list != NULL )
  {
    lvar = list;

    while( lvar->suivant != NULL )
    {
      lvar = lvar->suivant;
    }

    //On ajoute la liste contenant notre element à la fin
    lvar->suivant = val;
  }

  else{

    list = val;
  }

  sizeList++;
}

/**
 * \brief Supprime un Vaisseau a un indice passé en parametre
 *
*/
template <class T>
void linkedListe<T>::supprimer(int i)
{

  if ( list == NULL )
  {
    cout << "Impossible de supprimer un élément d'une liste vide !\n";
    exit(EXIT_FAILURE);
  }

  lvar = list;
  Liste<T>* lisTmp = lvar;
  Liste<T>* listDel = lvar;   // Liste a supprimer


  //On cherche à atteindre la position i
  while( i > 0 && lvar->suivant != NULL )
  {
    lisTmp = lvar;
    lvar = lvar->suivant;
    i--;
  }

  // Copie par référence la la liste a supprimé
  listDel = lvar;

  // "Sauvegarde" le reste de la liste principâle
  lvar = lvar->suivant;

  // "Sauvegarde" les éléments qui précédent l'élement qu'on supprime
  lisTmp->suivant = lvar;

  // Cas ou l'element a supprimer est au debut de la liste
  if ( listDel == list )
  {
    list = list->suivant;
    lisTmp = NULL;
    delete lisTmp; // Libere memoire de la liste temporaire
  }

  listDel = NULL;
  delete listDel; // Libere memoire
  sizeList--;
}

/**
 * \brief Retourne un Vaisseau situé a un indice passé en paramètre
 *
*/
template <class T>
T* linkedListe<T>::get(int i)
{

  if ( list == NULL )
  {
    cout << "Impossible de retourner un élément d'une liste vide !\n";
    exit(EXIT_FAILURE);
  }

  lvar = list;

  while( i > 0 && lvar->suivant != NULL)
  {
    lvar = lvar->suivant;
    i--;
  }

  return lvar->premier;
}

/**
 * \brief Retourne la taille de la liste
 *
*/
template <class T>
int linkedListe<T>::size()
{

  return sizeList;
}


/**
 * \brief Libere la liste passé en paramètre
*/
template <class T>
void linkedListe<T>::libererListe(Liste<T>* L)
{

  if ( L != NULL )
  {
    libererListe( L->suivant );
    delete L;
  }
}

/**
 * \brief Libere toute la liste
*/
template <class T>
void linkedListe<T>::free()
{

  libererListe(list);
  libererListe(lvar);
}
