#include <iostream>
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

