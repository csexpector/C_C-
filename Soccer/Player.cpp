#include "Player.h"
#include <string.h>
Player::Player(char* fname, char* lname, double subs)
{
	firstName = new char[strlen(fname) + 1];
	strcpy(firstName, fname);
	lastName = new char[strlen(lname) + 1];
	strcpy(lastName, lname);
	subscription = subs;
}

Player::Player()
{
	firstName = new char[strlen("John") + 1];
	strcpy(firstName,"John");
	lastName = new char[strlen("Doe") + 1];
	strcpy(lastName,"Doe");
	subscription = 0;
}

Player::~Player()
{
	if (firstName != nullptr) delete []firstName;
	if (lastName != nullptr)  delete []lastName;
	firstName = nullptr;
	lastName = nullptr;
}
