#include <iostream>
using namespace std;
#include <string>
#include "Book.h"

//Book constructor
Book::Book(string t,string n,string b, float p , string a, string i, int e, int y)
   :BookstoreInventory(t,n,b,p), authors(a),isbn(i),edition(e), year(y) {}

Book::~Book()
{
	
}

//getters
string Book::getBarcode()  { return BookstoreInventory::getBarcode(); }
float  Book::getPrice()    { return BookstoreInventory::getPrice(); }
string Book::getName()     { return BookstoreInventory::getName(); }
string Book::getAuthors()  { return authors; }
string Book::getISBN()     { return isbn; }
int    Book::getEdition()  { return edition; }
int    Book::getYear()     { return year; }
string Book::getType()     { return BookstoreInventory::getType(); }
string Book::returnSpecificAttribute() { return getAuthors(); }

