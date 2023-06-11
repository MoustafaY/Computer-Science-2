#include"Header.h"
#include<iostream>
#include<fstream>
using namespace std;
binary bst;

int main()
{
	ifstream file;//variable to hold the input file
	string name;//holds file name
	cout << "Insert file name: ";
	cin >> name;
	if (name == "input.txt")//if name of file is this one
	{
		file.open("input.txt");//open file

		while (file.peek() != EOF)//if the next character is not the end of the file
		{
			bst.build(file);//build a binary tree
			cout << "In order: ";
			bst.infix();//print the infix order
			cout << endl;
			cout << "Pre order: ";
			bst.prefix();//print the prefix order
			cout << endl;
			cout << "Post order: ";
			bst.postfix();//print the postfix order
			cout << endl;
			cout << "Value: ";
			bst.value();//print the value of expression
			cout << endl;
		}
	}
	else
	{
		cout << "Invalid file name." << endl;
	}

	return 0;
}