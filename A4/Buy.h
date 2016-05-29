#ifndef BUY_H
#define BUY_H

#include <iostream>
using namespace std;

#include "Transaction.h"

/*  This is a derived class of the Transaction class
 *  It has 2 data members: userPrice and methodOfPayment
 *	Getters: getProduct : returns the BookstoreInventory pointer
 *	Functions: removeInventory   : Removes the specific item from an array of products and decrements the size of that array
               changeDue         : Calculates the change based on the userPrice and the price of the product
               transactionHandle : Pure virtual function from the base class. Calls changeDue and removeInventory.
 */

class Buy : public Transaction
{
	private:
		float userPrice;
		string methodOfPayment;

	public:
		Buy(BookstoreInventory*, float, string);
		~Buy();

		BookstoreInventory* getProduct();
		void   removeInventory(BookstoreInventory*, BookstoreInventory* [], int&);
		string changeDue();
	 	string transactionHandle(BookstoreInventory*, BookstoreInventory* [], int&);
};
#endif