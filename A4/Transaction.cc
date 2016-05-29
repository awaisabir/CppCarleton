#include <iostream>
using namespace std;

#include <string>

#include "Transaction.h"

Transaction::Transaction(BookstoreInventory* p) : product(p) { }

Transaction::~Transaction()
{
}

BookstoreInventory* Transaction::getProduct()  { return product; }

