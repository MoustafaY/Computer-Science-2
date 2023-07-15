# Queueing simulation

Linked Queues are useful when we want to print the contents of a queue without directly accessing the data inside the queue. This program creates linked queues based on the user input. Each queue represents a line of customers and one teller. The program generates a transaction time amount and starts to count down from it, when the transaction time becomes zero a new customer is dequeued or served and another transaction time amount is generated, and the loop is repeated. After the simulation ends, the program will print:
- The longest time a customer waited to be served
- The average ticks the served customer waited
- How many customers are still left in line.
