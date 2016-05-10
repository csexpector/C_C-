#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
    numInventory = 0;
}
BMScontrol::~BMScontrol(){
    for(int i=0; i<numInventory; ++i){
        delete this->items[i];
    }
}
void BMScontrol::launch()
{
  int    choice;
  //string code;
  
  while (1) {
    choice = -1;
  
    view.mainMenu(&choice);  
    if (choice >=4 && choice <=7 && numInventory == MAX_INVENTORY){
        cout << "Inventory database full, unable to add more"<< endl;
        continue;
    }
    if (choice == 0) {
      break;
    }
    else if (choice == 1) {
      int choiceAdd = -1;  
      view.subMenuCourseAdd(&choiceAdd);
      if (choiceAdd == 1){
          cout << "Input course data to add " << endl;
          Course newCourse;
          view.getCourseData(&newCourse);
          courses+=newCourse;   // using += to add a course, earlier it was add method
      }
      else if(choiceAdd == 2){
          cout << "Input course data to add " << endl;
          cout << "How many courses to add? ";
          int num;
          cin >> num;
          while(num<=0){
              cout << "Number of courses must be > 0"<<endl;
              view.pause();
              cout << "Enter again: ";
              cin >> num;
          }
          CourseArray array;
          string str; 
          //just to clear the buffer 
          getline(cin, str);
          view.getCourseArray(array, num);
          courses += array; // using += to add the courses
      }
      
      else if(choiceAdd == 3){
          view.pause();
          continue;
      }
      //Course newCourse;
      //view.getCourseData(&newCourse);
      //courses.add(&newCourse);
    }
    else if(choice == 2){
        // for removing one or many courses
        int choiceRem = -1;
        if (courses.getSize() == 0){
              cout << "No courses there to remove" << endl;
              view.pause();
              continue;
        }
        view.subMenuCourseRemove(&choiceRem);
      if (choiceRem == 1){
          
          Course newCourse;
          cout << "Input course data to remove " << endl;
          view.getCourseData(&newCourse);
          courses-=newCourse;   // using -= to remove a course
      }
      else if(choiceRem == 2){
          
          cout << "Input course data to remove " << endl;
          cout << "How many courses to remove? ";
          int num;
          cin >> num;
          while(num<=0 || num > courses.getSize()){
              cout << "Number of courses must be > 0 and <= " << courses.getSize() <<endl;
              view.pause();
              cout << endl;
              cout << "Enter again: ";
              cin >> num;
          }
          CourseArray array;
          string str; 
          //just to clear the buffer 
          getline(cin, str);
          view.getCourseArray(array, num);
          courses -= array; // using -= to add the courses
      }
      
      else if(choiceRem == 3){
          view.pause();
          continue;
      }
        
        
    }
    else if (choice == 3) {
      //view.printCourses(&courses);
      // instead of calling the printCourses we will use the 
      // overloaded <<
      string outStr;
      
      outStr << courses;
      cout << endl << outStr << endl << endl;
    }
    else if (choice == 4) {        
        // adding a book
        Inventory *inv = view.getBook();
        this->items[numInventory++] = inv;
        cout << "Book added" << endl;
        
        
    }
    else if (choice == 5) {
        // adding a book
        Inventory *inv = view.getPen();
        this->items[numInventory++] = inv;
        cout << "Pen added" << endl;
        
    }
    else if (choice == 6) {
        // adding a book
        Inventory *inv = view.getCoverFile();
        this->items[numInventory++] = inv;
        cout << "Cover file added with inventory" << endl;
        
    }
    else if (choice == 7) {
        // adding a book
        Inventory *inv = view.getBaseballBat();
        this->items[numInventory++] = inv;
        cout << "Baseball bat added with inventory" << endl;
        
    }
    else if(choice == 8){
        view.printInventory(this->items, numInventory);        
    }

    view.pause();
  }
}

