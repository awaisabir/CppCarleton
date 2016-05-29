#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Course**);  //changed
    void printCourses(Dlist*);
    void courseToRemove(Dlist* list);
    void pause();

    void getBookData(Book**);  //added
    void addTextBook(Dlist*, Book**);
    void printBooks(Dlist*);  //added
  private:
    int getInt();
};

#endif

