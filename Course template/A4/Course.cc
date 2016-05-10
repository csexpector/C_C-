#include "Course.h"

Course::Course(string s, string nu, string na, string i, int e)
{
   subj  = s;
   num   = nu;
   name  = na;
   instr = i;
   enrol = e;
}

string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()      { return enrol; }

int    Course::getNumBooks() { 
    //return 0;
    return books.getSize(); 
}

void   Course::addBook(Inventory* b)  
{ 
  books.add(b);
}

