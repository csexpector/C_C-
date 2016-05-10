#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "BookArray.h"

class Course {

  public:
    Course(string="", string="", string="", string="", int=0);
    string  getCode();
    string  getName();
    string  getInstr();
    int     getEnrol();
    int     getNumBooks();
    void    addBook(Inventory*);    
    
  private:
    string    subj;
    string    num;
    string    name;
    string    instr;
    int       enrol;
    BookArray books;
};

#endif

