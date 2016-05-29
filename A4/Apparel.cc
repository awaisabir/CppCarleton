#include <iostream>
using namespace std;
#include <string>

#include "Apparel.h"

//Apparel constructor
Apparel::Apparel(string t,string n, string b, float p , string s, string c)
     :BookstoreInventory(t,n,b,p), size(s), color(c) {}

Apparel::~Apparel()
{

}

//getters
string Apparel::getSize()  { return size; }
string Apparel::getColor() { return color; }
string Apparel::getBarcode() { return BookstoreInventory::getBarcode(); }
string Apparel::getName() { return BookstoreInventory::getName(); }
float  Apparel::getPrice() { return BookstoreInventory::getPrice(); }
string Apparel::getType()  { return BookstoreInventory::getType(); }

string Apparel::returnSpecificAttribute() { return getColor(); }
