#include<iostream>
#include<fstream>
using namespace std;

int passing(int a[10], int size)
{
	int largest_num = a[0];

	for (int i = 0;i < size;i++)
	{
		if (a[i] > largest_num)
		{
			largest_num = a[i];
		}
	}
	return largest_num;
}


int main()
{
	int array[10];
	int large = 0;

	int size=sizeof(array)/sizeof(array[0]);
	cout << "Enter array: ";
	for (int i = 0;i < size;i++)
	{
		cin >> array[i];

	}
	large = passing(array, size);
	cout << "Largest Number in Array is: " << large;
	return 0;
}