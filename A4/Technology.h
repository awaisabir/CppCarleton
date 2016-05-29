/*
Derived class which inherits BookstoreInventory.
Technology class has warranty and serialNumber as its data member and inherits 
the other from BookstoreInventory class
*/

#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H
#include "BookstoreInventory.h"
//Technology class inherits the BookstoreInventory class
class Technology : public BookstoreInventory
{
  public:
    Technology(string="",string="",string="000000000000",float=0.00, int=0, string="");
    ~Technology();
    int getWarranty();
    string getSerialNumber();

    string getName();
    string getBarcode();
    float  getPrice();
    string getType();

    virtual string returnSpecificAttribute();

  private:
    int warranty;
    string serialNumber;
};

#endif
