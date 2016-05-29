/*
 *BookstoreInventory is a base class for the derived classes(technology,apparel,games and book)
 *All its data member will get inherited to the derived classes as they all share these comman data members
 */
#ifndef BOOKSTOREINVENTORY_H
#define BOOKSTOREINVENTORY_H
#include <string>
using namespace std;

class BookstoreInventory 
{
  public:
    BookstoreInventory(string="",string="",string="000000000000",float=0.00);
    virtual ~BookstoreInventory();    // we have to make the destructor virtual so that each individual derived class destructor will be called
    string getType();
    string getBarcode();
    string getName();
    float getPrice();

    virtual string returnSpecificAttribute() = 0;

  private:
  	string type;
  	string name;
    string barcode;
    float price;
};

#endif
