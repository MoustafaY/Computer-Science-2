#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED
#include<iostream>
using namespace std;

class binary
{
public:

	typedef int Item;
	//constructor
	binary() { root = NULL; }
	//deconstructor
	~binary() { destroy(root); }
	//member functions
	void make_empty();
	bool empty() { return root == NULL; }
	void insert(Item entry) { heap_insert(root, entry); }
	void remove(Item target) { find(root, target); }
	//constant member functions
	bool present(Item root);
	int length() { return find_length(root); }
	void print();
	
	
private:

	struct Node
	{
		Item data;
		Node* left;
		Node* right;
	};
	Node* root;

	void destroy(Node*& r);//to recur and remove items
	int find_length(Node* r);//to recur and count the number of functions
    bool r_present(Item target, Node* root);//to recur and search for an item
	void heap_insert(Node*& t, Item entry);//to recur and add an item to the list
	void find(Node*& t, Item target);//to find and item 
	void remove_node(Node*& t);//to recur and remove items
	void printer( Node* b);//to recur and print items in the list in order
};



#endif 