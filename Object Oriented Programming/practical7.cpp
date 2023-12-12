#include <iostream>
#include <map>

using namespace std;

map<string, float> states;
map<string, float>::iterator i;

int main()
{
	char cont_choice;
	do
	{
		cout << "1. Add a [State,Population] Pair to the map" << endl;
		cout << "2. Search for the population of a state" << endl;
		int choice;
		string tempState;
		float tempPop;
		string searchState;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter the name of the state." << endl;
				cin >> tempState;
				cout << "Enter the population of the state in Cr" << endl;
				cin >> tempPop;
				states[tempState] = tempPop;
				break;
			case 2:
				cout << "Enter the name of the state whose population you want to view" << endl;
				cin >> searchState;
				for (i = states.begin(); i!=states.end(); ++i)
				{
					if(i->first == searchState)
						cout << "Population of " << searchState << " is " << i->second << "Cr" << endl;
				}
				break;
			default:
				cout << "Invalid Input." << endl;
		}
		
		cout << "Do you want to continue? (y/n)" << endl;
		cin >> cont_choice;
	}while (cont_choice == 'y' || cont_choice == 'Y');
}
