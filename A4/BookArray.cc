#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "BookArray.h"

BookArray::BookArray() 
{ 
  size = 0;
}
/*BookArray destructor does not have any implementation because we will delete
* the book object when a course is removed, we delete the object from our inventory array pointer
* As any book that belongs to a course will be also added to our inventory array.
*/

BookArray::~BookArray()   
{

}

int   BookArray::getSize()         { return size; }
Book*  BookArray::getBook(int i)   { return books[i]; }

void BookArray::add(Book* book)
{
  if (size == MAX_BOOKS)
    return;

  books[size] = book;
  size++;

}

string BookArray::printTextBooks()
{
  string str = "";
  string edition = "";
  string year = "";
  string price = "";

  if(size == 0)
  {
    str = "None";
    return str;
  }
  
  for(int i = 0; i< size; i++)
  {
      stringstream ss;
      ss << getBook(i)->getEdition();
      edition = ss.str();
 
      stringstream yy;
      yy << getBook(i)->getYear();
      year = yy.str();

      stringstream aa;
      aa << getBook(i)->getPrice();
      price = aa.str();


       str += "\nTitle: " + getBook(i)->getName() +"\n" +
              "Author: " + getBook(i)->getAuthors() +"\n" +
              "ISBN: " + getBook(i)->getISBN() +"\n" +
              "Edition: "  + edition + "\n"+
              "Year: " + year + "\n" +
              "Price: " + price + "\n" +
              "Barcode: " + getBook(i)->getBarcode() + "\n\n";
  }
  return str;
}

