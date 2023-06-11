#pragma once
#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED
#include<iostream>
using namespace std;

class queue
{
public:
	typedef int Item;
	static const int capacity = 100;

	//constructor
	queue();

	//Modification member functions
	int size() { return count; }
	bool empty() { return count == 0; }
	void enqueue(Item entry);
	Item dequeue();

	//friend function
	friend ostream& operator <<(ostream& out, queue q);

private:
	Item data[capacity];
	int front;
	int rear;
	int count;
	int next_index(int i)
	{
		return (i + 1) % capacity;
	}

};



#endif