#include <iostream>
using namespace std;

#include <string>
#include <sstream>

#include "Reserve.h"

//constructor
Reserve::Reserve(BookstoreInventory* ptr, string f, string l, string a, string p, string d)
	: Transaction(ptr), fname(f), lname(l), address(a), postalCode(p), daysToReserveFor(d)
{

}
Reserve::~Reserve()
{
	
}

BookstoreInventory* Reserve::getProduct()  { return Transaction::getProduct(); }

//function to return a string
string Reserve::transactionHandle(BookstoreInventory* ptr, BookstoreInventory* arr[], int& size)
{
	string str = "";
	stringstream ss;
	ss << daysToReserveFor;


	str = "You have reserved " + getProduct()->getName() + " for " +  daysToReserveFor + ". Please drop by the store within 5 days to pick it up, or it will go back in stock!\n";

	return str;
}