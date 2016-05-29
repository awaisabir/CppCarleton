#include <iostream>
using namespace std;

#include <string>
#include <sstream>

#include "Return.h"

//constructor
Return::Return(BookstoreInventory* p) 
       : Transaction(p)
{

}

//destructor
Return::~Return()
{
  delete getProduct();
}


BookstoreInventory* Return::getProduct()
{
	return Transaction::getProduct();
}

//function to return the refund on a product
string Return::compensation()
{
	string returnPrice = "";
	stringstream ss;
	ss << getProduct()->getPrice();
	returnPrice = ss.str();

	return "\nFor return: Since you have returned " + getProduct()->getName() + 
				 ". Your refund is $" + returnPrice + " !\n";
}

//Function to add the returned product back into the product array
void Return::returnProduct(BookstoreInventory* productToReturn, BookstoreInventory* array[], int& arraySize)
{
	if(arraySize == MAX_BOOKS)
		return;

	array[arraySize] = productToReturn;

	arraySize++;
}

//calls the two functions
string Return::transactionHandle(BookstoreInventory* productToReturn, BookstoreInventory* array[], int& arraySize)
{
	string str = "";

	returnProduct(productToReturn, array, arraySize);
	str = compensation();

	return str;
}