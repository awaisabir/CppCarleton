#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course" << endl;
  cout << "  ( 2 )  List all courses" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 3 )  Add textbook" << endl;
  cout << "  ( 4 )  List course textbooks" << endl << endl;

  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 4) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

//Changed the parameter to a double pointer
void UImanager::getCourseData(Course** course)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;

  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }
  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  ";
  getline(cin, name);

  cout << endl << "Enter instructor name:   ";
  getline(cin, inst);

  cout << endl << "Enter enrolment:   ";
  getline(cin, str);
  stringstream ss(str);

  ss >> enrol;
  
  //allocate memory for the new course
  Course* tmpCourse = new Course(subj, num, name, inst, enrol);
  //dereference the pointer once and set it equal to the temp course
  *course = tmpCourse;

}


//function to get the book data
void UImanager::getBookData(Book** book)
{
  string str = "";
  string name, author, isbn;
  int edition, year;
  
  cout << endl;
  
  //prompt the user to enter textbook name
  cout << "Enter the textbook name:  ";
  getline(cin, name);
  
  //prompt the user to enter author name
  cout << endl << "Enter the Author:  ";
  getline(cin, author);

  //prompt the user to enter the isbn
  cout << endl << "Enter the ISBN of the book:   ";
  getline(cin, isbn);

  //prompt the user to enter the edition
  cout << endl << "Enter the Edition Number:   ";
  getline(cin, str);
  stringstream ss(str);
  ss >> edition;

  //prompt the user to enter year of publication
  cout << endl << "Enter the Year of Publication:   ";
  getline(cin, str);
  stringstream bb(str);
  bb >> year;


  //make a tempbook pointer and allocate memory for it
  Book* tmpBook = new Book(name, author, isbn, edition, year);
  //dereference the double pointer once and set it equal to the tempBook pointer
  *book = tmpBook;
  
}


//function to check whether the course exists or not
int UImanager::checkCourse(CourseArray* courseArray, int* index)
{
  string str = "";
  
  //prompt the user to enter the course code
  while (str.length() != 8) {
     cout << "Enter course code:  ";
     getline(cin, str);
   }

  //loop through the size of the courseArray
  for(int i = 0; i < courseArray->getSize(); i++)
  {
    //if the entered course exists in the array:
    if(courseArray->getCourse(i)->getCode() == str)
     {
       //change the value of index to i
       *index = i;
       //print "The course has been found
       cout << "The course has been found!" << endl;
       
       return 1;
     }

  }
  cout << endl;
  //if nothing happens then the specified course does not exist
  cout<< "This specified course does not even exist!" << endl;

  return -1;
}


void UImanager::printCourses(CourseArray *arr)
{
  cout << endl << endl << "ALL COURSES:" << endl << endl;
  for (int i=0; i<arr->getSize(); ++i) {

    Course* c = arr->getCourse(i);
    cout << "Course:     " << c->getCode()  << "  " << c->getName() << endl;
    cout << "Instructor: " << c->getInstr()  << endl;
    cout << "Enrolment:  " << c->getEnrol() << endl;
    cout << "Textbooks:  "  ;
    if (c->getNumBooks() == 0) {
      cout << "None" << endl;
    }
    else {
      //print the number of books 
      cout<< c->getNumBooks() << endl;
    }
    cout << endl;
  }
}

//print books function
void UImanager::printBooks(CourseArray *arr)
{
  string str = "";
  //promp the user to enter a course
  while (str.length() != 8) {
     cout << "Enter course code:  ";
     getline(cin, str);
   }
  
  //make a course pointer
  Course* p;
  int i;

  //loop through the array till the size
  for(i = 0; i<arr->getSize();i++)
  {
    //set the value of p to be the first course
    p = arr->getCourse(i);

    //if the course code exists and the number of books is 0
    if (arr->getCourse(i)->getCode() == str && p->getNumBooks() == 0)
    {
      //tell the user this course has no books
      cout << "This course has no books!" <<endl;
      break;
    }
    //else if the code exists and the books also exist
    else if(arr->getCourse(i)->getCode() == str && p->getNumBooks() != 0)
    {    
       //print the books
       for(int j = 0; j < p->getNumBooks(); j++)
       {	
         cout<<endl;
         cout<< "Title: "   << p->getBooks(j)-> getTitle() <<endl;
         cout<< "Authors: " << p->getBooks(j)-> getAuthors() <<endl;
         cout<< "ISBN: "<< p->getBooks(j)-> getISBN() <<endl;
         cout<< "Edition: "<< p->getBooks(j)-> getEdition() <<endl; 
         cout<< "Year: "<< p->getBooks(j)-> getYear() <<endl; 
         cout<< endl;
       }
      break;
    }
  }

    //if the index is at the size and the book is still not found then the course does not exist
    if(i == arr->getSize() && arr->getCourse(arr->getSize()-1)->getCode() != str)
    cout<< "This course does not exist!" <<endl;
}

void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

