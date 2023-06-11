#include"Header.h"
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

queue q;//declaring queue
int digitNum(int);//function to find the number of digits in an integer
//Precondition: the integer that we want to know how many digits does it contain
//Postcondition: the number of digits in the input integer
int findMax(int [], int);//function to find the maximum number in an array
//Precondition: the array that we want to search in , and the size of that array
//Postcondition: the maximum number in the array input
void radixSort(int* ,int,int);//funcion to sort the array input
//Precondition: the array that we want to search in, the size of the array, and the maximum number of digits in the array
//Postcondition: the array will be sorted from smalles to largest integer


int main()
{
	int size;//holds the size of the array
	int seed;//holds the seed value
	int max;//holds maximum integer in the array
	int digitCount;//holds the number of digits in the maximum integer in the array


	cout << "Number of values: ";
	cin >> size;//user enters size
	int* arr=new int[size];//array to hold the integers

	cout << "Seed value: ";
	cin >> seed;//user enters seed

	srand(seed);//random numbers are generated based on the seed
	cout << "Unsorted: ";
	for (int i = 0; i < size;i++)
	{
		arr[i]=rand();//random numbers are generated based on the previous random numbers and are assigned to the array
		cout << arr[i]<<" ";
	}
	cout << endl;

	max = findMax(arr, size);//findMax() returns value to max
	digitCount = digitNum(max);//digitNum() returns value to digitCount


	radixSort(arr,size,digitCount);//radixSort() sorts the array
	cout << "Sorted: ";
	
	
	cout << "Sorted: " << endl;

	cout << q;//integers are printed using queue ADT
	return 0;
}

int digitNum(int x)
{
	int count = 0;//to hold the number of digits in the input integer
	while (x != 0)//loop will continue as long as there are digits left in the integer
	{
		x = x / 10;//deduct one digit from the integer
		count++;//increment count
	}
	return count;//return count
}

int findMax(int arr[],int x)
{
	int max=arr[0];//to hold the maximum value in the array
	for (int i = 0; i < x; i++)//loop will continue as many times as the size of the array
	{
		if (max < arr[i])//if there is an integer larger than max
		{
			max = arr[i];//max will hold the value of that integer instead
		}
	}
	return max;//return max
}

void radixSort(int* arr,int size,int digits) 
{

	int nth;//to hold the position of the digits
	for (int i = 0; i < digits; i++)//loop will continue as many times as the number 
		//of digits in the maximum number of the array
	{
		nth = pow(10, i + 1);//nth has the value of 10 and increases by multiplying it by 10 in each turn
		for (int j = 0; j < size; j++)//loop will continue as many times as the size of the array
		{
			if (arr[j] / nth == 0)//if the integer is smaller than the nth value
			{
				for (int k = j + 1; k < size; k++)//loop will continue as many times as the size of the array
				{
					if (arr[k] / nth == 0)//if the integer is smaller than the nth value
					{
						if (arr[j] % nth > arr[k] % nth)//if the jth integer is larger than the kth integer
						{
							//swap their values
							int temp = arr[k];
							arr[k] = arr[j];
							arr[j] = temp;
						}
					}

				}

			}

		}


	}
	for (int i = 0; i < size; i++)//loop will continue as many times as the size of the array
	{
		q.enqueue(arr[i]);//integer is inserted in the queue
	}


}

