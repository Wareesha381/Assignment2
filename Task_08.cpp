#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int counting()
{
	int wordcounter = 0;
	ifstream file("output.txt");//reading file

	if (file.is_open())

	{
		char s;
		while (file >> s)
		{
			if (s == ' ')
			{
				continue;
			}
			else
			{
				if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
				{
					wordcounter++;
				}
			}
		}
	}
	return wordcounter;
}
	


int main()
{

	int count = 0;
	count= counting();
	cout << "Number of Words are: " << count;
	

	return 0;
}