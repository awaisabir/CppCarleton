#ifndef COURSE_ARRAY_H
#define COURSE_ARRAY_H

#include "Course.h"

class CourseArray
{
  public:
    CourseArray();
    ~CourseArray();
    void   add(Course*);
    Course* getCourse(int);
    int    getSize();
  private:
    int size;
    Course* courses[MAX_COURSES]; //changed
};

#endif
