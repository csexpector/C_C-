#include <iostream>
#include <string>
#include <sstream>

#include <iomanip>

using namespace std;

#include "CourseArray.h"

//template <class TCourse> CourseArray<TCourse>::CourseArray() 
//{ 
//  size = 0;
//}

//template <class TCourse> int CourseArray<TCourse>::getSize()        
//{ 
//	return size; 
//}
//
//template <class TCourse> TCourse CourseArray<TCourse>::getCourse(int i) 
//{
//	return courses[i]; 
//}

//template <class TCourse> void CourseArray<TCourse>::add(TCourse* course)
//{
//  if (size == MAX_COURSES)
//    return;
//
//  courses[size] = *course;
//  size++;
//}

//template <class TCourse> void CourseArray<TCourse>::operator+=(TCourse& rhs){
//    if (size == MAX_COURSES){
//        cout << "Collection is full, unable to add course"<< endl;
//        return;
//    }
//    courses[size++] = rhs;
//    
//}
//template <class TCourse> void CourseArray<TCourse>::operator+=(CourseArray<TCourse>& courses){
//    for(int i = 0; i<courses.getSize(); i++){
//        TCourse course = courses.getCourse(i);
//        *this+=course;
//    }
//}

//template <class TCourse> void CourseArray<TCourse>::operator-=(TCourse& rhs){
//    int index = -1;
//    bool found = false;
//    for(index = 0; index<this->getSize(); ++index){
//        if (this->getCourse(index).getCode()==rhs.getCode() && 
//                this->getCourse(index).getName() == rhs.getName() &&
//                this->getCourse(index).getInstr() == rhs.getInstr() && 
//                this->getCourse(index).getEnrol() == rhs.getEnrol()){
//            found = true;
//            break;
//        }
//    }
//    if (found){
//        
//        for(int i = index; i<this->getSize()-1; ++i){
//            
//            this->courses[i] = this->courses[i+1];
//        }
//        this->size--;
//    }
//    else{
//        cout << "Course not found" << endl;
//    }
//}

//template <class TCourse> void CourseArray<TCourse>::operator-=(CourseArray<TCourse>& courses){
//    int num_courses = courses.getSize();
//    for(int i = 0; i<num_courses; i++){
//        TCourse course = courses.getCourse(i);
//        *this-=course;
//    }
//}

//template <class T> string& operator<<(string& outStr, CourseArray<T>& courses)
//{
//    stringstream ss;
//    
//    ss << setw(15) << left << "Code" <<  " " 
//            << setw(20) << left << "Course Name" << " "             
//            << setw(15) << left << "Instr" << " "           
//            << setw(15) << right << "Enrol" << " "
//            << endl;
//    ss << "-------------------------------------------------------------------------"<< endl; 
//    if (courses.getSize() > 0){
//        for(int i=0; i<courses.getSize(); ++i){
//
//            ss<< setw(15) << left << courses.getCourse(i).getCode() << " "
//                << setw(20) << left <<courses.getCourse(i).getName() << " "                     
//                << setw(15) << left << courses.getCourse(i).getInstr() << " "
//                << setw(15) << right << courses.getCourse(i).getEnrol() << endl;               
//
//        }
//    }
//    else{
//        ss << "No courses are there " << endl;
//    }
//    outStr = ss.str();
//    return outStr;
//    
//}
