#include "FirstYear.h"
#include <iostream>
using namespace std;
void FirstYear::borrowInventory(Inventory* item)
{
	if (_item != NULL)
	{
		cout << "You are allowed to borrow 1 item only. Please return borrowed item first." << endl;
	}
	else
	{
		_item = item;
	}
}
void FirstYear::showBorrowedItem()
{
	if (_item == NULL)
	{
		cout << "You haven't borrow any item yet." << endl;
	}
	else
	{
		cout << "This is the item you borrowed" << endl;
		_item->print();
	}
}
FirstYear::FirstYear(string username, string password, string fullname, string address, string tel)
: User(username, password, fullname, address, tel)
{
	
}
