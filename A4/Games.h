/*
Derived class which inherits BookstoreInventory.
Games class has platform and rentalPeriodr as its data member and inherits 
the other from BookstoreInventory class
*/
#ifndef GAMES_H
#define GAMES_H

#include "BookstoreInventory.h"
//Games class inherits the BookstoreInventory class
class Games : public BookstoreInventory
{
  public:
    Games(string="", string="", string="000000000000", float=0.00, string="PC",int = 3);
    ~Games();
    string getPlatform();
    string getType();
    int getRentalPeriod();
    string getBarcode();
    string getName();
    float  getPrice();

    string returnSpecificAttribute();
  private:
    string platform;
    int rentalPeriod;
};

#endif
