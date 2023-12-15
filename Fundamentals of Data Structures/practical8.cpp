#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class BinaryNumber {
private:
    Node* head;
    Node* tail;

public:
    BinaryNumber() {
        head = NULL;
        tail = NULL;
    }
    bool isEmpty()
    {
    	return ((head == NULL)&&(tail==NULL));
	}

    void addDigitToFront(int digit) {
        Node* newNode = new Node;
        newNode->data = digit;
        newNode->prev = NULL;
        newNode->next = head;

        if (head == NULL) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }

        head = newNode;
    }
    
	void addDigitToEnd(int digit) {
	    Node* newNode = new Node;
	    newNode->data = digit;
	    newNode->next = NULL;
	
	    if (isEmpty()) {
	    	newNode->next = NULL;
	    	newNode->prev = NULL;
	        head = tail = newNode;
	    } else {
	    	newNode->prev = tail;
	        tail->next = newNode;
	        tail = newNode;
	    }
	}

    void displayBinaryNumber() {
        Node* current = head;

        while (current != NULL) {
            cout << current->data;
            current = current->next;
        }

        cout << endl;
	}
	
	friend BinaryNumber computeOnesComp(BinaryNumber&);
	friend BinaryNumber computeTwosComp(BinaryNumber&);
	friend BinaryNumber computeSum(BinaryNumber&, BinaryNumber&);
};

BinaryNumber computeOnesComp(BinaryNumber& binNum)
{
	BinaryNumber compNum;
	Node* current = binNum.head;
	while(current!=NULL)
	{
		if (current->data == 0)
			compNum.addDigitToEnd(1);
		else if (current->data == 1)
			compNum.addDigitToEnd(0);
		current = current->next;
	}
	return compNum;
}

BinaryNumber computeTwosComp(BinaryNumber& binNum)
{
	BinaryNumber onesComp = computeOnesComp(binNum);
	BinaryNumber twosComp;
	int carry = 1;
	Node* current = onesComp.tail;
	while (current!=NULL)
	{
		int sum = current->data + carry;
		carry = sum / 2;
		sum = sum % 2;
		twosComp.addDigitToFront(sum);
		current = current->prev;
	}
	if (carry == 1)
		twosComp.addDigitToFront(1);
	return twosComp;
}

BinaryNumber computeSum(BinaryNumber& num1, BinaryNumber& num2) {
    Node* current1 = num1.tail;
    Node* current2 = num2.tail;
    BinaryNumber numSum;
    int carry = 0;

    while (current1 != NULL || current2 != NULL || carry != 0) {
        int sum = carry;

        if (current1 != NULL) {
            sum += current1->data;
            current1 = current1->prev;
        }
        if (current2 != NULL) {
            sum += current2->data;
            current2 = current2->prev;
        }

        numSum.addDigitToFront(sum % 2);
        carry = sum / 2;
    }

    if (carry == 1) {
        numSum.addDigitToFront(carry);
    }

    return numSum;
}


// Function to get binary number from user input
void getBinaryNumberFromUser(BinaryNumber& binaryNumber) {
    string num;
    cout << "Enter the binary number as a string: ";
    getline (cin, num);
    for (int i = 0; i < num.length(); i++)
    {
    	if (num[i]=='0')
    	{
    		binaryNumber.addDigitToEnd(0);
		}
		else if (num[i]=='1')
		{
			binaryNumber.addDigitToEnd(1);
		}
		else
		{
			cout << "Enter a valid binary number! Do not enter alphabets, spaces, or numbers other than 1 or 0" << endl;
			exit(1);
		}
	}
}

int main()
{
	BinaryNumber num1;
	BinaryNumber num2;
	cout << "Enter the first number: " << endl;
	getBinaryNumberFromUser(num1);
	cout << "Enter the second number: " << endl;
	getBinaryNumberFromUser(num2);
	cout << "The binary numbers you entered are: " << endl;
	num1.displayBinaryNumber();
	num2.displayBinaryNumber();
	cout << endl;
	cout << "The 1's Complement of the two numbers are: " << endl;
	computeOnesComp(num1).displayBinaryNumber();
	computeOnesComp(num2).displayBinaryNumber();
	cout << "The 2's Complement of the two numbers are: " << endl;
	computeTwosComp(num1).displayBinaryNumber();
	computeTwosComp(num2).displayBinaryNumber();
	cout << "The sum of the two binary numbers is: " << endl;
	cout << " ";
	num1.displayBinaryNumber();
	cout << "+";
	num2.displayBinaryNumber();
	cout << "-------------" << endl << " ";
	computeSum(num1, num2).displayBinaryNumber();
}


