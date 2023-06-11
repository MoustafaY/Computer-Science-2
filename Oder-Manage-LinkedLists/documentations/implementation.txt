#include "Header.h"
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

//copy constructor
List::List(const List& source)
{
	Node* p;//to hold the items in the list
	Node* Last;//points to last Node in the list

	if (source.first == NULL)//if the the list is empty
	{
		first = NULL;//the first Node becomes NULL
	}
	else
	{
		first = get_node(source.first->data, NULL);//copies the first Node
		Last = first;
		p = source.first->next;
		while (p != NULL)//Loop to copy the rest of the Nodes
		{
			Last->next = get_node(p->data, NULL);
			Last = Last->next;
			p = p->next;
		}

	}
}

List::~List()//Destuctor
{
	Node* temp;
	while (first != NULL)//loop that works as long as the first Node is not NULL
	{
		temp = first;//temporary Node becomes equal to the first Node
		first = first->next;//first Node moves the next Node and becomes it
		delete temp;//deletes temporay Node
	}
}

void List::insert(const Item& entry)//function to add a value to a list
//precondition: an integer
//postcondition: The integer has been added to the list
{
	Node* prev;

	if (first == NULL || entry < first->data)//if the first Node is NULL 
											 //or if the input value is less than the value of the first Node
	{
		first = get_node(entry, first);//adds the value to the be held by the first Node
	}
	else
	{
		
			prev = first;//make previous Node equals to the first Node
			while (prev->next != NULL && prev->next->data < entry)//loop that works as long as the Node after the previous Node is no NULL
				//and as long as the integer of the Node after the previous Node is less than the input integer
			{
				prev = prev->next;//previous Node is equal to the Node next to it
			}
			prev->next = get_node(entry, prev->next);	//add the integer to be held by the Node after the previous Node
		
	}
}

void List::insert( )//overloaded function to print the output list into an output file
//postcondition: the ouptut list is printed into the output file
{
	file.open(output);//opens file under the variable "ouput"
	Node* p;
	p = first;//p Node is equal to the first Node 
	while (p != NULL)//loop that works as long as the p Node is not NULL
	{
		file << p->data<<" ";//integer held by p Node is printed into the ouput file
		p = p->next;//p Node is equal to the Node next to it
	}
	cout << endl;
	file.close();//closes file 
}
List::Node* List::get_node(const Item& entry, Node* link)//function that creates a new Node and allocated an integer into it
//precondition: an integer variable and the List that we want to allocate this Node into
//postcondition: a new Node has been created that holds a new value and points to the next Node within a list
{
	Node* temp;
	temp = new Node;//temp pointer becomes a new Node
	temp->data = entry;//temp Node holds the input integer in it
	temp->next = link;//temp Node points to the next Node in the input list
	return temp;
}

size_t List::length()const//function to get the number of items in the list
//postcondition: return the number of integer within a list
{
	Node* p;
	size_t count;

	count = 0;
	for (p = first; p != NULL; p = p->next)//loop that will continue until p Node becomes NULL
	{
		count++;//count variable is incremented every time we move to the next Node
	}
	return count;
}

void List::merge(List& list1,List& list2)//function that merges two lists into one list
//precondition: the two lists we want to merge
//postcondition: the two lists become merged into one list
{
	Node* nexto;
	Node* prevo;
	Node* l1;
	Node* l2;
	bool flag;
	size_t num;

	nexto = new Node;

	l1 = list1.first;//l1 Node holds the first Node in List1
	l2 = list2.first;//l2 Node holds the second Node in list 2


	while (l1 != NULL && l2 != NULL)//Loop will continue to work until both l1 and l2 become NULL
	{

		if (l1->data <= l2->data)//if the integer in l1 Node is less than or equal to the integer in l2 Node
		{
			num = l1->data;//num variable holds the integer in l1 Node
			l1 = l1->next;//l1 becomes equal to the Node next to it
			flag = list1.found(num);//flag variable holds the boolean value returned by the found function
			if (flag == false)//if flag is equal to false
			{
				
				nexto->data = num;//nexto Node holds the integer value in the num variable
				list1.insert(num);//num variable is added to the list through the insert function
				
			}

		}

		else//if the integer in l1 Node is not less than or equal to the integer in l2 Node
		{
			num = l2->data;//num variable holds the integer in l2 Node
			l2 = l2->next;//l2 becomes equal to the next Node
			flag = list1.found(num);//flag variable holds the boolean value returned by the found function
			if (flag == false)//if flag is equal to false
			{
				nexto->data = num;//nexto Node holds the integer value in the num variable
				list1.insert(num);//num variable is added to the list through the insert function
		
			}
		}

		nexto->next = NULL;//the Node after the nexto Node becomes NULL

		if (l1->data >= l2->data)//if the integer in l1 Node is larger than or equal to the integer in l2 Node
		{
			num = l1->data;//num variable holds the intgeger in l1 Node
			l1 = l1->next;//l1 Node becomes equal to the Node next to it
			flag = found(num);//flag variable holds the boolean value returned by the found function
			if (flag == false)//if flag is equal to false
			{
				nexto->data = num;//nexto Node holds the integer value in the num variable
				insert(num);//num variable is added to the list through the insert function
			}
		}
		
		else//if the integer in l1 Node is not larger than or equal to the integer in l2 Node
		{
			num = l2->data;//num variable holds the integer value in the l2 Node
			l2 = l2->next;//l2 Node becomes equal to the Node next to it
			flag = found(num);//flag variable holds the returned boolean value of the found function
			if (flag == false)//if the flag variable is eqaul to false
			{
				nexto->data = num;//nexto Node holds the integer variable in the num variable
				insert(num);//num variable is added to the list through the insert function
			}
		}
		nexto->next = NULL;//the Node afer the nexto Node becomes NULL

		if (first == NULL)//if the first Node is NULL
		{
			first = nexto;//first Node becomed equal to the Nexto Node
		}
		else
		{
			prevo = new Node;//a new Node called prevo is created
			prevo->next = nexto;//prevo Node becomes the nexto Node
		}

	}

	list2.make_empty();//list2 becomes empty
}

bool List:: found(size_t item)//function to locate a similar integer
//precondition: an integer variable
//postcondition: a boolean value that is true if the same integer is found in a list
//and false if there was not the same variable in a list
{
	Node* p=first;//p Node is declared to be equal to first Node
	bool flag = false;

	while (p != NULL)//loop that continues as long as the p Node is not NULL
	{
		if (p->data == item)//if the integer in the p Node is equal to the input integer
		{
			flag = true;//flag becomes true
		}
		p = p->next;//p Node becomes equal to the next Node
	}
	return flag;
}

void List::make_empty()//funtion to make a list empty
//postcondition: there will be no items in that list
{
	Node* temp;
	
	while (first != NULL)//loop that will continue as long as the first Node is not NULL
	{
		temp = first;//temp Node becomes equal to the first Node
		first = first->next;//first Node becomes equal to the next Node
		delete temp;//deletes the temp Node
	}
}

ostream& operator<<(ostream& out_s,const List& L)//function that overload the "<<" operator to print the items within a list
{
	List::Node* p;
	p = L.first;//p Node becomes equal to the first Node of the input list

	while(p!=NULL)//this loop will continue as long as the p Node is not NULL
	{
		out_s << p -> data << " ";//prints the integer in the p Node
		p = p ->next;//p Node moves to the Node next to it
	}
	return out_s;
}