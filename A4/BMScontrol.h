#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "BookstoreInventory.h"
#include "Book.h"
#include "UImanager.h"
#include "Transaction.h"
#include "Dlist.h"
#include "Buy.h"
#include "Return.h"
#include "BookRentalPeriod.h"
#include "Reserve.h"


class BMScontrol {
  
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();

    //made all the functions private so other classes would not access them
  private:
    UImanager* view;
    Dlist<Course*>* courses;
    BookstoreInventory* inventory[MAX_BOOKS];   // a c-style array of pointers is created to store the all the objects that created from the derived class of BookstoreInventory
    Transaction*  transactions[MAX_BOOKS];

    BookstoreInventory* getInventory(int);     //Function to get the inventory pointer from the array

    void addInventory(BookstoreInventory*);    //Function to add the inventory into the array
    string printInventory(); 
    //void removeInventory(BookstoreInventory*);                  //Function to print the inventory. Returns a string of all the courses

    void addTransaction(Transaction*);

    BookstoreInventory* findBook(string, string, float);
    BookstoreInventory* findTechnology(string, string, float);
    BookstoreInventory*  findGame(string, string, float);
    BookstoreInventory* findApparel(string, string, float);

    int size;                                 //Variable to keep track of the number of inventory in the array                         
    int transactionSize;

};
#endif
