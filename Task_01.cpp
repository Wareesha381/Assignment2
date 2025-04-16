#include<iostream>
using namespace std;

void passingarray(int a[5], int len)
{
	cout << "Dispalying Array Elements: ";
	for (int i = 0;i < len;i++)
	{
		cout << a[i] << " ";
	}

}


int main()
{
	int array[5];
	int size = sizeof(array) / sizeof(array[0]);
	cout << "Enter the Elements for Array: ";
	for (int i = 0;i < size;i++)
	{
		cin >> array[i];
	}
	passingarray(array, size);
	return 0;
}