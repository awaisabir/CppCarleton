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
    void transactionSubMenu(int*);

    void addTextBook(Dlist<Course*>*, Book**);
    void printBooks(Dlist<Course*>*);

    string getCourseCode();
    void   getNumCourseToAddOrRemove(int*);
    void   printCourses(Dlist<Course*>*);
    void   printInventory(string); 

    void getCourseData(Course**); 
    
    void getBookData(Book**);
    void getTechnologyData(Technology**);
    void getGameData(Games**);
    void getApparelData(Apparel**);

    //added getters
    string getInventoryName();
    float getInventoryPrice();
    string getInventoryType();

    string getBookAuthors();

    string getPlatform();

    string getSize();
    string getColor();

    string getMethodOfPayment();
    float  getUserPrice();

    string getApparelSize();

    int getStartDate();
    int getEndDate();

    string getfName();
    string getlName();
    string getAddress();
    string getPostalCode();
    string getDaysToReserve();    

    void   result(string);

    Course* courseToRemove(Dlist<Course*>*);
    void    pause();
    void    courseFound();
    void    courseNotFound();
    void    itemNotFound();
    void    itemFound();

    void    endPrompt();
    
  private:
    int getInt();
};

#endif

