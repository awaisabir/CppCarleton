#include <iostream>
using namespace std;
#include <string>

#include "Technology.h"

Technology::Technology(string t,string n,string b, float p, int w, string sn)
         :BookstoreInventory(t,n,b,p), warranty(w),serialNumber(sn) {}

Technology::~Technology()
{
	
}


int Technology::getWarranty()       { return warranty; }
string Technology::getSerialNumber(){ return serialNumber; }
string Technology::getName()        { return BookstoreInventory::getName(); }
string Technology::getBarcode()     { return BookstoreInventory::getBarcode(); }
float  Technology::getPrice()       { return BookstoreInventory::getPrice(); }
string Technology::getType()        { return BookstoreInventory::getType(); }

string Technology::returnSpecificAttribute() { return getType(); }