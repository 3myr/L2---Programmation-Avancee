#include <iostream>
#include <string>

using namespace std;

template <class T>
class otherLinkedList
{
private:
	struct node
	{
		T data;
		node * next;
	} *head;

public:
	otherLinkedList();
	~otherLinkedList();
	void add(T d);
	void remove(T d);
	void clear();
	void display(const char* s);
};

template <class T>
otherLinkedList<T>::otherLinkedList()
{
	head = NULL;
}

template <class T>
otherLinkedList<T>::~otherLinkedList()
{
	node *p, *q;
	p = head;
	if(p == NULL) return;
	while(p) {
		q = p->next;
		delete p;
		p = q;
	}
}

template <class T>
void otherLinkedList<T>::add(T d)
{
	node *p, *q;
	if(head == NULL) {
		head = new node;
		head->data = d;
		head->next = NULL;
		return;
	}
	p = head;
	while(p->next != NULL)
		p = p->next;
	q = new node;
	q->data = d;
	q->next = NULL;
	p->next = q;
}

template <class T>
void otherLinkedList<T>::remove(T d)
{
	node *p, *q;
	if(head == NULL) return;
	p = head;
	while(p) {
		if(p->data == d) {
			q->next = p->next;
			delete p;
			return;
		}
		q = p;
		p = p->next;
	}
}

template <class T>
void otherLinkedList<T>::clear()
{
	node *p, *q;
	if(head == NULL) return;
	p = head;
	while(p) {
		q = p->next;
		delete p;
		if(q != head)  {
			head = NULL;
			return;
		}
		p = q;
	}
}

template <class T>
void otherLinkedList<T>::display(const char* s)
{
	node *p;
	if(head == NULL) return;
	p = head;
	while(p) {
		if(s == "string")
			cout << p->data << endl;
		else
			cout << p->data << ' ';
		p = p->next;
		if(p != NULL) {
			if(p == head) return;
		}
	}
	if(s == "integer") cout << endl;
}
