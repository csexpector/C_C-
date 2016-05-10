#include "stdafx.h"
#include "SoccerClub.h"
#include "Player.h"
#include <iostream>
using namespace std;
SoccerClub::SoccerClub()
{
	pPlayers = nullptr;
}
// add a player to the front of linked list
void SoccerClub::AddPlayer()
{
	//Player* p = new Player();
	char* fname = new char[100];
	char* lname = new char[100];
	int subsmission;
	cout << "Enter first name: ";
	cin >> fname;
	cout << "Enter last name:";
	cin >> lname;
	cout << "Enter submission: ";
	cin >> subsmission;
	Player* p = new Player(fname, lname, subsmission);
	Link* l = new Link(nullptr, nullptr, p);
	// if list is empty
	if (pPlayers == nullptr)
		pPlayers = l;
	else
	{
		// add player to front of list
		l->pNext = pPlayers;
		pPlayers->pPrev = l;
		pPlayers = l;
	}
}
// delete player from the front
void SoccerClub::DeletePlayer()
{
	if (pPlayers != nullptr) // delete if pPlayers is not empty
	{
		if (pPlayers->pNext != nullptr)
		{
			Link* tmp = pPlayers;
			pPlayers = pPlayers->pNext;
			if (pPlayers != nullptr) pPlayers->pPrev = nullptr;
			tmp->pNext = nullptr;
			delete tmp;
			tmp = nullptr;
		}
		else // only one player
		{
			delete pPlayers;
			pPlayers = nullptr;
		}
	}
}
// print players from front
void SoccerClub::PrintPlayersForward()
{
	Link* p = pPlayers;
	while (p != nullptr)
	{
		// print player information
		cout << "First name: " << p->pPlayer->getFirstName() << endl;
		cout << "Last name: " << p->pPlayer->getLastName() << endl;
		cout << "Submission: " << p->pPlayer->getSubscription() << endl;
		p = p->pNext; // moving forward
	}
}
// print players from back
void SoccerClub::PrintPlayersReverse()
{
	Link* p = pPlayers;
	while (p->pNext != nullptr) // find the last player
	{
		p = p->pNext;
	}
	// now p is the last player
	while (p != nullptr)
	{
		// print player information
		cout << "First name: " << p->pPlayer->getFirstName() << endl;
		cout << "Last name: " << p->pPlayer->getLastName() << endl;
		cout << "Submission: " << p->pPlayer->getSubscription() << endl;
		p = p->pPrev; // moving backward
	}
}
// delete instance of SoccerClub
SoccerClub::~SoccerClub()
{
	while (pPlayers != nullptr)
	{
		DeletePlayer();
	}
}
