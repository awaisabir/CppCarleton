#ifndef BOOKRENTALPERIOD_H
#define BOOKRENTALPERIOD_H

#include "Transaction.h"

/*  This is a derived class of the Transaction class
 *  It has no data members:
 *	Getters: getProduct : returns the BookstoreInventory pointer
 *	Functions: 
            calOverdueCharge  : Calculates the over-due charge based on the time period of the rental 
            transactionHandle : Pure virtual function from the base class. Calls calOverdueCharge.
 */

class BookRentalPeriod : public Transaction
{
	public:
		BookRentalPeriod(BookstoreInventory*, int, int);
		~BookRentalPeriod();
		string calOverdueCharge();
    	string transactionHandle(BookstoreInventory*, BookstoreInventory* [], int &);

	private:
		int startDate;
		int endDate;

};
#endif