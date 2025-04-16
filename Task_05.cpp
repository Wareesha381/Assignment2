#include<iostream>
#include<fstream>
using namespace std;

void passing(char a[100])
	{
	cout << "Printing on Seperate lines: ";
	for (int i = 0;a[i] != '\0';i++)
	{
		cout << a[i] << endl;
	}

}


int main()
{
	char array[100];
	int count = 0;

	int size=sizeof(array)/sizeof(array[0]);
	cout << "Enter String:";

	cin.getline(array, 100);

	 passing(array);
	return 0;
}