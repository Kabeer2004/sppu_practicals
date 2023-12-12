#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class item
{
	public:
		int code;
		string name;
		float cost;
		int quantity;
		item()
		{
			code = 0;
			name = "";
			cost = 0.0f;
			quantity = 0;
		}
};

vector<item> itemlist;
vector<item>::iterator it;

void addItem()
{
	item tempItem;
	cout << "Enter item code" << endl;
	cin >> tempItem.code;
	cout << "Enter item name" << endl;
	cin >> tempItem.name;
	cout << "Enter item cost" << endl;
	cin >> tempItem.cost;
	cout << "Enter item quantity" << endl;
	cin >> tempItem.quantity;
	itemlist.push_back(tempItem);
}

void searchItems()
{
	cout << "Enter code of item you wish to search: " << endl;
	int tempCode;
	cin >> tempCode;
	for (it = itemlist.begin(); it!=itemlist.end(); ++it)
	{
		if(it->code == tempCode)
		{
			cout << "Item found." << endl;
			cout << it->name << endl;
			cout << it->cost << endl;
			cout << it->quantity << endl;
			break;
		}
	}
}



bool compareItems(const item& item1, const item& item2) {
  return item1.code < item2.code;
}

void sortItems() {
  std::sort(itemlist.begin(), itemlist.end(), compareItems);
}

void displayItems() {
  cout << "Items in list:" << endl;
  for (it = itemlist.begin(); it!=itemlist.end(); ++it) {
    cout << "Code: " << it->code << ", Name: " << it->name << endl;
  }
  cout << endl;
}


int main()
{
	cout << "Add item 1" << endl;
	addItem();
	cout << "Add item 2" << endl;
	addItem();
	displayItems();
	searchItems();
	sortItems();
	displayItems();
	return 0;
}
