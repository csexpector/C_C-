#include <iostream>
#include <string>
#include <sstream>
#include <sstream>
#include <iomanip>

using namespace std;

#include "CourseArray.h"

CourseArray::CourseArray() 
{ 
  size = 0;
}

int    CourseArray::getSize()        { return size; }
Course CourseArray::getCourse(int i) { return courses[i]; }

void CourseArray::add(Course* course)
{
  if (size == MAX_COURSES)
    return;

  courses[size] = *course;
  size++;
}

void CourseArray::operator+=(Course& rhs){
    if (size == MAX_COURSES){
        cout << "Collection is full, unable to add course"<< endl;
        return;
    }
    courses[size++] = rhs;
    
}
void CourseArray::operator+=(CourseArray& courses){
    for(int i = 0; i<courses.getSize(); i++){
        Course course = courses.getCourse(i);
        *this+=course;
    }
}

void CourseArray::operator-=(Course& rhs){
    int index = -1;
    bool found = false;
    for(index = 0; index<this->getSize(); ++index){
        if (this->getCourse(index).getCode()==rhs.getCode() && 
                this->getCourse(index).getName() == rhs.getName() &&
                this->getCourse(index).getInstr() == rhs.getInstr() && 
                this->getCourse(index).getEnrol() == rhs.getEnrol()){
            found = true;
            break;
        }
    }
    if (found){
        
        for(int i = index; i<this->getSize()-1; ++i){
            
            this->courses[i] = this->courses[i+1];
        }
        this->size--;
    }
    else{
        cout << "Course not found" << endl;
    }
}

void CourseArray::operator-=(CourseArray& courses){
    int num_courses = courses.getSize();
    for(int i = 0; i<num_courses; i++){
        Course course = courses.getCourse(i);
        *this-=course;
    }
}

string& operator<<(string& outStr, CourseArray& courses){
    stringstream ss;
    
    ss << setw(15) << left << "Code" <<  " " 
            << setw(20) << left << "Course Name" << " "             
            << setw(15) << left << "Instr" << " "           
            << setw(15) << right << "Enrol" << " "
            << endl;
    ss << "-------------------------------------------------------------------------"<< endl; 
    if (courses.getSize() > 0){
        for(int i=0; i<courses.getSize(); ++i){

            ss<< setw(15) << left << courses.getCourse(i).getCode() << " "
                << setw(20) << left <<courses.getCourse(i).getName() << " "                     
                << setw(15) << left << courses.getCourse(i).getInstr() << " "
                << setw(15) << right << courses.getCourse(i).getEnrol() << endl;               

        }
    }
    else{
        ss << "No courses are there " << endl;
    }
    outStr = ss.str();
    return outStr;
    
}