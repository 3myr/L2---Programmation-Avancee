#ifndef LINKEDLISTE_H
#define LINKEDLISTE_H

#include <iostream>

template <class T>
struct Liste{

    T* premier;
    Liste<T>* suivant;
};

template <class T>
class linkedListe{

    private:

    // Liste principale
    Liste<T>* list;

    // Liste temporaire
    Liste<T>* lvar;

    // Taille de la liste
    int sizeList;


    public:

    //Constructeur
    linkedListe();

    // Fonctions d'observations
    T* get( int i );
    int size();

    // Fonctions de transformations
    void ajouter( T* v );
    void supprimer( int i );
    void libererListe( Liste<T> L );
    void free();

};

#endif
