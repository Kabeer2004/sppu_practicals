#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class publication
{
	public:
		string title;
		float price;
		publication()
		{
			title = "";
			price = 0.0f;
		}
};

class book:public publication
{
	public:
		int pagecount;
};

class tape:public publication
{
	public:
		float runtime;
};

int main()
{
	cout << "Set the maximum size of your library: " << endl;
	int maxSize;
	cin >> maxSize;
	book booklist[maxSize];
	tape tapelist[maxSize];
	
	int booknum = 0;
	int tapenum = 0;
	while (true)
	{
		cout << "1. Add new book to list" << endl;
		cout << "2. Add new tape to list" << endl;
		cout << "3. Display all publications" << endl;
		int choice;
		cin >> choice;
	
		switch (choice)
		{
			case 1:
				try
				{
					cout << "Enter title" << endl;
					cin >> booklist[booknum].title;
					cout << "Enter price" << endl;
					cin >> booklist[booknum].price;
					cout << "Enter pagecount" << endl;
					cin >> booklist[booknum].pagecount;
					if (booklist[booknum].pagecount<0)
						throw 0;
					booknum++;
					break;
				}
				catch(int e)
				{
					cerr << "Pagecount cannot be negative" << endl;
					exit(1);
				}
			case 2:
				cout << "Enter title" << endl;
				cin >> tapelist[tapenum].title;
				cout << "Enter price" << endl;
				cin >> tapelist[tapenum].price;
				cout << "Enter runtime" << endl;
				cin >> tapelist[tapenum].runtime;
				tapenum++;
				break;
			case 3:
				cout << "Publications in Library: " << endl;
				cout << "--------------BOOKS--------------" << endl;
				for (int i = 0; i<=booknum - 1; i++)
				{
					cout << "Book" << i << endl;
					cout << booklist[i].title << endl;
				}
				cout << "--------------TAPES--------------" << endl;
				for (int i = 0; i<=tapenum - 1; i++)
				{
					cout << "Tape" << i << endl;
					cout << tapelist[i].title << endl;
				}
				break;
			default:
				cout << "Invalid output" << endl;
		}
	}
}
