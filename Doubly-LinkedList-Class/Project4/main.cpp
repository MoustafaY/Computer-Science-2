#include"Header.h"
#include<iostream>

using namespace std;

DList listo;

int main()
{
	char ch[100];// variable to hold input characters.
	int i = 0;//variable to count the characters
	bool flag = false;//variable to stop the loop
	cout << "Enter line of characters (enter . to end): ";
	while (flag==false)//as long as the flag variable is set to false
	{
		cin >> ch[i];
		if (ch == "#")//if the character is # remove the last item added
		{
			listo.remove_last();
		}
		else//else add the character to the list
		{
			listo.append(ch[i]);
		}

		if (ch == ".")//if the character is a . then stop the loop and print the output list
		{
			flag = true;
		}
	}

	cout << "-> ";
	cout << listo << endl;




	return 0;
}