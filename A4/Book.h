/*
Derived class which inherits BookstoreInventory.
Book class has type, authors, isbn,edition and year as its data members and inherits 
the other from BookstoreInventory class
*/

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;
#include "BookstoreInventory.h"
#include "defs.h"
//Book class inherits the BookstoreInventory class
class Book : public BookstoreInventory {

  public:
    Book(string="", string="",string="000000000000", float=0.00, string="", string="", int=1, int=0);
    ~Book();
    string  getType();
    string  getBarcode();
    float   getPrice();
    string  getAuthors();
    string  getISBN();
    string  getName();
    int     getEdition();
    int     getYear();

    virtual string returnSpecificAttribute();

  private:
  	string    type;
    string    authors;
    string    isbn;
    int       edition;
    int       year;
};

#endif

