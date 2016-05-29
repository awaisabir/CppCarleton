#include <iostream>
#include <string>
#include<sstream>
using namespace std;

#include "Dlist.h"

Dlist::Dlist() : head(0) { }

//Dlist destrcutor does not delete the data anymore
Dlist::~Dlist()
{
  Node* currNode = head;
  Node* nextNode;

  while(currNode != 0)
  {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}
/* This function overload the << operator that format the linked list
 *into a string containing all the formatted course data */
string& operator<<(string& out, Dlist& list)
{
  out = list.printList();
  return out;
}

/*
Overload the += operator which will add course to the linked list
*/
Dlist& Dlist::operator+=(Course* course)
{
  addCourse(course);
  return *this;
}

/*
Overload the += operator which will add every element of courses to the linked list
*/
Dlist& Dlist::operator+=(Dlist& courses)
{
  Node* curr = courses.head;
  if(curr== 0)
    return *this;

  while(curr != 0)
  {   
    *this += curr->data;
    curr = curr->next;
  }
  return *this;
}

/*
Overload the -= operator which will remove course from the linked list
*/
Dlist& Dlist::operator-=(Course* course)
{
  if(course == 0)
    return *this;
  removeCourse(course->getCode());
  return *this;
}

/*
Overload the -= operator which will remove every element of courses from the linked list
*/
Dlist& Dlist::operator-=(Dlist& courses)
{
  Node* curr = courses.head;
  Node* temp = 0;
  if(curr == 0 )
    return *this;

  while(curr != 0)
  {
      (*this)-= curr->data;
      curr = curr->next;
  }
  return *this;
}

/*
addCourse that takes a course pointer as a parameter.
It creates a new node and add it into the linked list.
*/
void Dlist::addCourse(Course* course)
{
  Node* currNode = head;
  Node* prevNode = 0;
  Node* nodeToAdd = new Node;
  nodeToAdd->data = course;
  nodeToAdd->next = 0;
  nodeToAdd->prev = 0;

  while(currNode != 0)
  {
    if(currNode->data->getCode() > course->getCode())
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  if(prevNode == 0)
    head = nodeToAdd;
  else {
    prevNode->next = nodeToAdd;
  }
  nodeToAdd->prev = prevNode;
  nodeToAdd->next = currNode;

  if(currNode != 0)
  {
    currNode->prev = nodeToAdd;
  }
}

/*
It takes the course code which will be removed and loop over the list
to find the course and delete it from the list
*/
void Dlist::removeCourse(string sameCourse)
{
  Node* currNode = head;
  Node* prevNode = 0;

  if(currNode == 0)
    return;
  
  while(currNode != 0 )
  {
    if (currNode->data->getCode() == sameCourse)
      break;
   
    prevNode = currNode;
    currNode = currNode->next;
  }
  if(currNode == 0)
    return;
 
  if(prevNode == 0)
  { 
     head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  if(currNode->next != 0)
    currNode->next->prev = prevNode;

  delete currNode->data;
  delete currNode;
}

/*
Function that takes the course code  in string as a parameter and checks if it is in the list
return 1 for found
return 0 for not exists
*/
int Dlist::findCourse(string str)
{
  Node* currNode = head;
  
  while(currNode != 0)
  {
    if(currNode->data->getCode() == str)
    {
      
      return 1;
    }
    currNode = currNode->next;
  }

 return 0;
}

/*
This function takes the desired course code and check if it exists
if yes , it set the other parameter (double pointer c) to point to the data
if no, return 0
*/
int Dlist::findCourseForRemoving(string str, Course ** c)
{
  Node* currNode = head;
  
  while(currNode != 0)
  {
    if(currNode->data->getCode() == str)
    {
      *c= currNode->data;
      return 1;
    }
    currNode = currNode->next;
  }

 return 0;
}

/*
This function format the list data which is course informations into a string
*/
string Dlist::printList()
{
  string str = "";
  string numBook = "";
  string enroll = "";

  Node* currNode = head;
 
  if(currNode == 0) {
   str = "No Courses";
   return str;
 }
  while(currNode != 0 )
  {
    if (currNode->data->getNumBooks() == 0)
      numBook =  "None" ;
    else { 
      stringstream ss;
      ss << currNode->data->getNumBooks();
      numBook = ss.str();
    }

    stringstream ee;
    ee << currNode->data->getEnrol();
    enroll = ee.str();
     
    str +=  "\nCourse: " + currNode->data->getCode() + " " +currNode->data->getName() +"\n" +
            "Instructor: " + currNode->data->getInstr() +"\n" +
            "Enrolment:  " + enroll  +"\n" +
            "Textbooks:  "  + numBook+ "\n\n";      

    currNode = currNode->next;
   }
  return str; 
}

/*
 * This function format the list data which is course informations into a string
 * but in descending order
*/
string Dlist::printListDes()
{
  string str = "";
  string numBook = "";
  string enroll = "";

  Node* currNode = head;

  if(currNode == 0) {
    str = "No Courses";
    return str;
  }

  while(currNode->next != 0)
  {
    currNode = currNode->next;
  }
   

  while(currNode != 0)
  { 
    if (currNode->data->getNumBooks() == 0)
      numBook =  "None" ;
    else {
      stringstream ss;
      ss << currNode->data->getNumBooks();
      numBook = ss.str();
    }

    stringstream ee;
    ee << currNode->data->getEnrol();
    enroll = ee.str();
     
    str +=  "\nCourse: " + currNode->data->getCode() + " " +currNode->data->getName() +"\n" +
            "Instructor: " + currNode->data->getInstr() +"\n" +
            "Enrolment:  " + enroll  +"\n" +
            "Textbooks:  "  + numBook+ "\n\n";

    currNode = currNode->prev;
   }
  return str; 
}

/*
This function takes the course pointer to get all its' books information 
and format it into a string to be printed in UI.
*/
string Dlist::printTextBooks(Course* c)
{
  string str = "";
  string edition = "";
  string year = "";
  string price = "";

  if(c->getNumBooks() == 0)
  {
    str = "None";
    return str;
  }
  
  for(int i = 0; i< c->getNumBooks(); i++)
  {
      stringstream ss;
      ss << c->getBooks(i)->getEdition();
      edition = ss.str();
 
      stringstream yy;
      yy << c->getBooks(i)->getYear();
      year = yy.str();

      stringstream aa;
      aa << c->getBooks(i)->getPrice();
      price = aa.str();


       str += "\nTitle: " + c->getBooks(i)->getName() +"\n" +
              "Author: " + c->getBooks(i)->getAuthors() +"\n" +
              "ISBN: " + c->getBooks(i)->getISBN() +"\n" +
              "Edition: "  + edition + "\n"+
              "Year: " + year + "\n" +
              "Price: " + price + "\n" +
              "Barcode: " + c->getBooks(i)->getBarcode() + "\n\n";
  }
  return str;
}

/*
This function take the desired course code as a string and loop over the list 
to check if it exist. 
If yes, it return course pointer pointing to the data
If no, it return null
*/
Course* Dlist::getCourse(string str)
{
  Node* currNode = head;
  if(currNode == 0)
    return 0;

  while(currNode != 0)
  {
    if(currNode->data->getCode() == str)
      return currNode->data;
    
    currNode = currNode->next;
  }
  return 0;  
}

/*
This function return the size of the list
*/
int Dlist::listSize() const
{
  int i = 0;
  Node* currNode = head;
  if(currNode == 0)
    return 0;

  while(currNode != 0)
  {
      currNode = currNode->next;
      i++;
  }
  return i;  
}

/*
This function deletes each node's data which is the list of courses.
*/
void Dlist::cleanup()
{
  Node* currNode = head;
  Node* nextNode;

  while(currNode != 0)
  {
    nextNode = currNode->next;
    delete currNode->data;
    currNode = nextNode;
  }
}