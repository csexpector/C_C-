// SoccerApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Player.h"
#include "Link.h"
#include "SoccerClub.h"
#include <iostream>			// <--- have to add this to use cout
using namespace std;
int main(void)
{
	SoccerClub sc;
	bool RUNNING = true;
	char response;
	while (RUNNING)
	{
		cout << "nPlease select an option:" << endl;
		cout << "1. Add a Player" << endl;
		cout << "2. Delete a Player" << endl;
		cout << "3. Print out Players" << endl;
		cout << "4. Print out Players in reverse order" << endl;
		cout << "q. Quit" << endl;
		cout << "CHOICE: ";
		cin >> response;
		switch (response)
		{
			case '1':sc.AddPlayer(); break;
			case '2':sc.DeletePlayer(); break;
			case '3':sc.PrintPlayersForward(); break;
			case '4':sc.PrintPlayersReverse(); break;
			case 'q': return 0;
			default:cout << "Please enter a valid optionn";
		}
		cout << "n";
	}
}