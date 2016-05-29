/*
 *Course class is a class that will be store as the linked list data
 *It has data members of subj, num, name , instr, enrol, and a BookArray that will store 
 *the pointers to the associate book objects.
*/
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "BookArray.h"

class Course {

  public:
    Course(string="", string="", string="", string="", int=0);
                                                                                                              
    ~Course();
    string  getCode();
    string  getName();
    string  getInstr();
    int     getEnrol();
    int     getNumBooks();
    void    addBook(Book*);
    Book*   getBooks(int);
  private:
    string    subj;
    string    num;
    string    name;
    string    instr;
    int       enrol;
    BookArray* books;
};

#endif

