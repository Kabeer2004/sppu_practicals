#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 100;

class MyStack {
private:
    int top;
    char arr[MAX_SIZE];

public:
    MyStack() {
        top = -1;  // Initialize top to -1 to indicate an empty stack
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(char ch) {
        if (isFull()) {
            std::cout << "Stack overflow! Cannot push " << ch << ".\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow! Cannot pop from an empty stack.\n";
            return '0';
        }
        return arr[top--];
    }
};

void procString(string instring, MyStack& stack)
{
	for (int i = 0; i < instring.length(); i++)
	{
		if (isalnum(instring[i]))
		{
			stack.push(tolower(instring[i]));
		}
	}
}

string revStringReturn(MyStack& stack)
{
	string revstring;
	MyStack tempStack = stack;
	while(!(tempStack.isEmpty()))
	{
		revstring = revstring + tempStack.pop();
	}
	return revstring;
}

int main() {
    MyStack myStack;
	
	cout << "Enter a string: " << endl;
	string userString;
	getline (cin, userString);
	
	procString(userString, myStack);
	string revString = revStringReturn(myStack);
	cout << revString << endl;
	
	if (revString == userString)
	{
		cout << "Given string is a palindrome" << endl;
	}
    return 0;
}

