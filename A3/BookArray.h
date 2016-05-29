/*
 *BookArray class is used to store pointers to a
 *list of books object that belongs to a course.
 *So every course will have a BookArray by default.
*/
#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include "Book.h"

class BookArray
{
  public:
    BookArray();
    ~BookArray();
    void add(Book*);
    Book* getBook(int);
    int  getSize();
  private:
    int  size;
    Book* books[MAX_BOOKS];
};

#endif
