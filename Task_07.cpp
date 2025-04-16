#include<iostream>
#include<fstream>
using namespace std;

void printing_array(char a[21])
{
	cout << "Reverse String is: ";
	for (int i=20;i >= 0;i--)
	{
		cout << a[i] << " ";
	}

	
}


int main()
{
	char array[21] ;
	cout << "Enter String: ";
	cin.getline(array, 21);

	printing_array(array );
	

	return 0;
}