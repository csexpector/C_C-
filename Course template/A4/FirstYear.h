#ifndef FIRST_YEAR_H
#define FIRST_YEAR_H
#include "User.h"
#include "Inventory.h"
/*
 * First year student
 */
class FirstYear : public User
{
  private:
    // borrowed inventory
  	Inventory* _item;
  public:
    // borrow inventory 
  	void borrowInventory(Inventory* item);
	// show borrowed inventory
  	void showBorrowedItem();
	// constructor with arguments
  	FirstYear(string username, string password, string fullname, string address, string tel);
};
#endif
