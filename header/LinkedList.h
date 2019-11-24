#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;
#include <iostream>
#include <assert.h>

template <class T>
struct Node
{
    T val;
    Node<T>* next;
};

template <class T>
class LinkedList
{
  private:
      Node<T>* first;
      Node<T>* last;

  public:
      LinkedList();
      ~LinkedList();

      void insertAtBack(T valueToInsert);
      void insertAtFront(T valueToInsert);
      bool removeFromBack();
      bool isEmpty();
      int size();
      void clear();

      bool removeFromFront();
      T& get();
      T& get(int index);
};

#endif
