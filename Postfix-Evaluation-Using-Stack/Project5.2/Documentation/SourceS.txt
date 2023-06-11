#include "HeaderS.h"
#include<iostream>
using namespace std;

void stack::push(Item entry)
{
	data[used] = entry;
	used++;
}

stack::Item stack::pop()
{
	used--;
	return data[used];
}

