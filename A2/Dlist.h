#ifndef DLIST_H
#define DLIST_H

#include "Course.h"

class Dlist{

 class Node{
 
  friend class Dlist;
  private:
  Node* next;
  Node* prev;
  Course* data;
  };
  
  public:
  Dlist();
  ~Dlist();
  void addCourse(Course*);
  void removeCourse(string);
  int findCourse(string);
  Course* getCourse(string);
  string printList();
  string printListDes();
  string printTextBooks(Course* );

  private:
  Node* head;
};


#endif
