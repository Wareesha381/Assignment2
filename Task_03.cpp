#include<iostream>
using namespace std;

int vowelcount(char a[100])
	{
		int vowelcount = 0;

	for (int i = 0;a[i]!='\0';i++)

	{
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
		{
			vowelcount++;
		}
	}
	return vowelcount;

}


int main()
{
	char array[100];
	int count = 0;

	int size=sizeof(array)/sizeof(array[0]);
	cout << "Enter String:";
	cin.ignore();
	cin.getline(array, 100);

	count = vowelcount(array);
	
	cout << "Vowels in String are: " << count;
	return 0;
}