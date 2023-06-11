
#ifndef HEADERS_INCLUDED
#define HEADERS_INCLUDED
#include<iostream>
using namespace std;

class stack
{
public:
	static const int cap = 100;
	typedef char Item;

	stack() { used = 0; }//constructor

	void push(Item entry);//adds new item when called, item is pushed to the top of the list
	//Postcondition: Item in parameter has been added to the top of the list or stack

	Item pop();//returns the item in the top of the list or stack
	//Postcondition: Item has been returned and the number of items in the list has decreased by 1




private:
	Item data[cap];
	int used;

};


#endif
