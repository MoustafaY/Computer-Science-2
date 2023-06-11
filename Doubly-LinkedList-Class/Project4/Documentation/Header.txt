#pragma once
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INLCUDED
#include<iostream>
#include<ostream>
using namespace std;

class DList
{
public:
	typedef char Item;
	struct Node
	{
		Item data;
		Node* next;
		Node* back;
	};
	Node* first;
	Node* last;


	//constructor
	DList() 
	{
		first = NULL;
		last = NULL;
	}
	~DList();

	//modification member functions
	void append( Item&);
	void remove_last();


	//constant member functions
	bool empty();
	

	friend std::ostream& operator<<(std::ostream& out_s, const DList& L);

	//private member function
private:

	Node* get_node(const Item&, Node*,Node*);
	
};






#endif