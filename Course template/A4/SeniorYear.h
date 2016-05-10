#ifndef SENIOR_YEAR_H
#define SENIOR_YEAR_H
#include "User.h"
#include "Inventory.h"

/*
 * First year student
 */
class SeniorYear : public User
{
  private:
    // borrowed inventory
  	Inventory* _item1;
	// borrowed inventory 
  	Inventory* _item2;
  public:
    // to borrow an inventory 
  	void borrowInventory(Inventory* item);
	// to show borrowed inventories 
  	void showBorrowedItem();
	// constructor with arguments
  	SeniorYear(string username, string password, string fullname, string address, string tel);
};
#endif
