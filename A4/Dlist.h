/*
Dlist class is a class to create a 
doubly linked list that store courses as the data.
*/
#include <iostream>
#include <string>
#include<sstream>
using namespace std;

#ifndef DLIST_H
#define DLIST_H

#include "Course.h"

template <class T>
class Dlist{
  template <class V>
  friend string& operator<<(string&,Dlist<V>&);
  class Node{
    friend class Dlist;
    private:
      Node* next;
      Node* prev;
      T data;
    };
  
    public:
      Dlist();
      ~Dlist();

      Dlist<T>& operator+=(T);
      Dlist<T>& operator+=(Dlist<T>& );
      Dlist<T>& operator-=(T);
      Dlist<T>& operator-=(Dlist<T>& );

      void addData(T);
      void removeData(string);
      int findData(string);
      int findDataForRemoving(string , T*);
      T getData(string);
      string printList();
      string printListDes();
      int listSize() const;

      void cleanup();

    private:
      Node* head;
};


template<class T>
Dlist<T>::Dlist() : head(0) { }


//Dlist destrcutor does not delete the data anymore
template<class T>
Dlist<T>::~Dlist()
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
template<class T>
string& operator<<(string& out, Dlist<T>& list)
{
  out = list.printList();
  return out;
}

/*
Overload the += operator which will add course to the linked list
*/
template<class T>
Dlist<T>& Dlist<T>::operator+=(T data)
{
  addData(data);
  return *this;
}

/*
Overload the += operator which will add every element of courses to the linked list
*/
template<class T>
Dlist<T>& Dlist<T>::operator+=(Dlist<T>& list)
{
  Node* curr = list.head;
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
template<class T>
Dlist<T>& Dlist<T>::operator-=(T data)
{
  if(data == 0)
    return *this;
  removeData(data->getCode());
  return *this;
}

/*
Overload the -= operator which will remove every element of courses from the linked list
*/
template<class T>
Dlist<T>& Dlist<T>::operator-=(Dlist<T>& list)
{
  Node* curr = list.head;
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
template<class T>
void Dlist<T>::addData(T dataToAdd)
{
  Node* currNode = head;
  Node* prevNode = 0;
  Node* nodeToAdd = new Node;
  nodeToAdd->data = dataToAdd;
  nodeToAdd->next = 0;
  nodeToAdd->prev = 0;

  while(currNode != 0)
  {
    if(*(currNode->data) > dataToAdd) //overload this operator
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
template<class T>
void Dlist<T>::removeData(string sameData)
{
  Node* currNode = head;
  Node* prevNode = 0;

  if(currNode == 0)
    return;
  
  while(currNode != 0 )
  {
    if (*(currNode->data) == sameData)  // overload
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
template<class T>
int Dlist<T>::findData(string str)
{
  Node* currNode = head;
  
  while(currNode != 0)
  {
    if(*(currNode->data) == str)   //overload
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
template<class T>
int Dlist<T>::findDataForRemoving(string str, T* c)
{
  Node* currNode = head;
  
  while(currNode != 0)
  {
    if(*(currNode->data) == str) // overload
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
template<class T>
string Dlist<T>::printList()
{
  string output = "";
  Node* currNode = head;
 
  if(currNode == 0) {
   output = "No data";
   return output;
 }
  while(currNode != 0 )
  {
    output << *(currNode->data); 
    currNode = currNode->next;
   }
  return output;
}

/*
 * This function format the list data which is course informations into a string
 * but in descending order
*/
template<class T>
string Dlist<T>::printListDes()
{
  string output = "";
  Node* currNode = head;
 
  if(currNode == 0) {
   output = "No data";
   return output;
  }
  while(currNode->next != 0)
  {
  currNode = currNode->next;
  }
  while(currNode != 0 )
  {
   output << *(currNode->data); 
   currNode = currNode->prev;
  }
  return output;
}

/*
This function take the desired course code as a string and loop over the list 
to check if it exist. 
If yes, it return course pointer pointing to the data
If no, it return null
*/
template<class T>
T Dlist<T>::getData(string str)
{
  Node* currNode = head;
  if(currNode == 0)
    return 0;

  while(currNode != 0)
  {
    if(*(currNode->data) == str)
      return currNode->data;
    
    currNode = currNode->next;
  }
  return 0;  
}

/*
This function return the size of the list
*/
template<class T>
int Dlist<T>::listSize() const
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
template<class T>
void Dlist<T>::cleanup()
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
#endif
