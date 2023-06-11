#include"Header.h"
#include<iostream>
#include<cstdlib>
using namespace std;

int countWait(int,Queue []);//function to count the total size of all queues and return that number
//Precondition: an int to represent the number of queue, and the queue we are counting
//PostCondition: the total sum of the queues is returned representing customers still waiting in line
int main()
{
	int count=0;//counts the number of customers served
	int entry_time;//holds the entry time of each customer
	int* trans_time;//holds the transaction time for every customer that is dequeued
	int wait_num =0;//holds the waiting time of each customer
	int seed;//holds the seed value in order to generate random numbers
	int z;//holds the number of queues
	int prob;//holds the probability of a customer arriving
	int maxTrans;//holds the maximum transaction time value
	int dur;//holds the duration of the program running
	int maxWait = 0;//holds the current maximum waiting time
	int custWait=0;//holds the number of customers still in line
	int max = 0;//holds the all time maximum waiting time
	
	cout << "Enter seed value: ";
	cin >> seed;
	srand(seed);//random numbers will be generated based on this seed

	cout << "Enter Number of queues/servers: ";
	cin >> z;//user enters number of queues

	Queue* line=new Queue[z];//number of queues are dynamically allocated based on user input

	trans_time = new int[z];//transaction time variables are dynamically allocated based on user input

	for (int i = 0; i < z; i++)//all transaction time variables hold the value of 0
	{
		trans_time[i]=0;
	}


	cout << "Enter probability of customer arriving: ";
	cin >> prob;//user enters probabilty 


	cout << "Enter max amount of time for transaction: ";
	cin >> maxTrans;//user enters the maximum amount of time for a transaction

	cout << "Enter duration of program: ";
	cin >> dur;//user enter the duration of the program

	if (dur > 0 && maxTrans > 0 && prob >= 0 && prob <= 100 && z > 0 && seed > 0)
	{//if the user enters valid inputs
		for (int time = 0; time < dur; time++)//this loop will continue for the amount of times based on the user input
		{
			for (int i = 0; i < z; i++)//this loop will continue based on the amount of queues the user input
			{
				if (rand() % 100 < prob)//if the randomly generated number is within the probability percentage
				{
					line[i].enqueue(time);//the current time is enqueud representing a customer arriving at that time
				}

				if (trans_time[i] == 0)//if transaction time is 0 then the teller is free
				{
					if (!line[i].empty())//if the queue is not empty
					{
						if (max < maxWait)//if the all time maximum value is less than the current maximum value
						{
							max = maxWait;//the all time maximum value holds the value of the current maximum value
						}
						count++;//increment the count of the customers served
						maxWait = 0;//the current maximum value is reset to 0
						entry_time = line[i].dequeue();//dequeues item representing a customer being served
						wait_num += (time - entry_time);//holds the how long that customer waited until getting served
						trans_time[i] = rand() % maxTrans + 1;// a transaction time is generated limited by the maxTrans variable
						if (trans_time[i] == 0)//if the transaction time generated is 0 then we add 1
						{
							trans_time += 1;
						}

					}
				}
				else//if transaction time is not reduced to 0 then increment the current maximum value
				{
					maxWait++;
				}

				if (trans_time[i] > 0)//if transaction time is greater than 0 then decrement the value of transaction time by 1
				{
					trans_time[i]--;

				}

				cout << time + 1 << "     " << trans_time[i] << "  " << line[i] << endl;//print the time then transaction time left
				//then the rest of the queue

			}
			cout << endl;
		}
		count--;//decrement the value of count
		if (count < 0)//if count is less than 0 then count is 0
		{
			count = 0;
		}
		custWait = countWait(z, line);//countWait function returns its value to custWait
		cout << "The longest time a customer waited: " << max << endl;
		cout << count << " customers waited an average of " << wait_num / count << " ticks " << endl;
		cout << "The number of customers waiting in line are: " << custWait << endl;


	}
	else
	{
		cout << "Invalid Input" << endl;
	}
	return 0;
}

int countWait(int z,Queue line[])
{
	int x=0;
	for (int i = 0; i < z; i++)//loop that adds the sizes of the queues in order to get the number of customers waiting
	{
		x += line[i].length();
	}
	return x;
}