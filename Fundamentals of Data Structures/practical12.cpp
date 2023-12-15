//Practical 12: Circular Queue

#include <iostream>
using namespace std;

class CircularQueue
{
	private:
		int front;
		int rear;
		int *jobs;
		int M;
	public:
		CircularQueue(int maxSize)
		{
			front = -1;
			rear = -1;
			M = maxSize;
			jobs = new int[M];
		}
		~CircularQueue()
		{
			delete[] jobs;
		}
		bool isEmpty()
		{
			return ((front == -1) && (rear == -1));
		}
		bool isFull()
		{
			return ((rear + 1) % M == front);
		}
		void enqueue(int order)
		{
		    if (isFull())
		    {
		        cout << "Queue is full. Cannot accept any more jobs." << endl;
		        return;
		    }
		    if (isEmpty())
		    {
		        front = 0;
		        rear = 0;
		    }
		    else
		    {
		        rear = (rear + 1) % M;
		    }
		    jobs[rear] = order;
		}
		void dequeue()
		{
		    if (isEmpty())
		    {
		        cout << "Queue is empty." << endl;
		        return;
		    }
		    else
		    {
		        cout << "Serving Order" << jobs[front] << endl;
		        if (front == rear)
		        {
		            // If there was only one element, set front and rear to -1
		            front = rear = -1;
		        }
		        else
		        {
		            front = (front + 1) % M;
		        }
		    }
		}
};

int main()
{
	CircularQueue orderQueue(5);
	cout << "PIZZA PARLOR" << endl;
	while (1)
	{
		int ch;
		cout << "1. Add Order to Queue." << endl;
		cout << "2. Serve Order" << endl;
		cout << "3. Exit" << endl;
		cin >> ch;
		int tempOrder;
		switch(ch)
		{
			case 1:
				cout << "Enter order number: " << endl;
				cin >> tempOrder;
				orderQueue.enqueue(tempOrder);
				break;
			case 2:
				orderQueue.dequeue();
				break;
			case 3:
				return 0;
			default:
				cout << "Invalid Input" << endl;
		}
	}
}
