#include "stdafx.h"
#include "Player.h"
#include <string.h>

// Constructor of Player
Player::Player(char* fname, char* lname, double subs)
{
	firstName = new char[strlen(fname) + 1];
	strcpy_s(firstName, strlen(fname) + 1, fname);
	lastName = new char[strlen(lname) + 1];
	strcpy_s(lastName,strlen(lname) + 1, lname);
	subscription = subs;
}
// Constructor of Player (no arguments)
Player::Player()
{
	firstName = new char[strlen("John") + 1];
	strcpy_s(firstName, strlen("John") + 1, "John");
	lastName = new char[strlen("Doe") + 1];
	strcpy_s(lastName, strlen("Doe") + 1, "Doe");
	subscription = 0;
}
// Destructor of Player
Player::~Player()
{
	if (firstName != nullptr) delete[]firstName;
	if (lastName != nullptr)  delete[]lastName;
	firstName = nullptr;
	lastName = nullptr;
}