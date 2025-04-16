#include<iostream>
using namespace std;

int passingarray(int a[5], int len)
{
	int sum = 0;

	for (int i = 0;i < len;i++)
	{
		sum += a[i];
	}
	return sum;

}


int main()
{
	int array[5];
	int sum = 0;
	int size = sizeof(array) / sizeof(array[0]);
	cout << "Enter the Elements for Array: ";
	for (int i = 0;i < size;i++)
	{
		cin >> array[i];
	}
	sum= passingarray(array, size);
	cout << "Sum of elements are: " << sum;
	return 0;
}