//practical 10
const int MAX = 100;
#include <iostream>
using namespace std;

class Stack
{
	private:
		int top;
		char stack_arr[MAX];
	public:
		Stack()
		{
			top = -1;
		}
		bool isEmpty()
		{
			return (top == -1);
		}
		bool isFull()
		{
			return (top == MAX - 1);
		}
		void push(char ch)
		{
			stack_arr[++top] = ch;
		}
		char pop()
		{
			return stack_arr[top--];
		}
		char topEle()
		{
			return stack_arr[top];
		}
};

bool isOperator(char ch)
{
	return ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'));
}

int getPrecedence(char op)
{
	if (op == '/')
		return 4;
	if (op == '*')
		return 3;
	if (op == '+')
		return 2;
	if (op == '-')
		return 1;
}

string infixToPostfix(string infix)
{
	Stack charStack;
	string postfix;
	for (int i = 0; i < infix.length(); i++)
	{
		if (isalnum(infix[i]))
		{
			postfix += infix[i];
		}
		if (isOperator(infix[i]))
		{
			while ((!charStack.isEmpty()) && (getPrecedence(charStack.topEle()) > getPrecedence(infix[i])))
			{
				postfix += charStack.pop();
			}
			charStack.push(infix[i]);
		}
	}
	while (!charStack.isEmpty())
	{
		postfix += charStack.pop();
	}
	return postfix;
}

int evalOp(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}

int evalPostfix(string postfix)
{
	cout << "The postfix expression will be evaluated as follows: " << endl;
	Stack operandStack;
	int res;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isalnum(postfix[i]))
		{
			operandStack.push(postfix[i]);
		}
		if (isOperator(postfix[i]))
		{
			int b = operandStack.pop() - '0';
			int a = operandStack.pop() - '0';
			char op = postfix[i];
			res = evalOp(a, b, op);
			operandStack.push(res + '0');
		}
		if (isalpha(postfix[i]))
		{
			cout << "This expression cannot be evaluated as it contains variables. Please enter an expression with constants to evaluate it's result." << endl;
			return 0;
		}
	}
	res = operandStack.pop() - '0';
	cout << res << endl;
	return 0;
}

int main()
{
	cout << "Enter an infix expression: " << endl;
	string infix;
	getline (cin, infix);
	cout << "The postfix expression is: " << endl;
	string postfix = infixToPostfix(infix);
	cout << postfix << endl;
	evalPostfix(postfix);
}
