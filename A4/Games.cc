#include <iostream>
using namespace std;
#include <string>

#include "Games.h"

Games::Games(string t,string n, string b, float p, string pl, int r)
        :BookstoreInventory(t,n,b,p), platform(pl), rentalPeriod(r) {}

Games::~Games()
{
	
}

string Games::getPlatform() { return platform; }
string Games::getType()    { return  BookstoreInventory::getType();    }
int Games::getRentalPeriod(){ return rentalPeriod; }
string Games::getBarcode()  { return BookstoreInventory::getBarcode(); }
string Games::getName()     { return BookstoreInventory::getName(); }
float  Games::getPrice()    { return BookstoreInventory::getPrice(); }

string Games::returnSpecificAttribute() { return getPlatform(); }
