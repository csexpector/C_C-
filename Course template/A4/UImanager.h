#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "CourseArray.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void subMenuCourseAdd(int *); // added
    void subMenuCourseRemove(int *); // added
    void subMenuUserAdd(int *);
    void subMenuUserBorrow(int *);
    void getCourseData(Course*);
    void getCourseArray(CourseArray<Course> &, int ); // added to input many courses    
    void printCourses(CourseArray<Course>*);
    void printInventory(Inventory *[], int);
    void pause();
    // following functions added
    Inventory* getBook();
    Inventory* getPen();
    Inventory* getCoverFile();
    Inventory* getBaseballBat();
  private:
    int getInt();
    double getDouble();
};

#endif

