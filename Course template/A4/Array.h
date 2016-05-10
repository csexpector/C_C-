#ifndef COURSE_ARRAY_H
#define COURSE_ARRAY_H

#include "Course.h"

class CourseArray
{
  public:
    CourseArray();
    void   add(Course*);
    Course getCourse(int);
    int    getSize();
    void operator+=(Course& rhs);
    void operator+=(CourseArray& courses);
    
    void operator-=(Course& rhs);
    
    void operator-=(CourseArray& courses);
    friend string& operator<<(string& outStr, CourseArray& courses);  
    
  private:
    int size;
    Course courses[MAX_COURSES];
};

#endif
