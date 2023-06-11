#include"Header.h"
#include<iostream>
using namespace std;

void Queue::enqueue(Item entry)
{
	Node* temp;
	temp = new Node;
	temp->data = entry;
	temp->next = NULL;

	if (front == NULL)
	{
		front = temp;
		count++;
	}
	else
	{
		rear->next = temp;
		count++;
	}
	rear = temp;
	
}

Queue::Item Queue::dequeue()
{
	Node* temp;
	Item it;
	it = front->data;
	temp = front;
	front = front->next;
	delete temp;
	if (front == NULL)
	{
		rear = NULL;
	}
	count--;
	return it;
}

ostream& operator<<(ostream& out_s, const Queue& L)//function that overload the "<<" operator to print the items within a list
{
	Queue::Node* p;
	p = L.front;//p Node becomes equal to the front Node of the input list

	while (p != NULL)//this loop will continue as long as the p Node is not NULL
	{
		out_s << p->data << " ";//prints the integer in the p Node
		p = p->next;//p Node moves to the Node next to it
	}
	return out_s;
}