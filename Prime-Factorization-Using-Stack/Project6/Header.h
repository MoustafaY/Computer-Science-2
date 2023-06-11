#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED
#include<iostream>
using namespace std;

class stack
{
public:
	typedef int Item;
	//constructor
	stack() { top = NULL; size = 0; }

	//Modification member functions
	void push(Item entry);//Adds new item when called, item is added to the top of the list
	//Postcondition: A new item is placed on top of the list

	Item pop();//returns an item from the top of the list
	//Postcondition: Item has been returned and the number of items in the list has decreased by 1


	//Constant member functions
	int sizE() { return size; }
	bool empty() { return top == NULL; }
	

	//friend function
	friend ostream& operator << (ostream& outs, stack& s);

private:
	struct Node
	{
		Item data;
		Node* next;
	};
	Node* top;
	int size;
};



#endif
