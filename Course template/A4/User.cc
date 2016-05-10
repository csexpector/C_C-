#include "User.h"
#include <iostream>

using namespace std;

User::User()
{
	_username = "default";
	_password = "default";
	_address  = "default";
	_fullname = "default";
	_tel      = "default";
}

User::User(string username, string password, string fullname, string address, string tel)
{
	_username = username;
	_password = password;
	_fullname = fullname;
	_address  = address;
	_tel      = tel;
}
string User::getAddress()
{
	return _address;
}

string User::getFullname()
{
	return _fullname;
}
string User::getPassword()
{
	return _password;
}
string User::getTel()
{
	return _tel;
}
void User::setAddress(string address)
{
	_address = address;
}
void User::setFullname(string fullname)
{
	_fullname = fullname;
}
void User::setPassword(string password)
{
	_password = password;
}
void User::setTel(string tel)
{
	_tel = tel;
}
