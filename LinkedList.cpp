#include "header/LinkedList.h"

/**
* Methode constructice
*/
template <class T>
LinkedList<T>::LinkedList()
{
	first = NULL;
	last = NULL;
}

/**
* Methode destructice
*/
template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = first;
	while(temp != NULL)
	{
		temp = temp->next; // Stocke le reste de la liste dans une variables temporaire
		delete(first); // libère la mémoire du premier élément
		first = temp; // Le reste devient le premier élément
	}
}

/**
* Fonction permettant d'insérer un élément à la fin de la LinkedList
*/
template <class T>
void LinkedList<T>::insertAtBack(T valueToInsert)
{
  // Création du noeud contenant la valeur a stocker et son prochain élément si il en a un
	Node<T>* newNode;
	newNode->val = valueToInsert;
	newNode->next = NULL;

  // Permet de faire la liaison entre la valeur que l'on insert et la LinkedList actuelle
	Node<T>* temp = first;

  // On cherche quand ajouter le noeud avec la valeur ajouter ( ici a la fin de la LinkedList )
	if (temp != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

    // On effectue la liaison entre la LinkedList et l'élément à ajouter
		temp->next = newNode;
	}
	else // Cas dans lequel la LinkedList est vide
	{
		first = newNode;
	}
}

/**
* Fonction permettant d'insérer un élément au debut de la LinkedList
*/
template <class T>
void LinkedList<T>::insertAtFront(T valueToInsert)
{
	Node<T>* newNode;

	newNode->val = valueToInsert;

  	 if(first == NULL)
   	{
   		first = newNode;
   	}
   	else
   	{
   		newNode->next = first;
   		first = newNode;
   	}
}

/**
* Fonction permettant de supprimer un élément situé à la fin de la LinkedList
*/
template <class T>
bool LinkedList<T>::removeFromBack()
{
  // Cas ou la LinkedList est vide
	if (first == NULL && last == NULL)
  {
    return false;
  }

  // Cas ou il n'y a qu'un seul élément dans notre LinkedList
	if (first == last)
	{
		delete(first);
		first = NULL;
    last = NULL;
		return true;
	}

	else
	{
		Node<T>* temp = first; // Stocke le premier élément dans une variable temporaire
		int nodeCount = 0; // Permet de connaitre le nombre d'éléments présent dans notre LinkedList

    // Parcours la LinkedList jusqu'a trouver le dernier élément
		while (temp != NULL)
		{
			nodeCount = nodeCount + 1;
			temp = temp->next;
		}

		Node<T>* temp2 = first;

    // Recupere l'avant dernier élément dans une variables temporaire
		for(int i = 1; i < (nodeCount - 1); i++)
		{
			temp2 = temp2->next;
		}

    // Libère l'allocations mémoire du dernier élément ( celui a supprimer )
		delete(temp2->next);

    // Faire pointer Last sur Temp2
		last = temp2;
		last->next = NULL; // Supprime la référence de l'avant dernier élément pour qu'il devienne le dernier élément

		return true;
	}
}

/**
* Fonction permmettant de savoir si une LinkedList est vide
*/
template <class T>
bool LinkedList<T>::isEmpty()
{
	if (first == NULL && last == NULL)
  {
    return true;
  }
	else
  {
    return false;
  }
}

/**
* Fonction permettant de connaitre la taille de la LinkedList ( le nombre d'éléments présent a l'intérieur )
*/
template <class T>
int LinkedList<T>::size()
{
	if (first == NULL && last == NULL)
  {
    return 0;
  }
	Node<T>* temp = first;
	int nodeCounter = 0;

  // Parcours la LinkedList jusqu'a trouver le dernier élément
	while (temp != NULL)
	{
    // Probleme ici qui fait une boucle sans fin ( temp jamais NULL )
		nodeCounter = nodeCounter + 1;
		temp = temp->next;
    if(temp->next == NULL)
    {
      cout<<"temp est NULL"<<endl;
    }
	}
	return nodeCounter;
}

/**
* Fonction permettant libérer l'allocation mémoire occupé par toute la LinkedList
*/
template <class T>
void LinkedList<T>::clear()
{
	Node<T>* temp = first; // Recupere le premier élément de la liste dans une variable temporaire
	while(temp != NULL)
	{
		temp = temp->next;
		first = temp;
		delete(temp);
	}
}

/**
* Fonction permettant de supprimer un élément situé au début de la LinkedList
*/
template <class T>
bool LinkedList<T>::removeFromFront()
{
	if (first == NULL && last == NULL)
  {
    return false;
  }

	else
	{
		Node<T>* temp;

		temp = first;
		first = first->next;

		delete(temp);

		return true;
	}
}

/**
* Fonction permettant de récuperer le premier élément de la LinkedList
*/
template <class T>
T& LinkedList<T>::get()
{
	return first->val; // Retourne l'élément situé au début de la LinkedList
}

/**
* Fonction permettant de récuperer un élément de la LinkedList
*/
template <class T>
T& LinkedList<T>::get(int index)
{
  Node<T>* temp;
  int nodeCounter = 0;
  temp = first;

  while(temp != NULL)
  {
    if(nodeCounter == index)
    {
      return temp->val;
    }
    nodeCounter++;
    temp = temp->next;
  }
  assert(0); // Retourne une erreur quand l'élement n'est pas trouvé
}
