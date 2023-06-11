#include <iostream>
#include "Header.h"
using namespace std;
stack s1;

void primefact(int n);//finds the prime factors of the integer and pushes them into the list
//PreCondition: A positive integer
//Postcondition: prime factors are all pushed in the list


int main()
{

	int x=1;//to hold the user input
	bool flag = false;//to flag the loop when to stop
	while (flag==false) //loop continues as long as flag is false
	{
		cout << "Enter a positive integer to know its prime factors (0 to stop): ";
		cin >> x;
		if (x >= 0)//if user input is a positive integer
		{
			if (x == 0)//if user input is zero
			{
				flag = true;//flag becomes true
			}
			else
			{
				primefact(x);//calls function to push prime factors into the list
				cout << "Prime factors: " << x << " = " << s1 << endl;//prints the output using the friend function
			}
		}
		else
		{
			cout << "Invalid Input" << endl;//prints invalid input
			
		}

	}

	return 0;
}

void primefact(int n)
{
	int divisor = 2;//to hold the value of the prime factors

	if (n <= 1)//if input is less than or equal to 1
	{
		return;//return function

	}	

	while (n % divisor != 0)//while user input modulus the divisor does not equal to 0
	{
		divisor++;//increment the divisor
	}
	
	s1.push(divisor);//push the divisor

	primefact(n / divisor);//recur the function with the input divided by the divisor
}
