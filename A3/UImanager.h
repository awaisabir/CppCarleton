#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"
#include "BookstoreInventory.h"
#include "Technology.h"
#include "Games.h"
#include "Apparel.h"

#define TEST_MODE

class UImanager {

  public:
    void mainMenu(int*);

    void addTextBook(Dlist*, Book**);
    void printBooks(Dlist*);

    string getCourseCode();
    void   getNumCourseToAddOrRemove(int*);
    void   printCourses(Dlist*);
    void   printInventory(string); 

    void getCourseData(Course**); 
    void getBookData(Book**);
    void getTechnologyData(Technology**);
    void getGameData(Games**);
    void getApparelData(Apparel**);

    Course* courseToRemove(Dlist*);
    void    pause();
    void    courseFound();
    void    courseNotFound();
    
  private:
    int getInt();
};

#endif

