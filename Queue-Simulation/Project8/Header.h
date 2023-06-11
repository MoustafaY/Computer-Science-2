#pragma once
#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED
#include<iostream>
using namespace std;

class Queue
{
public:
	typedef int Item;

	//constructor
	Queue()
	{
		front = NULL;
		rear = NULL;
		count = 0;
	}

	//deconsturctor
	~Queue()
	{
		Node* temp;
		while (front != NULL)
		{
			temp = front;
			front = front->next;
			delete temp;
		}
	}

	//modification member function
	void enqueue(Item entry);
	Item dequeue();

	//constant member function
	int length() { return count; }
	bool empty() { return front == NULL; }


	//friend function
	friend ostream& operator <<( ostream& out_s,const Queue& q);

private:
	struct Node
	{
		Item data;
		Node* next;
	};
	Node* front;
	Node* rear;
	int count;
};


#endif