#ifndef USER_H
#define USER_H

#define MAX_USER 100
#include <string>
#include "Book.h"
using namespace std;
/* 
 * abstract class for all type of users
 */
class User 
{
  protected:
	string _username;
	string _password;
	string _fullname;
	string _address;
	string _tel;	
  public:
    // constructor no arguments
  	User();
	// constructor with arguments
  	User(string username, string password, string fullname, string address, string tel);
	// get username 
  	string getUsername();
	// get password
  	string getPassword();
	// get full name 
  	string getFullname();
	// get address 
  	string getAddress();
	// get telephone number 
  	string getTel();
	// set user name 
  	void setUsername(string username);
	// set password 
  	void setPassword(string password);
	// set full name 
  	void setFullname(string fullname);
	// set address 
  	void setAddress(string address);
	// set telephone
  	void setTel(string tel);
  	// virtual function to borrow an inventory
  	virtual void borrowInventory(Inventory* item) = 0;
	// virtual function to show borrowed inventories 
  	virtual void showBorrowedItem() = 0;
};
#endif
