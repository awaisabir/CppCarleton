#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "BookstoreInventory.h"
#include "Book.h"
#include "UImanager.h"
#include "Dlist.h"

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();

    //made all the functions private so other classes would not access them
  private:
    UImanager* view;
    Dlist* courses;
    BookstoreInventory* inventory[MAX_BOOKS];   // a c-style array of pointers is created to store the all the objects that created from the derived class of BookstoreInventory

    BookstoreInventory* getInventory(int);     //Function to get the inventory pointer from the array

    void addInventory(BookstoreInventory*);    //Function to add the inventory into the array
    string printInventory();                   //Function to print the inventory. Returns a string of all the courses

    int size;                                 //Variable to keep track of the number of inventory in the array                         
};

#endif

