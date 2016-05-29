#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
  view = new UImanager();  //allocate memory for the UImanager object
  courses = new CourseArray();   //allocate memory for the CourseArray object
}

BMScontrol::~BMScontrol()
{
  delete view; //delete the view UImanager pointer
  delete courses;  //delete the courseArray pointer

}
void BMScontrol::launch()
{
  int    choice;
  string code;

  while (1) {
    choice = -1;
    view->mainMenu(&choice);    //changed since view is now a pointer
    if (choice == 0) {
      break;
    }
    else if (choice == 1) {
      //newCourse is now a pointer
      Course *newCourse; 

      //get the couse data from the user (pass the addressof since the parameter id a double pointer)              
      view->getCourseData(&newCourse);

      //add the course pointer to the courses array
      courses->add(newCourse);
    }
    else if (choice == 2) {
      //use the arrow operator since it is a pointer
      view->printCourses(courses);
    }
    else if (choice == 3) {
      //make a new book pointer
      Book *newBook;
      
      int index = 0;  

      //if the course exists    
      if(view->checkCourse(courses, &index) == 1)
      {
        //call the getbookData function
        view->getBookData(&newBook);

        //get the course from the course array and add the book into that course
        courses->getCourse(index)->addBook(newBook);
      }
 
    }
    else if (choice == 4) {
      //call the printBooks function on the array of course pointers
      view->printBooks(courses);     
    }

    view->pause();         // changed
  }
}

