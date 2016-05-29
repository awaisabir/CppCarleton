#include "Course.h"

//constructor
Course::Course(string s, string nu, string na, string i, int e)
{
   subj  = s;
   num   = nu;
   name  = na;
   instr = i;
   enrol = e;
   books = new BookArray();
}

//destructor
Course::~Course()          
{
	//deletes the book array object
  delete books;
}
string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()     { return enrol; }

//get total number of books
int    Course::getNumBooks()  { return books->getSize(); }

//add book
void   Course::addBook(Book* b)  
{ 
  books->add(b);
}

//get a book at a particualr index
Book* Course::getBooks(int i)
{
  return books->getBook(i);
}

