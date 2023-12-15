//practical 11
/*

Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ 
program for simulating job queue. Write functions to add job and delete job from queue.

*/

#include <iostream>
using namespace std;
const int MAX = 3;
class Queue
{
	private:
		int front;
		int tail;
		int jobs[MAX];
	public:
		Queue()
		{
			front = tail = -1;
		}
		bool isEmpty()
		{
			return ((front == -1) || (tail==-1));
		}
		bool isFull()
		{
			return ((front == 0) && (tail == MAX - 1));
		}
		void enqueue(int job)
		{
			if (isFull())
			{
				cout << "Queue is full." << endl;
				return;
			}
			if (isEmpty())
			{
				front = 0;
				tail = 0;
				jobs[front] = job;
				cout << "Job" << job << " added to Job Queue." << endl;
			}
			else
			{
				jobs[++tail] = job;
				cout << "Job" << job << " added to Job Queue." << endl;
			}
		}
	    void dequeue() {
	        if (!isEmpty()) {
	            cout << "Executing job" << jobs[front++] << endl;
	
	            // Check if the queue becomes empty after dequeue
	            if (front > tail) {
	                front = -1;
	                tail = -1;
	                cout << "Queue is now empty." << endl;
	            }
	        } else {
	            cout << "No jobs to execute. Queue is empty." << endl;
	        }
	    }
};

int main()
{
	Queue jobQueue;
	while(1)
	{
		cout << "1. Add job to Queue." << endl;
		cout << "2. Execute job from Queue." << endl;
		cout << "3. Exit" << endl;
		int ch;
		cin >> ch;
		int tempJobID;
		switch (ch)
		{
			case 1:
				cout << "Enter job number: " << endl;
				cin >> tempJobID;
				jobQueue.enqueue(tempJobID);
				break;
			case 2:
				jobQueue.dequeue();
				break;
			case 3:
				return 0;
			default:
				cout << "Invalid Input" << endl;
		}
	}
	return 0;
}
