/********************************************************************
 *Derived class which inherits BookstoreInventory.                  *
 *Apparel class has size and color as its data member and inherits  *
 *the other from BookstoreInventory class                           *
 *******************************************************************/
#ifndef APPAREL_H
#define APPAREL_H

#include "BookstoreInventory.h"
//Apparel class inherits the BookstoreInventory class
class Apparel : public BookstoreInventory
{
  public:
    Apparel(string="",string= "",string="000000000000", float=0.00, string="Large", string="Maroon");
    ~Apparel();
    string getSize();
    string getColor();
    string getName();
    string getBarcode();
    float  getPrice();
    string getType();
    
  private:
    string size;
    string color;
};

#endif
