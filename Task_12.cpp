#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Adding Players
void addingPlayer()
{
start:
	ofstream storing("Players.txt", ios::app);//writing in a file
	if (!(storing.is_open()))
	{
		cout << "Error in Opening File!...Try Again!..." << endl;
		return;
	}
	string playerName, teamName, role;
	int totalRuns, Wickets;

	cout << "Name of the Player is: " << endl;
	cin.ignore(1000, '\n');
	getline(cin,playerName);
	

	cout << "Name of a Team is: " << endl;
	getline(cin, teamName);

	cout << "Role of a PLayer is: " << endl;
	cin >> role;
	
	cout << "Total Runs by the Player are: " << endl;

	cin >> totalRuns;

	cout << "Wickets made by a Player are: " << endl;
	cin >> Wickets;

	storing << playerName << " " << teamName << " " << role << " " << totalRuns << " " << Wickets << endl; //Storing data in a File without wickets!
	cout << "Playes Data added Successfully!...Congratulations!..." << endl;

	storing.close();

	do {
		char op;
		cout << "Do you wan to add a new player: " << endl;// Asking if user wanted to add new player! 
		cin >> op;
		if (op == 'Y' || op == 'y')
		{
			goto start;
		}
		else
		{
			break;
		}
	} while (true);
}

//Viewing All the Players
void viewingPlayers()
{
	ifstream viewingplayers("Players.txt");//reading data of Players from File!

	if (!(viewingplayers.is_open()))
	{
		cout << "Error in opening File....Try Again...." << endl;
		return;
	}
	int displayWickets, displayRuns;
	string displayPlayersName, displayrole, displayTeamName;


	while (viewingplayers >> displayPlayersName >> displayTeamName >> displayrole >> displayRuns >> displayWickets)

	{
		cout << "Name: " << displayPlayersName << " Team Name: " << displayTeamName << " Role: " << displayrole << " Runs: " << displayRuns << " Wickets: " << displayWickets << endl;
	}

	cout << "All the Records Displayed Successfully!....Congratulations...! ";
	viewingplayers.close();
}

//Finding Player by Their Name! 
void findingPlayer()
{
	ifstream findingplayer("Players.txt");//reading data of Players from File!


	if (!(findingplayer.is_open()))
	{
		cout << "Error in Opening File!....Try Again...." << endl;
		return;
	}

	string typePlayername;
	string findName, findRole, findTeamName;
	int fingWickets, findRuns;
	bool found = false;

	cout << "Enter Player Name you want to find: " << endl;
	cin >> typePlayername;

	while (findingplayer >> findName >> findTeamName >> findRole >> findRuns >> fingWickets)
	{
		if (typePlayername == findName)
		{
			cout << "Name: " << findName << " Team Name: " << findTeamName << " Role: " << findRole << " Runs: " << findRuns << " Wickets: " << fingWickets << endl;
			found = true;

		}
	}
	if (found == true)
	{

		cout << "\tPlayer Displayed Successfully!.... Conngratulations....!" << endl;
	}
	else
	{
		cout << "Player doesn't Found!....Try Again...." << endl;
	}
	findingplayer.close();
}
//Updating Players Data                

void UpdatePlayer()
{
	ifstream update("Players.txt");
	

	if (!(update.is_open()))
	{
		cout << "Error in Opening File!....Try Again....!";
		return;
	}

	string findingPlayerName;

	int replacingRuns, replacingWickets;
	cout << "Enter Players name: ";
	cin >> findingPlayerName;

	string updatingName, updatingTeamName, updatingRole;
	int updatingRuns, updatingWickets;
	bool found = false;
	string updatedData = " ";

	while (update >> updatingName >> updatingTeamName >> updatingRole >> updatingRuns >> updatingWickets)
	{
		if (findingPlayerName == updatingName)
		{
			cout << "Enter Run to Update: ";
			cin >> replacingRuns;
			cin.ignore();

			cout << "Enter Wickets to Update: ";
			cin >> replacingWickets;

		updatingRuns = replacingRuns;
		updatingWickets = replacingWickets;
		found = true;
		}
		//Storing updatingRuns and updatingWickets in a file after typrcasting them
		updatedData += updatingName + " " + updatingTeamName + " " + updatingRole + " " + to_string(updatingRuns) + " " + to_string(updatingWickets) + "\n";
	}
	
	update.close();

	ofstream updating("Players.txt");
	if (found == true)
	{
		if (!(updating.is_open()))
		{
			cout << "Error in Opening File!....Try Again....!";
			return;
		}
		else
		{
			updating << updatedData;
			cout << "Data Replaced Successfully!....Comngratulations....! ";
		}
	}
	else
	{
		cout << "Player doesn't Exists....Sorry....! ";
	}
	updating.close();
}
                         //Deleting Record
			
void deleteRecord()
{
	ifstream deleting("Players.txt");  //read
	ofstream temp("Temp.txt");  //write

	if (!deleting.is_open()||!temp.is_open())
	{
		cout << "Error in opening in File....Try Again!....! ";
		return;
	}

	int deleteRuns, deleteWickets;
	string deletePlayerName, deleteTeamName, deleteRole;

	string deletingName;
	bool found = false;

	cout << "Enter the Name you want to delete the record: ";
	cin >> deletingName;

	while (deleting >> deletePlayerName >> deleteTeamName >> deleteRole >> deleteRuns >> deleteWickets)
	{
		if (deletePlayerName != deletingName)
		{
			temp << deletePlayerName << " " << deleteTeamName << " " << deleteRole << " " << deleteRuns << " " << deleteWickets << endl;
			
		}
		else
		{
			found = true;
		}
	}
	deleting.close();
	temp.close();

	remove("Players.txt");
	rename("Temp.txt", "Players.txt");

	if (found == true)
	{
		cout << "Player Deleted Successfully!";

	}
	else
	{
		cout << "Player doesn't Exists!";
	}

}
//Displaying Menu
void menu()
{



	cout << "\t\t========Pakistan Super League========" << endl;
	cout << "Perss 1 to Add Player Record!" << endl;
	cout << "Perss 2 to View all the Players !" << endl;
	cout << "Perss 3 to Search Player by Name or by Team !" << endl;
	cout << "Perss 4 to UpdatePlayer Status !" << endl;
	cout << "Perss 5 to Delete Player Record !" << endl;
	cout << "Perss 6 to Exit from Menu !" << endl;

	do {

		int choice;
		cout << "Enter your Choice: " << endl;
		cin >> choice;
		if (choice == 1)
		{
			addingPlayer();
		}

		else if (choice == 2)
		{
			viewingPlayers();
		}

		else if (choice == 3)
		{
			findingPlayer();
		}

		else if (choice == 4)
		{
			UpdatePlayer();
		}

		else if (choice == 5)
		{
			deleteRecord();
		}

		else if (choice == 6)
		{
			cout << "You Exit the Menu!" << endl;
			break;
		}


	} while (true);


}


int main()
{
	menu();	//Calling a Menu Function
	return 0;
}