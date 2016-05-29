#include <iostream>
#include <string>
using namespace std;

#include "CourseArray.h"

CourseArray::CourseArray() 
{ 
  size = 0;
}

//Deallocate each course pointer
CourseArray::~CourseArray()
{
  for(int i = 0; i < size; i++)
   {	
     //call cleanup so each book gets deallocated
     courses[i]->cleanup();
     delete courses[i];
   }
}
int    CourseArray::getSize()        { return size; }
Course* CourseArray::getCourse(int i) { return courses[i]; }

void CourseArray::add(Course* course)
{
  if (size == MAX_COURSES)
    return;

  courses[size] = course;
  size++;
}

