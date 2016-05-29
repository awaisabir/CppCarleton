#include <iostream>
using namespace std;

#include <string>

#include "BookstoreInventory.h"

//constructor
BookstoreInventory::BookstoreInventory(string t, string n,string b, float p) 
		: type(t), name(n), barcode(b), price(p)   {}

//destructor
BookstoreInventory::~BookstoreInventory()
{
	
}

//getters
string BookstoreInventory::getName()  { return name; }
string BookstoreInventory::getBarcode() { return barcode; }
float BookstoreInventory::getPrice()  { return price;   }
string BookstoreInventory::getType()  { return type;  }