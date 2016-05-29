#ifndef	RESERVE_H
#define RESERVE_H

#include <iostream>

using namespace std;

#include <string>

/*  This is a derived class of the Transaction class
 *  It has 5 data members: fName, lName, address, postalCode, daysToReserve
 *	Getters: getProduct : returns the BookstoreInventory pointer
 *	Functions: 
       transactionHandle : Pure virtual function from the base class. Returns a string of what item and how long they have reserved the item for.
 */
#include "Transaction.h"

class Reserve : public Transaction
{
	private:
		string fname;
		string lname;
		string address;
		string postalCode;
		string daysToReserveFor;

	public:
		Reserve(BookstoreInventory*, string, string, string, string, string);
		~Reserve();
		BookstoreInventory* getProduct();
		string transactionHandle(BookstoreInventory*, BookstoreInventory* [], int&);

};
#endif