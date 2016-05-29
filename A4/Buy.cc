#include <iostream>
using namespace std;

#include <string>
#include <sstream>

#include "Buy.h"

Buy::Buy(BookstoreInventory* p, float pr, string m) : Transaction(p), userPrice(pr), methodOfPayment(m)
{

}

Buy::~Buy()
{
	delete getProduct();
}

BookstoreInventory* Buy::getProduct()
{
	return Transaction::getProduct();
}

//Function to calculate the change
string Buy::changeDue()
{
	string str = "";
	if(methodOfPayment == "Credit Card")
	{
		return "\nYour change is $0.00. Thank you for buying " + getProduct()->getName() + "\n"; 
	}
	else 
	{
		if(userPrice > getProduct()->getPrice())
		{
			float change = userPrice - getProduct()->getPrice();
			stringstream ss;
			ss << change;
			str = ss.str();

			string statement = "\nPurchase : Your change is $" + str + ". Thank you for buying " + getProduct()->getName() + "\n";
			return statement;
		}
	}
	return "";
}

//Function to remove the inventory from the array of products
void Buy::removeInventory(BookstoreInventory* product, BookstoreInventory* array[], int& arraySize)
{
	if(arraySize == 0)
    return;

  for(int i=0; i<arraySize; i++)
  {
    if(product == array[i])
    {
      for(int j=i; j<arraySize; j++){
        array[j] = array[j+1];
      }
      arraySize--;
      break;
    }
  }
}

//calls the two other functions
string Buy::transactionHandle(BookstoreInventory* product, BookstoreInventory* array[], int& arraySize)
{
  string change = changeDue();
  removeInventory(product,array,arraySize);

  return change;
}