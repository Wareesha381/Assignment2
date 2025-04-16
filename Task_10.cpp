#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void copying(int  a[10],int len)

{
	int arr[10];
	cout << "Reversed Array: ";
	
	for (int i = 0;i<len;i++)
	{
		arr[i] = a[i];
		cout << arr[i] << " ";

	}

}
	


int main()
{
	int array[10];

	int size = sizeof(array) / sizeof(array[0]);
	cout << "Enter Array: ";

	for (int i = 0;i<size;i++)
	{


		cin >> array[i];
	}


	copying(array, size);

	return 0;
}