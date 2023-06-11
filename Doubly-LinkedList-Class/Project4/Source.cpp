#include "Header.h"
#include <iostream>

using namespace std;

DList:: ~DList()
{
	Node* temp;
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}

void DList::append( Item& entry)
{
	if (first == NULL)
	{
		cout << "is null" << endl;
		first = new Node;
		first->data = entry;
		first->next = NULL;

	}
	else
	{
		Node* prev= first;
		while (prev->next!=NULL)
		{
			prev = prev->next;
		}
		prev->next = get_node(entry, prev->next, prev);
		prev->next->next->back = prev->next;
	}
}

void DList::remove_last()
{
	last->back->next = NULL;
	last = last->back;
}


bool DList:: empty()
{
	bool flag = false;
	if (first == NULL)
	{
		flag = true;
	}
	return flag;
}

DList::Node* DList::get_node(const Item& entry, Node* forward, Node* backward)
{
	Node* temp;
	temp = new Node;
	temp->data = entry;
	temp->next = forward;
	temp->back = backward;
	return temp;
}

ostream& operator<<(ostream& out_s, const DList& L)//function that overload the "<<" operator to print the items within a list
{
	DList::Node* p;
	p = L.first;//p Node becomes equal to the first Node of the input list

	while (p != NULL)//this loop will continue as long as the p Node is not NULL
	{
		out_s << p->data << " ";//prints the integer in the p Node
		p = p->next;//p Node moves to the Node next to it
	}
	return out_s;
}