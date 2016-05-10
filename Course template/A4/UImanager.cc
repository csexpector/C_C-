#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"
#include "Pen.h"
#include "CoverFile.h"
#include "BaseballBat.h"

using namespace std;

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course" << endl;
  cout << "  ( 2 )  Remove course" << endl;
  cout << "  ( 3 )  List all courses" << endl;
  cout << "  Inventory Management:" << endl;
  cout << "  ( 4 )  Add Book" << endl;
  cout << "  ( 5 )  Add Pen" << endl;
  cout << "  ( 6 )  Add Cover File" << endl;
  cout << "  ( 7 )  Add Baseball Bat" << endl;
  cout << "  ( 8 )  List Inventories" << endl << endl;
  cout << "  User Management:" << endl;
  cout << "  ( 9 )  Add User" << endl;
  cout << "  ( 10)  Borrow Inventory Item" << endl;
  
  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 10) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::subMenuCourseAdd(int *choice){
    *choice = -1;
    cout << endl << endl << "COURSE MANAGEMENT SUB MENU (ADD COURSE)" << endl;
    cout << "---------------------------------------"<< endl;
    cout << " (1) Add single course" << endl;
    cout << " (2) Add more than one course" << endl;
    cout << " (3) Main Menu" << endl << endl;
    while (*choice <= 0 || *choice > 3) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
    
}
void UImanager::subMenuCourseRemove(int *choice){
    *choice = -1;
    cout << endl << endl << "COURSE MANAGEMENT SUB MENU (REMOVE COURSE)" << endl;
    cout << "-----------------------------------------"<< endl;
    cout << " (1) Remove single course" << endl;
    cout << " (2) Remove more than one courses" << endl;
    cout << " (3) Main Menu" << endl << endl;
    while (*choice <= 0 || *choice > 3) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
    
}

void UImanager::subMenuUserAdd(int *choice){
    *choice = -1;
    cout << endl << endl << "COURSE MANAGEMENT SUB MENU (ADD USER)" << endl;
    cout << "-----------------------------------------"<< endl;
    cout << " (1) Add first year student" << endl;
    cout << " (2) Add second year student" << endl;
    cout << " (3) Main Menu" << endl << endl;
    while (*choice <= 0 || *choice > 3) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
}

void UImanager::subMenuUserBorrow(int *choice){
    *choice = -1;
    cout << endl << endl << "COURSE MANAGEMENT SUB MENU (USER BORROW INVENTORY)" << endl;
    cout << "-----------------------------------------"<< endl;
    cout << " (1) All student borrow inventory item" << endl;
    cout << " (2) One student borrow inventory item" << endl;
    cout << " (3) Show borrowed users and items" << endl;
    cout << " (4) Main Menu" << endl << endl;
    while (*choice <= 0 || *choice > 4) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
}

void UImanager::getCourseArray(CourseArray<Course>& courseArray, int num){
    for(int i = 0; i < num; ++i){
        cout << "Input course " << (i+1) << ": " << endl;
        Course newCourse;
        this->getCourseData(&newCourse);
        courseArray += newCourse;
    }
}
void UImanager::getCourseData(Course* course)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;

  cout << endl;
  
  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }
  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  ";
  getline(cin, name);

  cout << endl << "Enter instructor name:   ";
  getline(cin, inst);

  cout << endl << "Enter enrolment:   ";
  getline(cin, str);
  stringstream ss(str);
  ss >> enrol;

  Course tmpCourse(subj, num, name, inst, enrol);

  *course = tmpCourse;

}

void UImanager::printCourses(CourseArray<Course> *arr)
{
  cout << endl << endl << "ALL COURSES:" << endl << endl;

  for (int i=0; i<arr->getSize(); ++i) {
    Course c = arr->getCourse(i);
    cout << "Course:     " << c.getCode()  << "  " << c.getName() << endl;
    cout << "Instructor: " << c.getInstr()  << endl;
    cout << "Enrolment:  " << c.getEnrol() << endl;
    cout << "Textbooks:  ";
    if (c.getNumBooks() == 0) {
      cout << "None" << endl;
    }
    else {
      cout << endl;
    }
      
    cout << endl;
  }
}

void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

double UImanager::getDouble()
{
  string str;
  double    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

Inventory* UImanager::getBook(){
    cout << "Input book details " << endl;
    cout << "Enter code: ";
    int code = getInt();
    cout << "Enter title: ";
    string title;
    getline(cin, title);
    
    cout << "Enter ISBN: ";    
    string isbn;
    getline(cin, isbn);
    
    cout << "Enter author: ";
    string author;
    getline(cin, author);
    
    cout << "Enter Edition: ";
    int edition = getInt();
    
    cout << "Enter Year: ";
    int year = getInt();
    
    cout << "Enter quantity: ";
    int qty = getInt();
    
    cout << "Enter unit price: ";
    double unit_price = getDouble();
    
    
    
    Inventory *inv = new Book(title, author, isbn, edition, year, code, qty, unit_price);
    
    return inv;
}
Inventory* UImanager::getPen(){
    cout << "Input data for pen" << endl;
    cout << "Input code: ";
    int code = getInt();
    cout << "Enter ink color: ";
    string ink_color;
    getline(cin, ink_color);
    
    cout << "Enter make: ";
    string make;
    getline(cin, make);
    
    cout << "Enter quantity: ";
    int qty = getInt();
    
    cout << "Enter price: ";
    int u_price = getDouble();
    
    Inventory *inv = new Pen(ink_color, make, code, qty, u_price);
    return inv;        
}
Inventory* UImanager::getCoverFile(){
    cout << "Input data for cover file " << endl;
    
    cout << "Input code: ";
    int code = getInt();
    
    cout << "Enter color: ";
    string color;
    getline(cin, color);
    
    cout << "Enter size: ";
    int size = getInt();
    
    cout << "Enter quantity: ";
    int qty = getInt();
    
    cout << "Enter price: ";
    int u_price = getDouble();
    
    Inventory *inv = new CoverFile(color, size, code, qty, u_price);
    return inv;
}
Inventory* UImanager::getBaseballBat(){
    cout << "Input data for Baseball bat" << endl;
    
    cout << "Input code: ";
    int code = getInt();
    
    cout << "Enter color: ";
    string color;
    getline(cin, color);
    
    cout << "Enter built(wood/ aluminium): ";
    string built;
    getline(cin, built);
    
    cout << "Enter size: ";
    int size = getInt();
    
    cout << "Enter quantity: ";
    int qty = getInt();
    
    cout << "Enter price: ";
    int u_price = getDouble();
    
    Inventory *inv = new BaseballBat(color, built, size, code, qty, u_price);
    return inv;
}

void UImanager::printInventory(Inventory *list[], int num){
    cout << setw(15) << left << "Inventory Type" << " "
            <<setw(10) << right << "Code" << " "
            <<setw(10) << right << "Qty" << " "
            <<setw(10) << right << "Unit Price" << " "
            <<setw(10) << right << "Total Price" << " " << endl;
    cout << "------------------------------------------------------------------------"<< endl;        
    if (num <=0 ){
        cout << "No inventory found in the list" << endl << endl;
        return;
    }
        
    for(int i=0; i<num; ++i){
        list[i]->print();
    }
    cout << endl;
}
