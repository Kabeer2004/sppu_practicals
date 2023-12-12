#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 10;
int array1[MAX] = {10,20,30,40,50};
int array2[MAX];

int main()
{
	ofstream os;
	os.open("input.dat", ios::trunc|ios::binary);
	if (!os)
	{
		cout << "Could not open file." << endl;
		exit(1);
	}
	os.write((char*)(&array1), sizeof(array1));
	if (!os)
	{
		cout << "Could not write to file" << endl;
		exit(1);
	}
	os.close();

	ifstream is;
	is.open("input.dat", ios::binary);
	if (!is)
	{
		cout << "Could not open file" << endl;
		exit (1);
	}
	is.read((char*)(&array2), sizeof(array2));
	if (!is)
	{
		cout << "Could not read from file" << endl;
		exit(1);
	}
	is.close();
	for (int i=0; i<MAX; i++)
	{
		cout << array2[i] << " ";
	}
}
