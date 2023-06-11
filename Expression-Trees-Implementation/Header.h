#pragma once
#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED
#include<iostream>
#include<fstream>
using namespace std;

class binary
{
public:
	//constructor
	binary() { root = NULL; }
	//deconstructor
	~binary() { destroy(root); }
	//modification member functions
	void value() { cout << r_value(root) << endl; }
	void build(istream& in_s) { destroy(root); root = r_build(in_s); }
	//constant member functions
	void infix() { r_infix( root); }
	void prefix() { r_prefix(root); }
	void postfix() { r_postfix(root); }
	
private:
	struct Node
	{
		char optr;
		int operand;
		Node* left;
		Node* right;
	};
	Node* root;
	Node* r_build(istream& );
	void destroy(Node* r);
	void r_infix(Node* r);
	void r_prefix(Node* r);
	void r_postfix(Node* r);
	int r_value(Node* r);
};



#endif