#ifndef RETURN_H
#define RETURN_H

#include <iostream>
using namespace std;

#include "Transaction.h"
#include "defs.h"

/*  This is a derived class of the Transaction class
 *  It has no data members:
 *	Getters: getProduct : returns the BookstoreInventory pointer
 *	Functions: 
            returnProduct     : Adds the product to the array of products and increments the size 
            transactionHandle : Pure virtual function from the base class. Calls calOverdueCharge.
 */


class Return : public Transaction
{
  public:
  	Return(BookstoreInventory*);
  	~Return();

  	BookstoreInventory* getProduct();

  	string compensation();
  	void returnProduct(BookstoreInventory*, BookstoreInventory*[], int&);
  	string transactionHandle(BookstoreInventory*, BookstoreInventory*[],int&);

};
#endif