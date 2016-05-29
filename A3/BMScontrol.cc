#include <iostream>
#include <sstream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
  : size(0)
{
  view = new UImanager();
  courses = new Dlist();
}

//destructor 
BMScontrol::~BMScontrol()
{
  delete view;
  //calls cleanup to delete the data of the list
  courses->cleanup();
  //deletes the nodes
  delete courses;

  //deletes each inventory item
  for(int i=0; i<size; i++)
    delete inventory[i];
}


void BMScontrol::launch()
{
  int    choice;
  string code;

  while (1) {
    choice = -1;
    view->mainMenu(&choice);
    if (choice == 0) {
      break;
    }
    //get the number of courses to add
    else if (choice == 1) {
      int c = 0;

      view->getNumCourseToAddOrRemove(&c);
      
      //If 1 course to be added:
      if(c == 1){

      	//Make a new course pointer, get the data and then use the += operator to add it into the list
        Course *newCourse; 
        view->getCourseData(&newCourse);
        *(courses)+= newCourse;
      }
      else{

      	//Make a temporary list
        Dlist* courses2add = new Dlist();

        //loop over till the the number the user entered
        while(c > 0)
        {
        	//Make a new course pointer, get the data, and append it to the temp list
           Course *newCourse;
           view->getCourseData(&newCourse);
           *(courses2add)+= newCourse;
           c--;
        }
        //add the temp list to the original list
       *(courses) += *courses2add;
       delete courses2add;  //delete the temp list
      } 
    }
    else if (choice == 2) {
      int r = 0;
      view->getNumCourseToAddOrRemove(&r);

      if(r == 1){
      	//if one course wants to be removed then get the course and store it
        Course* removedCourse = view->courseToRemove(courses);


        /*Find that specific course in the inventory array and delete it.
         *Shift all the elements back by one after the deletion*/
        for(int i=0;i<removedCourse->getNumBooks();i++)
        {
          BookstoreInventory* bookToRemove = removedCourse->getBooks(i);

          for(int j=0;j<size;j++)
          {
            if(getInventory(j) == bookToRemove)
            {
              delete inventory[j];

              for(int k=j; k<size;k++) 
              {
                inventory[k] = inventory[k+1];
              }
              size--;
            }
          }
        }
        //delete that course from the original list
        *(courses) -= removedCourse;

       }
      else {  
      	//If the user wants to remove more than one course:

      	//Make a temp list
        Dlist* listCoursesToRemove = new Dlist();

        //Loop over till the user entered number
        while(r > 0)  
        {
        	//get the course code of the list
          string code = view->getCourseCode();

          //find the course in the list using the code and store it in the course pointer
          Course* course;

          //If course(s) is found, alert the user and then add it to the temporary list
          if(courses->findCourseForRemoving(code, &course) == 1)
          {
            view->courseFound();
           *(listCoursesToRemove)+= course;

           //delete the books of that course from the inventory array
            for(int i=0;i<course->getNumBooks();i++)
            {
              BookstoreInventory* bookToRemove = course->getBooks(i);

              for(int j=0;j<size;j++)
              {
                if(getInventory(j) == bookToRemove)
                {
                  delete inventory[j];

                  for(int k=j; k<size;k++) 
                  {
                    inventory[k] = inventory[k+1];
                  }
                  size--;
                }
              }
            }
          } else {
            view->courseNotFound();
          }
         r--;
        }

        //delete the courses from the original list
        *(courses) -= *listCoursesToRemove; 

        //delete the temporary list
        delete listCoursesToRemove; 
      }
    }
    else if (choice == 3) {

      view->printCourses(courses);
      
    }
    else if (choice == 4) {

      Book *newBook;
      view->addTextBook(courses, &newBook);
      addInventory(newBook);
    }

    else if (choice == 5) {

      view->printBooks(courses);     
    }

    else if (choice == 6)
    {
      Book *newBook;
      view->getBookData(&newBook);
      addInventory(newBook);
    }

    else if (choice == 7)
    {
      Technology* newTechnology;
      view->getTechnologyData(&newTechnology);
      addInventory(newTechnology);
    }

    else if (choice == 8)
    {
      Apparel* newApparel;
      view->getApparelData(&newApparel);
      addInventory(newApparel);
    }

    else if (choice == 9)
    {
      Games* newGame;
      view->getGameData(&newGame);
      addInventory(newGame);
    }

    else if (choice == 10)
    {
      view->printInventory(printInventory());
    }
    view->pause();
  }
}

//add inventory
void BMScontrol::addInventory(BookstoreInventory* inventoryToAdd)
{
  if(size == MAX_BOOKS)
    return;

  inventory[size] = inventoryToAdd;
  size++;
}

//get inventory
BookstoreInventory* BMScontrol::getInventory(int index)
{
  if(index < 0 || index > size)
    return 0;

  return inventory[index];
}

//print inventory
string BMScontrol::printInventory()
{
  string str;

  string price, barcode;

  if(size == 0){
    str = "No Inventory in stock!";
    return str;
  }
  
  for(int i=0; i<size; i++)
  {
    stringstream aa;
    aa << getInventory(i)->getPrice();
    price = aa.str();

    stringstream bb;
    bb << getInventory(i)->getBarcode();
    barcode = bb.str();
  
    str += "\nType: " + getInventory(i)->getType() + "\n" +
           "Name: " + getInventory(i)->getName() + "\n" +
           "Price: " + price + "\n" +
           "Barcode: " + barcode + "\n\n";
  }

  return str;
}