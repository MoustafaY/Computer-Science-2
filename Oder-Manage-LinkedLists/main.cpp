#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include "Header.h"

//This program takes the integers within two text files, adds them to two seperate lists, then merges these two list
//into one list without repeating any integer.
//The program will ask the user for the name of the two input files, then if they do exist, the program
//will add these items into two seperate lists, where they will be ordered in ascending order.
//then the program merges them into a single list where the number of items and the integers in the first
//and the second list will appear in the terminal along with the number and the integers in the output list.
//The ouput list will also have it's integers printed in an output text file
using namespace std;

List Listo1;
List Listo2;

void open_input(ifstream& file, string name)//this function opens a file
//precondition: the ifstream variable and the name of the file string variable
//postcondition: the file will be opened
{
	file.open(name);//opens the input file named by the user

}

void read1(ifstream& file)//this function adds the items in the first input file to the first list
//precondition: the ifstream file 
//postcondition: the items in the input file will be held inside the first list
{
	int hold;
	while (!file.eof())//loop that will continue until the end of the input file
	{
		file >> hold;//integer is held in the hold variable
		Listo1.insert(hold);//integer is added to the first list through the insert function
	}

}

void read2(ifstream& file)//this function add the items in the second input file to the second list
//precondition: the fstream file
//postcondition: the items in the input file will be held inside the second list
{
	int hold;
	while (!file.eof())//loop will continue until the ned of the input file
	{
		file >> hold;//integer is held in the hold variable
		Listo2.insert(hold);//integer is added to the second list through the insert function
	}
	
}

int main()
{
	string name1,name2;
	ifstream file1,file2;
	cout << "Enter List name: ";//asks user for name of first input file
	cin >> name1;//user input name of first input file
	cout << "Enter List name: ";//asks user for name of second input file
	cin >> name2;//user input name of second input file
	
	if (name1 != "test1.txt" || name2 != "test2.txt")//if the name of the first or the second input file does not equal to
		//test1.txt or test2.txt
	{
		if (name1 != "test1.txt"&& name2!="test2.txt")//if the name of the first and the second input file does not
			//equal to test1.txt and test2.txt
		{
			cout << "Both file names "<<name1<<" and "<<name2<<" does not exist." << endl;//print "both files does not exist"
		}

		else if(name2!="test2.txt")//if the name of the second input file does not equal to test2.txt
		{
			cout << "File name " << name2 << " does not exist." << endl;//print "file name does not exist"
		}

		else
		{
			cout << "File name " << name1 <<" does not exist." << endl;//prints "file name does not exist"
		}
	}

	else//if both input files are correct
	{
	open_input(file1, name1);//first input file is opened
	open_input(file2, name2);//second input file is opened

	read1(file1);//first input file is read and added to the first list
	read2(file2);//second input file is read and added to the second list

	cout << "There are " << Listo1.length() << " items in the first list: " << endl;
	cout << Listo1 << endl;//prints the integrs in the first list
	cout << "There are " << Listo2.length() << " items in the second list: " << endl;
	cout << Listo2 << endl;//prints the integers in the second list

	Listo1.merge(Listo1, Listo2);//adds the integers in the second list to the first list without repeating integers

	Listo1.insert();//prints the output list in the output file

	cout << "There are " << Listo1.length() << " items in the output list." << endl;
	cout << Listo1 << endl;
	}
	return 0;
}