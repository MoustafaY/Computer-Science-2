#include"Header.h"
#include<iostream>
using namespace std;

queue::queue()
{
	data[capacity] = 0;
	front = 0;
	rear = capacity - 1;
	count = 0;
}

void queue::enqueue(Item entry)
{
	rear = next_index(rear);
	data[rear] = entry;
	count++;
}

queue::Item queue::dequeue()
{
	Item it;
	it = data[front];
	front = next_index(front);
	count--;
	return it;
}

ostream& operator<<(ostream& out, queue q)
{
	queue::Item it;
	int n, i;
	n = q.size();
	for (i = 0; i < n; i++)
	{
		it = q.dequeue();
		out << it << " ";
		q.enqueue(it);
	}
	return out;
}