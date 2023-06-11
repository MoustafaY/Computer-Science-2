#include"Header.h"
#include<iostream>
#include<fstream>
using namespace std;

void binary::destroy(Node* root)//function to delete items in binary tree
{
	if (root != NULL)//if node is not null
	{
		destroy(root->left);//recur function to start with left node
		destroy(root->right);//recur function to start with right node
		delete root;//delete the current node
	}
}
//precondition: root of binary tree to be deleted
//postcondition: binary tree will be deleted

binary::Node* binary::r_build(istream& in_s)//function to build binary tree
{
	char ch;//character variable to hold items in the file
	Node* temp;//pointer to hold the item in the tree
	in_s >> ch;//a character is read from the input file
	if (isdigit(ch))//if character is an integer
	{
		temp = new Node;// a new node is created 
		temp->operand = ch - '0';//the character is turned into an integer and is held in the node
		temp->left = NULL;//left node becomes null
		temp->right = NULL;//right node becomes null
	}
	else//if character is not an integer
	{
		temp = new Node;//a new node is created
		temp->left = r_build(in_s);//recur function to return to the left node
		in_s >> temp->optr;//the operator is held in binary tree
		temp->right = r_build(in_s);//recur function to return to the right node
		in_s >> ch;//the character is held in the binary tree
	}
	return temp;//returns the temp node
}
//precondition:the file that has the input data
//postcondition:a binary tree is created with the data in the file

void binary::r_infix(Node* r)//function to print the data in binary tree in infix form
{
	if (r->left == NULL)//if left node is null
	{
		cout << r->operand;//print the integer
	}
	else
	{
		cout << "(";
		r_infix(r->left);//recur function to the left node
		cout << r->optr;//print the sign
		r_infix(r->right);//recur function to the right node
		cout << ")";
	}
	
}
//precondition: node that will be compared
//postcondition: the expression will be printed in infix form

void binary::r_prefix(Node* r)//function to print data in binary tree in prefix form
{
	if (r->left == NULL)//if left node is null
	{
		cout << r->operand<<" ";//print the integer
	}
	else
	{
		cout << r->optr<<" ";//print the sign
		r_prefix(r->left);//recur the function to the left node
		r_prefix(r->right);//recur the function to the right node
	}
}
//precondition: node that will be compared
//postcondition: exoression will be printed in prefix form

void binary::r_postfix(Node* r)//function to print data from binary tree in postfix form
{
	if (r->left == NULL)//if left node is null
	{
		cout << r->operand<<" ";//print integer
		
	}
	else
	{
		r_postfix(r->left);//recur function to the left node
		r_postfix(r->right);//recur function to the right node
		cout << r->optr << " ";//print the sign
	}
}
//precondition: node that will be compared
//postcondition: expression will be printed in postfix form

int binary::r_value(Node* r)//function to calculate the value of the expression in the binary tree
{
	int val1, val2;//val1 hold the left integer, val2 holds the right integer

	if (r->left == NULL)//if left node is null
	{
		return r->operand;//return the integer
	}
	else
	{
		val1 = r_value(r->left);//recur function to left node and return to val1
		val2 = r_value(r->right);//recur function to right node and return to val2

		if (r->optr == '+')//if sign is +
		{
			return val1 + val2;
		}
		else if (r->optr == '*')//if sign is *
		{
			return val1 * val2;
		}
		else if (r->optr == '-')//if sign is -
		{
			return val1 - val2;
		}
		else if (r->optr == '/')//if sign is /
		{
			return val1 / val2;
		}
	}
}