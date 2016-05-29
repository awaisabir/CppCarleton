#include "Course.h"
#include <sstream>
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

bool Course ::operator==(const string& c)
{
  return getCode() == c;
}

bool Course:: operator>(Course* c)
{
  return getCode() > c->getCode();
}

string& operator<<(string& out, Course& c)
{
  out += c.printCourses();

  return out;
}

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

string Course::printTextbooks()
{
  return books->printTextBooks();
}

string Course::printCourses()
{
  string str = "";
  string numBook = "";
  string enroll = "";

  if(books->getSize() == 0)
    numBook = "None";
  else
  {
    stringstream ss;
    ss << getNumBooks();
    numBook = ss.str();
  }
  
  stringstream ee;
  ee << getEnrol();
  enroll = ee.str();
  
  str +=  "\nCourse: " + getCode() + " " + getName() +"\n" +
          "Instructor: " + getInstr() +"\n" +
          "Enrolment:  " + enroll  +"\n" +
          "Textbooks:  "  + numBook+ "\n\n"; 

  return str;
}
