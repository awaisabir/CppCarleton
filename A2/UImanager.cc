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
  cout << "  ( 2 )  Remove course" << endl;
  cout << "  ( 3 )  List all courses" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 4 )  Add textbook" << endl;
  cout << "  ( 5 )  List course textbooks" << endl << endl;
  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 5) {
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
  Course* tmpCourse = new Course(subj, num, name, inst, enrol);

  *course = tmpCourse;

}


//function to get the book data
void UImanager::getBookData(Book** book)
{
  string str = "";
  string name, author, isbn;
  int edition, year;
  
  cout << endl;
  
  cout << "Enter the textbook name:  ";
  getline(cin, name);

  cout << endl << "Enter the Author:  ";
  getline(cin, author);

  cout << endl << "Enter the ISBN of the book:   ";
  getline(cin, isbn);

  cout << endl << "Enter the Edition Number:   ";
  getline(cin, str);
  stringstream ss(str);
  ss >> edition;

  cout << endl << "Enter the Year of Publication:   ";
  getline(cin, str);
  stringstream bb(str);
  bb >> year;


  Book* tmpBook = new Book(name, author, isbn, edition, year);
  *book = tmpBook;
  
}

void UImanager :: courseToRemove(Dlist* list)
{
  string str = "";

  while (str.length() != 8) {
     cout << "Enter course code:  ";
     getline(cin, str);
   }
  if(list->findCourse(str) == 1)
    list->removeCourse(str);
  else
    cout<< "Course is not found";
}


void UImanager :: addTextBook(Dlist* list, Book** book)
{
  string str = "";

  while (str.length() != 8) {
     cout << "Enter course code:  ";
     getline(cin, str);
   }
  if(list->findCourse(str) == 1)
  {
    getBookData(book);
    list->getCourse(str)->addBook(*book);
  } else {
     cout<<"Course not found!"<<endl;
  }
}


void UImanager::printCourses(Dlist* list)
{
  string str = "";
  string asc = "1";
  string des = "2";

  while(str !=  asc && str != des)
  {
    cout<<"\n1.Ascending order"<<endl;
    cout<<"2.Descending order\n"<<endl;
    cout << "Enter 1 or 2:  ";
    getline(cin,str);
  }
  if(str == asc)
    cout<< list->printList();
  else 
   cout <<list->printListDes();
}


//print books function
void UImanager::printBooks(Dlist *list)
{
  string str = "";

  while (str.length() != 8) {
     cout << "Enter course code:  ";
     getline(cin, str);
   }
  
  if(list->getCourse(str) == 0)
  {
    cout<<"Course is not found!\n";
  }
  else
  {
    cout<< list->printTextBooks(list->getCourse(str));
  }
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

