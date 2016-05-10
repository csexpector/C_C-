#ifndef COURSE_ARRAY_H
#define COURSE_ARRAY_H

#include "Course.h"
#include <sstream>
using namespace std;
template <class TCourse> class CourseArray
{
  public:
    // get size
    CourseArray()
    {
    	size = 0;
	}
	// add course to array
    void   add(TCourse* course)
    {
    	if (size == MAX_COURSES)
    		return;

  		courses[size] = *course;
  		size++;
	}
	// get a course at index i
    TCourse getCourse(int i)
    {
    	return courses[i]; 
	}
	// get size of array 
    int    getSize()
    {
    	return size; 
	}
	// overload operator+=
    void operator+=(TCourse& rhs)
    {
    	if (size == MAX_COURSES){
        	cout << "Collection is full, unable to add course"<< endl;
        	return;
    	}
    	courses[size++] = rhs;
	}
	// overload operator+= 
    void operator+=(CourseArray<TCourse>& courses)
    {
    	for(int i = 0; i<courses.getSize(); i++){
        	TCourse course = courses.getCourse(i);
        	*this+=course;
    	}
	}
    
    // overload operator-= 
    void operator-=(TCourse& rhs)
    {
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
    // overload operator-= 
    void operator-=(CourseArray<TCourse>& courses)
    {
    	int num_courses = courses.getSize();
	    for(int i = 0; i<num_courses; i++){
	        TCourse course = courses.getCourse(i);
	        *this-=course;
	    }
	}
	// overload operator<< 
    friend string& operator<<(string& outStr, CourseArray<TCourse>& courses)
    {
    	stringstream ss;
    
	    ss << left << "Code" <<  " " 
	            <<  left << "Course Name" << " "             
	            <<  left << "Instr" << " "           
	            <<  right << "Enrol" << " "
	            << endl;
	    ss << "-------------------------------------------------------------------------"<< endl; 
	    if (courses.getSize() > 0){
	        for(int i=0; i<courses.getSize(); ++i){
	
	            ss<< left << courses.getCourse(i).getCode() << " "
	                <<  left <<courses.getCourse(i).getName() << " "                     
	                <<  left << courses.getCourse(i).getInstr() << " "
	                <<  right << courses.getCourse(i).getEnrol() << endl;               
	
	        }
	    }
	    else{
	        ss << "No courses are there " << endl;
	    }
	    outStr = ss.str();
	    return outStr;
	}
    
    
  private:
    int size;
    TCourse courses[MAX_COURSES];
};
//template <class TCourse> string& operator<<(string& outStr, CourseArray<TCourse>& courses);

#endif
