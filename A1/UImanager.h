#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "CourseArray.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Course**);  //changed
    void printCourses(CourseArray*);
    void pause();

    void getBookData(Book**);  //added
    int checkCourse(CourseArray*, int*);  //added
    void printBooks(CourseArray*);  //added
  private:
    int getInt();
};

#endif

