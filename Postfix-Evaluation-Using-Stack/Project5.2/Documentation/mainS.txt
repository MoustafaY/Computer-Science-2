#include<iostream>
#include<fstream>
#include<string>
#include"HeaderS.h"
using namespace std;
stack s1;

int apply(char,char,char);//function that applies the arithmatic equation of its parameters and returns the result
//Precondition: A character that holds the operator of the equation, two integers that represent the operands.
//Postcondition: The result of the arithmatic equation is returned

int main()
{

	ifstream inFile;//ifstream variable to hold the input file
	int result = 0;//holds the result of the arithmatic equation
	char x;//x holds every item in the input file and is entered as a parameter when it holds an operator
	char opnd1, opnd2;//hold the two integer of an arithmatic equation
	string name;//holds the name of the input file
	cout << "Enter file name: ";
	cin >> name;
	if (name != "input.txt")
	{
		cout << "Invalid file name" << endl;
		return 0;
	}

	inFile.open(name);//input file is opened
	cout << "The expression is: ";
	do
	{
		inFile >> x;//x holds an item in the input file
		if (x != '=')
		{
			cout << x << " ";
		}
		
		if (x == '+' || x == '-' || x == '*' || x == '/')//if x is any one of these operators
		{
				opnd1 = s1.pop();//opnd1 holds the first item in the list
				opnd2 = s1.pop();//opnd2 holds the second item in the list
				result = apply(x, opnd1, opnd2);//the function apply applies the arithmatic equation
				char r = '0' + result;
				s1.push(r);//the result is added to the list
		}
		int d = x - '0';

	    if (d >= 0 && d <= 9)//if x holds a number
		{
			s1.push(x);
		}
	} while (x != '=');
	cout << "= ";
	cout << result << endl;//print the result

	
	return 0;
}

int apply(char x, char opnd1,char opnd2)
{
	int resulty = 0;//holds the result of the arithmatic eequation
	int num1 = opnd1-'0';
	int num2 = opnd2 - '0';
			switch (x)//switch case for x
			{
			case'+':resulty = num2 + num1;//if x = + then add the two operands
				break;
			case'-':resulty = num2 - num1;//if x = - then subtract the operands
				break;
			case'*':resulty = num2 * num1;//if x = * then multiply the operands
				break;
			case'/':resulty = num2 / num1;//if x = / then divide the operands
				break;
			}
		return resulty;//return the result
}
