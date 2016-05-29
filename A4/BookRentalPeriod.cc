#include <iostream>
#include <string>
#include <sstream>
#include "BookRentalPeriod.h"

//constructor
BookRentalPeriod::BookRentalPeriod(BookstoreInventory* p, int s, int e)
				 : Transaction(p), startDate(s), endDate(e)
{

}

//destructor
BookRentalPeriod::~BookRentalPeriod()
{
	
}

//funcion to calculate the charge on an overdue product
string BookRentalPeriod::calOverdueCharge()
{
	int overdueDate = 0;
	int charge = 0;
	string result = "";
	overdueDate = endDate - startDate;

	if(overdueDate > 5)
	{
		string chargePrice = "";
		charge = overdueDate * 0.15;
		stringstream ss;
		ss<< charge;
		chargePrice = ss.str();

		result = "\nFor Rent a Book : **For each day above the 5 day rental period, you will have to pay 15 percent of the price of the book.** \nYou have to pay $ " + chargePrice + "\n";
		return result;
	}
	result = "No charge\n";
	return result;
}

//calls the otehr function
string BookRentalPeriod::transactionHandle(BookstoreInventory* p, BookstoreInventory* array[], int& size)
{
	return calOverdueCharge();
}