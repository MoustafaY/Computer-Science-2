#include<iostream>
#include"Header.h"
using namespace std;

void menu(char);//function to manage the menu
//Precondition: a character that represents what the user wants
//Postcondition: a list is made,removed or re organized depending on what the user wants
int var;//an integer to hold any items the user wants to search,add or remove within a list
binary b;//the list in which the items will be organized in

int main()
{
	char ans;//a character that will hold the user's inputs
	

	cout << "This program responds to commands the user enters to ";
	cout << "manipulate an ordered list of integers, which is ";
	cout << "initially empty.In the following commands, v is any integer. " << endl;

	cout << "e -- Re-initialize the list to be empty." << endl;
	cout << "i v -- Insert the value v into the list." << endl;
	cout << "r v -- Remove the value v from the list." << endl;
	cout << "l -- Report the length of the list." << endl;
	cout << "p v -- Is the value v present in the list?" << endl;
	cout << "w -- Write out the list." << endl;
	cout << "h -- See this menu." << endl;
	cout << "q -- Quit." << endl;

	do//loop that will continue as long as the user does not type q
	{
		cout << "--> ";
		cin >> ans;
		menu(ans);//function menu() is called to manage the list depending on the inputs of the user

	} while (ans != 'q');

	if (ans == 'q')//program ends if the user enters q
	{
		return 0;
	}
}

void menu(char ans)//this function will manage the list
{
	bool found = false;//boolean to hold the value of whether or not an item is found in the list
	if (ans == 'e')//if the user enters e then the list will be re initialized with 0 values in it
	{
		cout << "List is re inititalized." << endl;
		b.make_empty();
	}
	else if (ans == 'i')//if the user enters i then a number then that number will be added to the list
	{
		cin >> var;
		cout << "Number " << var << " is inserted. " << endl;
		b.insert(var);
	}
	else if (ans == 'r')//if the user enters r then a number than that number will be deleted from the list
	{
		cin >> var;
		cout << "Number " << var << " is removed. " << endl;
		b.remove(var);
	}
	else if (ans == 'l')//if the user enter l then the program will print the number of integers in the list
	{
		cout << "The list contains " << b.length() << " values." << endl;
	}
	else if (ans == 'p')//if the user enters p then a number then the program will search for that numeber
	{
		cin >> var;
		found = b.present(var);
		if (found)
		{
			cout << "The value " << var << " is present. " << endl;
		}
		else if(!found)
		{
			cout << "The value "<<var<<" is not present. " << endl;
		}
	}
	else if (ans == 'w')//if the user enters w then the program will prints the contents of the list in order
	{
		cout << "The list: ";
		b.print();

	}
	else if(ans=='h')//if the user enters h then the program will print the menu again
	{
		cout << "e -- Re-initialize the list to be empty." << endl;
		cout << "i v -- Insert the value v into the list." << endl;
		cout << "r v -- Remove the value v from the list." << endl;
		cout << "l -- Report the length of the list." << endl;
		cout << "p v -- Is the value v present in the list?" << endl;
		cout << "w -- Write out the list." << endl;
		cout << "h -- See this menu." << endl;
		cout << "q -- Quit." << endl;
	}
	else if(ans=='q')//if the user enter q then the program will exit the program
	{
		cout << "Exit program." << endl;
	}
	else//if the user enters anything else then the program will print invalid input
	{
		cout << "Invalid input" << endl;
	}
}