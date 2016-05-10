#include "SeniorYear.h"
#include <iostream>
#include <string>
using namespace std;
void SeniorYear::borrowInventory(Inventory* item)
{
	if (_item1 != NULL && _item2 != NULL)
	{
		cout << "You are allowed to borrow 2 items only. Please return borrowed item first." << endl;
		return;
	}
	if (_item1 == NULL && _item2 != NULL)
	{
		_item1 = item;
		cout << "You have borrowed 2 items." << endl;
		return;
	}
	if (_item2 == NULL && _item1 != NULL)
	{
		_item2 = item;
		cout << "You have borrowed 2 items." << endl;
		return;
	}
	
	_item1 = item;
	cout << "You have borrowed 1 item." << endl;
}
void SeniorYear::showBorrowedItem()
{
	if (_item1 == NULL && _item2 == NULL)
	{
		cout << "You haven't borrow any item yet." << endl;
	}
	else
	{
		cout << "Items you borrowed" << endl;
		if (_item1 != NULL) _item1->print();
		if (_item2 != NULL) _item2->print();
	}
}

SeniorYear::SeniorYear(string username, string password, string fullname, string address, string tel) : User(username, password, fullname, address, tel)
{
	
}
