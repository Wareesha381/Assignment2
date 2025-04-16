#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void palindrome(char a[10])

{
	char array2[10];
	cout << "Enter String you want to check Palindrome on: ";
	cin.ignore();
	cin.getline(array2, 10);
	
	bool found = false;
	for (int i = 0;a[i] != '\0';i++)
	{
			if (a[i] == array2[i])
			{
				found = true;
			}
			else
			{
				found = false;
				break;
			}
		

	}

	if (found==false)
	{
		cout << "word is not Polindrome!";
	}
	else
	{
		cout << "Word is Polindrome! ";
	}
}
	


int main()
{

	char array[10];
	
	cout << "Enter Array: ";
	cin.ignore();
	cin.getline(array, 10);

	palindrome(array);
	
	

	return 0;
}