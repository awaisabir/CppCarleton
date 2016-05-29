#ifndef TRANSACTION_H
#define TRANSACTION_H

/*  This is our base abstract class for our new hierarchy. Our hierarchy is called Transactions
 * 	This class contains a BookstoreInventory pointer as its only parameter
 *	The destructor is virtual so that the base class destructors can be called
 *  Our pure virtual function is called transactionHandle.
 */


#include "BookstoreInventory.h"

class Transaction
{
	private:
		BookstoreInventory* product;

	public:
		Transaction(BookstoreInventory*);
		BookstoreInventory* getProduct();
		virtual  ~Transaction();

		virtual  string transactionHandle(BookstoreInventory*, BookstoreInventory* [], int&) = 0;
};

#endif