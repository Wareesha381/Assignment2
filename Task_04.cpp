#include<iostream>
#include<fstream>
using namespace std;

void writing(char a[100])
	{
	ofstream data("output.txt");

	if (data.is_open())
	{
		for (int i = 0;a[i] != '\0';i++)
		{
			data << a[i];
		}
	}
	data.close();
	

}


int main()
{
	char array[100];
	int count = 0;

	int size=sizeof(array)/sizeof(array[0]);
	cout << "Enter String:";
	cin.ignore();
	cin.getline(array, 100);

	 writing(array);
	return 0;
}