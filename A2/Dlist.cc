#include <iostream>
#include <string>
#include<sstream>
using namespace std;

#include "Dlist.h"

Dlist::Dlist() : head(0) { }

Dlist::~Dlist()
{
  Node* currNode = head;
  Node* nextNode;

  while(currNode != 0)
  {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

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

int Dlist::findCourse(string str)
{
  Node* currNode = head;
  
  while(currNode != 0)
  {
    if(currNode->data->getCode() == str)
      return 1;
    
    currNode = currNode->next;
  }

 return 0;
}

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

string Dlist::printTextBooks(Course* c)
{
  string str = "";
  string edition = "";
  string year = "";

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

       str += "\nTitle: " + c->getBooks(i)->getTitle() +"\n" +
              "Author: " + c->getBooks(i)->getAuthors() +"\n" +
              "ISBN: " + c->getBooks(i)->getISBN() +"\n" +
              "Edition: "  + edition + "\n"+
              "Year: " + year +"\n\n";
  }
  return str;
}

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
