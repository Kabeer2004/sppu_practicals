#include <iostream>
using namespace std;

template <typename T>
void select_sort(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i+1; j<size; j++)
		{
			if (arr[j]<arr[min])
				min = j;
		}
		T temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	cout << "Sorted array: " << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr1[] = {20, 50, 10, 30, 70};
	int arr_len1 = sizeof(arr1) / sizeof(arr1[0]);
	float arr2[] = {9.9, 20.2, 13.1, 5.6, 2.2};
	int arr_len2 = sizeof(arr2) / sizeof(arr2[0]);
	select_sort(arr1, arr_len1);
	select_sort(arr2, arr_len2);
}
