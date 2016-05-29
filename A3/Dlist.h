/*
Dlist class is a class to create a 
doubly linked list that store courses as the data.
*/
#ifndef DLIST_H
#define DLIST_H

#include "Course.h"

class Dlist{
  friend string& operator<<(string&,Dlist& );
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

      Dlist& operator+=(Course*);
      Dlist& operator+=(Dlist& );
      Dlist& operator-=(Course*);
      Dlist& operator-=(Dlist& );
      
      void addCourse(Course*);
      void removeCourse(string);
      int findCourse(string);
      int findCourseForRemoving(string , Course ** );
      Course* getCourse(string);
      string printList();
      string printListDes();
      string printTextBooks(Course* );
      int listSize() const;

      void cleanup();

    private:
      Node* head;
};


#endif
