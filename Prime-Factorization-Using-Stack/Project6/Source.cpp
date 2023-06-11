#include"Header.h"
#include<iostream>
using namespace std;

void stack::push(Item entry)
{
	Node* temp;
	temp = new Node;
	temp->data = entry;
	temp->next = top;
	top = temp;
	size++;
}

stack::Item stack::pop()
{
	Item popped;
	Node* temp;
	popped = top->data;
	temp = top;
	top = top->next;
	delete temp;
	size--;
	return popped;
}

ostream& operator <<(ostream& outs, stack& s) {

	while (s.empty() == false) {

		while (s.sizE() != 1) {
			outs << s.pop() << " x ";
		}
		if (s.sizE() == 1) {
			outs << s.pop();
		}
	}
	return outs;
}