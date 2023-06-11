#include"Header.h"
#include<iostream>
using namespace std;

void binary::make_empty()//function to re initialize a list
{
	destroy(root);
	root = NULL;
}

void binary::destroy(Node*& root)//function to recur and remove all items in a list
{
	if (root != NULL)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

int binary::find_length(Node* root)//funciton to recur and count the length of a list
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return find_length(root->left) + 1 + find_length(root->right);
	}
}

void binary::heap_insert(Node*& t, Item entry)//function to recur and insert an item to the list
{
	if (t == NULL)
	{
		t = new Node;
		t->data = entry;
		t->left = NULL;
		t->right = NULL;
	}
	else if (entry < t->data)
	{
		heap_insert(t->left, entry);
	}
	else if(entry> t->data)
	{
		heap_insert(t->right, entry);
	}
}

void binary::find(Node*& t, Item target)//function to recur, find and remove an item in a list
{
	if (t->data == target)
	{
		remove_node(t);
	}
	else if (target < t->data)
	{
		find(t->left, target);
	}
	else if (target > t->data)
	{
		find(t->right, target);
	}
}

void binary::remove_node(Node*& t)//function to remove and re organize a list in order to not lose its order of values
{
	Node* ptr;
	Node* back;
	if (t->left == NULL && t->right == NULL)
	{
		delete t;
		t = NULL;
	}
	else if (t->left == NULL)
	{
		ptr = t;
		t = t->right;
		delete ptr;
	}
	else if (t->right == NULL)
	{
		ptr = t;
		t = t->left;
		delete ptr;
	}
	else
	{
		back = t;
		ptr = t->right;
		while (ptr->left != NULL)
		{
			back = ptr;
			ptr = ptr->left;
		}
		t->data = ptr->data;
		if (back == t)
		{
			remove_node(back->right);
		}
		else
		{
			remove_node(back->left);
		}
	}
}

void binary::printer(Node* b)//function to recur and print all the items in a list
{
  
	if (root != NULL)
	{
		if (b->left != NULL)
		{
			printer(b->left);
		}
		cout << b->data << " ";
		if (b->right != NULL)
		{
			printer(b->right);
		}

    }


}

void binary::print()//function to print a list
{
	cout << "--> ";
	printer(root);
	cout << endl;
}

bool binary::present(Item target)//function to search for and item in a list
{
	return r_present(target, root);
}

bool binary::r_present(Item target, Node* r)//function to recur and search for an item in a list
{
	if (r!=NULL)
	{
		if (target == r->data)
		{
			return true;
		}
		else if (target < r->data)
		{
			r_present(target, r->left);
		}
		else if (target > r->data)
		{
			r_present(target, r->right);
		}
	}
	else
	{
		return false;
	}
}