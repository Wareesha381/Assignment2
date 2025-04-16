#include<iostream>
#include<fstream>
#include<string>
using namespace std;


	//Student is adding Below
void addingstudent()
{

		ofstream outFile("student.txt", ios::app);
		string name, department;
		int roll_num;
		float gpa;

		//Added the lable to repeate the process
	start:
		cout << "Enter Name of Student: " << endl;

		cin >> name;

		cout << "Enter Roll Number of a Student: " << endl;
		cin >> ws;
		cin >> roll_num;

		cout << "Enter Department of a Student: " << endl;

		cin >> department;

		cout << "Enter the GPA of a Student: " << endl;
		cin.ignore(1000, '\n');

		cin >> gpa;

		cout << "\t\tStudent Added Successflly!" << endl;
		if (outFile.is_open())
		{
			outFile << name << " " << roll_num << " " << department << " " << gpa;
			outFile << endl;

		}
		else
		{
			cout<<"Error in Opening File :(...Try Again! ";
		}


		//Asking to add a Student in a File
		char op;

		cout << "Enter y if you want to add Student: ";

		cin >> op;

		while (true)
		{
			if (op == 'y' || op == 'Y')
			{
				goto start;


			}
			else
			{
				if (op != 'y' || op != 'Y')
				{
					break;
				}
			}
		}

}

                          	//Grabing data form file

void displayingrecords()
{
		ifstream readingFile("student.txt");


		int roll_num_reading;
		string namereading;
		string department_reading;
		float reading_gpa;
		if (readingFile.is_open())
		{
			//Moving Data from file to Concle
			cout << "\t\tData read from student.txt" << endl;
			while (readingFile >> namereading >> roll_num_reading >> department_reading >> reading_gpa)
			{

				//displaying data on screen

				cout << "Name: " << namereading << " Roll Number: " << roll_num_reading << " Department: " << department_reading << " GPA: " << reading_gpa << " " << endl;

			}
		}
}
	                        //Searching Student 

void searching()
{
		ifstream roll_num_search("student.txt"); //reading file to find Student

		int id;
		cout << "Enter Roll Number: ";
		cin >> id;
		string name_display, department_display;
		float gpa_display;

		int roll_num_display;
		bool found = false;

		if (roll_num_search.is_open())
		{
			while (roll_num_search >> name_display >> roll_num_display >> department_display >> gpa_display)
			{
				if (id == roll_num_display)
				{
					found = true;
					break;

				}
				else
				{
					found = false;
				}
			}

			if (found == true)
			{
				cout << "Name: " << name_display << " Roll Number: " << roll_num_display << " Department: " << department_display << " GPA: " << gpa_display << " " << endl;
			}
			else
			{
				cout << "Student doesn't found!...Sorry:(...Try Again!";
			}
		}
}

//Updating GPA on File
void updating_gpa()
{
	ifstream reading_for_gpa("student.txt");//reading from file
	ofstream temp("temp.txt");//writing on a file

	float gpa_updating;
	float gpa_replacing;
	int finding_through_roll_num;
	int roll_number;
	string namefind, departmentfind;
	bool found = false;
	cout << "Enter Roll Number: ";
	cin >> finding_through_roll_num;

	if (reading_for_gpa.is_open() && temp.is_open())
	{
		while (reading_for_gpa >> namefind >> roll_number >> departmentfind >> gpa_replacing)
		{
			if (finding_through_roll_num == roll_number)
			{
				cout << "Enter GPA: ";
				cin >> gpa_updating;
				temp<< namefind << " " << roll_number << " " << departmentfind << " " << gpa_updating << endl;
				cout<<namefind << " " << roll_number << " " << departmentfind << " " << gpa_updating << endl;
				found = true;
			}
			else
			{
				temp << namefind << roll_number << departmentfind << gpa_replacing;

			}
		}
		
	}
	if (found == true)
	{
		remove("student.txt");
		rename("temp.txt", "student.txt");
		cout << "GPA updated Successfully!";
	}

	else
	{
		remove("temp.txt");
		cout << "Error in Replacing GPA!...Sorry...Try Again:(";
	}
}
                       //deleting  Students by their ids

void deleting()
{
	ifstream deleting("student.txt");
	ofstream temp("temp.txt");

	string delayname, deldepartment;
	float delgpa;
	int delroll_num;
	int id_to_del;

	int found = false;
	cout << "Enter id you want to delete: ";
		cin >> id_to_del;

	if (!(deleting.is_open()) && (temp.is_open()))
	{
		cout << "Error in Opening File!..Try Again...! ";
		return;

	}
	else
	{
		while (deleting >> delayname >> delroll_num >> deldepartment >> delgpa)
		{
			if (delroll_num != id_to_del)
			{
				temp << delayname << " " << delroll_num << " " << deldepartment << " " << delgpa;
			}
			else
			{
				found = true;
			}
		}
	}

	deleting.close();
	temp.close();
	if (found)
	{
		remove("student.txt");
		rename("temp.txt", "student.txt");
		cout << "Student Record with id " << id_to_del << " deleted Successfully! ";
	}
	else
	{
		remove("temp.txt");
		cout << "Student not found! ";
	}

}
int menu()
{
		cout <<endl<< "\t\t========Student Management System========" << endl;
		cout << "\tPress 1 to Add Student!" << endl;
		cout << "\tPress 2 to View all the Records!" << endl;
		cout << "\tPress 3 to Search a student by Roll Number!" << endl;
		cout << "\tPress 4 to Update Student GPA!" << endl;
		cout << "\tPress 5 to Delete Student Record!" << endl;
		cout << "\tPress 6 to Exit from the Menu! " << endl;
		//choices
		int choice;

		while (true)
		{
		cout << "Press button you want to deal with: ";
		cin >> choice;


		if (choice == 1)
		{
			addingstudent();
		}
		else if (choice == 2)
		{
			
				displayingrecords();
			

		}
		else if (choice == 3)
		{

			searching();

		}
		else if (choice == 4)
		{
			updating_gpa();
		}
		else if (choice == 5)
		{
			deleting();
		}
		if (choice == 6)
		{
			cout << "You Exit the menu! ";
			break;
		}
		
	}
	return 0;
}


int main( )
{
	menu();
	system("pause");
	return 0;
}
