#include "Book.h"

Book::Book(string t, string a, string i, int e, int y)
{
   title   = t;
   authors = a;
   isbn    = i;
   edition = e;
   year    = y;
}

string Book::getTitle()    { return title; }
string Book::getAuthors()  { return authors; }
string Book::getISBN()     { return isbn; }
int    Book::getEdition()  { return edition; }
int    Book::getYear()     { return year; }

