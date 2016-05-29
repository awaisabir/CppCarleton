#include <iostream>
#include <sstream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
  : size(0), transactionSize(0)
{
  view = new UImanager();
  courses = new Dlist<Course*>();
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

  for(int i=0; i<transactionSize; i++)
    delete transactions[i];
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
        Dlist<Course*>* courses2add = new Dlist<Course*>();

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
        if(removedCourse != 0) {
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
       }
      else {  
      	//If the user wants to remove more than one course:

      	//Make a temp list
        Dlist<Course*>* listCoursesToRemove = new Dlist<Course*>();

        //Loop over till the user entered number
        while(r > 0)  
        {
        	//get the course code of the list
          string code = view->getCourseCode();

          //find the course in the list using the code and store it in the course pointer
          Course* course;

          //If course(s) is found, alert the user and then add it to the temporary list
          if(courses->findDataForRemoving(code, &course) == 1)
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
      if(newBook != 0)
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

    /**************************************************************************************************************************************************************************
	 *																								OUR NEW FEATURE IS IMPLEMENTED AFTER THIS POINT  ~~INSTRUCTIONS ~~									                            				  *
	 *																																										 																																										  *
	 * ~ All the new functions in the program work only for products already in inventory (Make sure you add alot of products before testing the feature thoroughly).     	    *
	 * ~ Please enter all the information to find a specific product EXACTLY AS ENTERED; or else the program will not be able to find the product.                         	    *
	 * ~ You can only Process all Transactions ONCE. The program will exit once you process all transactions.
	 *																																				                                                                                     							*
	 * ~ Function of the new hierarchy is explained in the specific header files.                                                                                               *
	 *                                                                                                                                                                          *
	 *																		~~~~ Enjoy using this new Customer Transaction(s) feature that has been implemented ~~~~~~~~~~~~~~~~~~~~~~                            *
	 *                                                                                                                                                                          *
	 *                                                                                                                                                                          *
	 ***************************************************************************************************************************************************************************/

	 //if the user wants to buy
    else if (choice == 11)
    {
    	//cout the submenu
      int subChoice;
      view->transactionSubMenu(&subChoice);

      //if wants to buy a book
      if(subChoice == 1) {
      	//get the info for the book to find
        string boughtBookName = view->getInventoryName();
        float  boughtBookPrice = view->getInventoryPrice();
        string boughBookAuthors = view->getBookAuthors();

        //set a product pointer to the found book
        BookstoreInventory* foundBook = findBook(boughtBookName,boughBookAuthors,boughtBookPrice);

        //if its null then don't do anything
        if(foundBook == 0){
          view->itemNotFound();
        } else {
        	//if not then get method of payment. If cash calculate the change/If credit card then no change.
          view->itemFound();
          string method = view->getMethodOfPayment();
          float  userPrice;

          if(method == "Cash"){
           userPrice = view->getUserPrice();
          }

          //Make a new Transaction pointer and add it to the array of Transactions
          Transaction* newBoughtBook = new Buy(foundBook, userPrice, method);
          addTransaction(newBoughtBook);
        }
      }
      //Same concept
      else if(subChoice == 2){
        //APPAREL
        string apparelName  = view->getInventoryName();
        float  apparelPrice = view->getInventoryPrice();
        string apparelSize   = view->getApparelSize();
        string apparelColor = view->getColor();

        BookstoreInventory* foundApparel = findApparel(apparelSize, apparelColor, apparelPrice);

        if(foundApparel == 0){
          view->itemNotFound();
        }
        else{
          view -> itemFound();
          string method = view->getMethodOfPayment();

          float userPrice;
          if(method =="Cash"){
            userPrice = view ->getUserPrice();
          }
          Transaction* newBoughtApparel = new Buy(foundApparel,userPrice,method);
          addTransaction(newBoughtApparel); 
        }

      }
      else if(subChoice == 3){
        //TECHNOLOGY
        string techName  = view->getInventoryName();
        float  techPrice = view->getInventoryPrice();
        string techType   = view->getInventoryType();

        BookstoreInventory* foundTechnology = findTechnology(techName, techType, techPrice);

        if(foundTechnology == 0){
          view->itemNotFound();
        }
        else{
          view -> itemFound();
          string method = view->getMethodOfPayment();

          float userPrice;
          if(method =="Cash"){
            userPrice = view ->getUserPrice();
          }
          Transaction* newBoughtTech = new Buy(foundTechnology,userPrice,method);
          addTransaction(newBoughtTech); 
        }

      }
      else if(subChoice == 4){
        //GAMES
        string gameName  = view->getInventoryName();
        string platform = view->getPlatform();
        float  gamePrice = view->getInventoryPrice();
        string gameType   = view->getInventoryType();

        BookstoreInventory* foundGame = findGame(gameName, platform , gamePrice);

        if(foundGame == 0){
          view->itemNotFound();
        }
        else{
          view -> itemFound();
          string method = view->getMethodOfPayment();

          float userPrice;
          if(method =="Cash"){
            userPrice = view ->getUserPrice();
          }
          Transaction* newBoughtGame = new Buy(foundGame,userPrice,method);
          addTransaction(newBoughtGame); 
        }
      }
    }

    //if user wants to rent a book.
    else if (choice == 12)
    {
      Book* checkBook;
      view->getBookData(&checkBook);

      //get the user input
      int start = view->getStartDate();
      int end = view->getEndDate();

      //make a new transaction pointer
      Transaction* checkRentalPeriod = new BookRentalPeriod(checkBook,start,end);
      addTransaction(checkRentalPeriod);
    }

    //if the user wants to reserve a product 
    else if (choice == 13)
    {
      int subChoice;
      view->transactionSubMenu(&subChoice);

      //if it is a book
      if(subChoice == 1)
      {
      	//get the info to find the book
        string boughtBookName = view->getInventoryName();
        float  boughtBookPrice = view->getInventoryPrice();
        string boughBookAuthors = view->getBookAuthors();

        BookstoreInventory* foundBook = findBook(boughtBookName,boughBookAuthors,boughtBookPrice);

        if(foundBook == 0){
          view->itemNotFound();
        } else {
        	//if it is found then get the info from the user and then make a new reserve product
          view->itemFound();
          string fName = view->getfName();
          string lName = view->getlName();
          string address = view->getAddress();
          string postalCode = view->getPostalCode();
          string daysToReserve = view->getDaysToReserve();

          Transaction* reservedBook = new Reserve(foundBook, fName, lName, address, postalCode,
                                                    daysToReserve);
          addTransaction(reservedBook);
        }
      }

      //if it is an apparel
      else if(subChoice == 2)
      {
        string apparelName  = view->getInventoryName();
        float  apparelPrice = view->getInventoryPrice();
        string apparelSize   = view->getApparelSize();
        string apparelColor = view->getColor();

        BookstoreInventory* foundApparel = findApparel(apparelSize, apparelColor, apparelPrice);

        if(foundApparel == 0){
          view->itemNotFound();
        }
        else{
          view->itemFound(); 

          string fName = view->getfName();
          string lName = view->getlName();
          string address = view->getAddress();
          string postalCode = view->getPostalCode();
          string daysToReserve = view->getDaysToReserve();

          Transaction* reservedApparel = new Reserve(foundApparel, fName, lName, address, postalCode,
                                                    daysToReserve);
          addTransaction(reservedApparel);
        }
      }
      //if it is a technology
      else if(subChoice == 3)
      {
        string techName  = view->getInventoryName();
        float  techPrice = view->getInventoryPrice();
        string techType   = view->getInventoryType();

        BookstoreInventory* foundTechnology = findTechnology(techName, techType, techPrice);

        if(foundTechnology == 0){
          view->itemNotFound();
        }
        else{
          view->itemFound();
          string fName = view->getfName();
          string lName = view->getlName();
          string address = view->getAddress();
          string postalCode = view->getPostalCode();
          string daysToReserve = view->getDaysToReserve();

          Transaction* reservedTechnology = new Reserve(foundTechnology, fName, lName, address, postalCode,
                                                    daysToReserve);
          addTransaction(reservedTechnology);
        }
      }

      //if it is a game
      else if(subChoice == 4)
      {
        string gameName  = view->getInventoryName();
        string platform = view->getPlatform();
        float  gamePrice = view->getInventoryPrice();
        string gameType   = view->getInventoryType();

        BookstoreInventory* foundGame = findGame(gameName, platform , gamePrice);

        if(foundGame == 0){
          view->itemNotFound();
        }
        else{
          view->itemFound();

          string fName = view->getfName();
          string lName = view->getlName();
          string address = view->getAddress();
          string postalCode = view->getPostalCode();
          string daysToReserve = view->getDaysToReserve();

          Transaction* reservedGame = new Reserve(foundGame, fName, lName, address, postalCode,
                                                  daysToReserve);
          addTransaction(reservedGame);
        }
      }
    }

    //if the user wants to return a product
    else if (choice == 14)
    {
      int subChoice;
      view->transactionSubMenu(&subChoice);

      //if it is a book
      if(subChoice == 1)
      {
        Book* returnedBook;
        view->getBookData(&returnedBook);

        Transaction* bookToReturn = new Return(returnedBook);
        addTransaction(bookToReturn);
      }
      	//if it is an apparel
      else if(subChoice == 2)
      {
        Apparel* returnedApparel;
        view->getApparelData(&returnedApparel);

        Transaction* apparelToReturn = new Return(returnedApparel);
        addTransaction(apparelToReturn); 
      }
      //if it is a technology
      else if(subChoice == 3)
      {
        Technology* returnedTech;
        view->getTechnologyData(&returnedTech);

        Transaction* techToReturn = new Return(returnedTech);
        addTransaction(techToReturn); 
      }

      //if it is a game
      else if(subChoice == 4)
      {
        Games* returnedGame;
        view->getGameData(&returnedGame);

        Transaction* gameToReturn = new Return(returnedGame);
        addTransaction(gameToReturn); 
      }
    }
    else if (choice == 15)
    {
      for(int i=0;i<transactionSize;i++)
      {
        view->result(transactions[i]->transactionHandle(transactions[i]->getProduct(), inventory, size));
      }
      view->endPrompt();
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

  if(size < 1){
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
           "Price: $" + price + "\n" +
           "Barcode: " + barcode + "\n\n";
  }

  return str;
}

//add a transaction
void BMScontrol::addTransaction(Transaction* transactionToAdd)
{
  if(transactionSize == MAX_BOOKS)
    return;

  transactions[transactionSize] = transactionToAdd;

  transactionSize++;
}

//find a book
BookstoreInventory* BMScontrol::findBook(string title, string authors, float price)
{
  BookstoreInventory* foundBook = 0;

  if(size == 0){
    foundBook = 0;
    return foundBook;
  }

  for(int i=0; i<size; i++){
    if((title == getInventory(i)->getName()) && (price == getInventory(i)->getPrice()) && (authors == getInventory(i)->returnSpecificAttribute()))
    {
      foundBook = inventory[i];
      return foundBook;
    }
  }
  return foundBook;
}

//find a technology
BookstoreInventory* BMScontrol::findTechnology(string name, string type, float price)
{
  BookstoreInventory* foundTechnology = 0;

  if(size == 0){
    foundTechnology = 0;
    return foundTechnology;
  }

  for(int i=0; i<size; i++){
    if((name == getInventory(i)->getName()) && (price == getInventory(i)->getPrice()) && (type == getInventory(i)->returnSpecificAttribute()))
    {
      foundTechnology = inventory[i];
      return foundTechnology;
    }
  }
  return foundTechnology;
}

//find a game
BookstoreInventory* BMScontrol::findGame(string name, string platform, float price)
{
  BookstoreInventory* foundGame = 0;

  if(size == 0){
    foundGame = 0;
    return foundGame;
  }

  for(int i=0; i<size; i++){
    if((name == getInventory(i)->getName()) && (price == getInventory(i)->getPrice()) && 
      platform == getInventory(i)->returnSpecificAttribute())
    {
      foundGame = inventory[i];
      return foundGame;
    }
  }
  return foundGame;
}

//find an apparel
BookstoreInventory* BMScontrol::findApparel(string color, string brand, float price)
{
  BookstoreInventory* foundApparel = 0;

  if(size == 0){
    foundApparel = 0;
    return foundApparel;
  }

  for(int i=0; i<size; i++){
    if((brand == getInventory(i)->getName()) && (price == getInventory(i)->getPrice()) && 
      (color == getInventory(i)->returnSpecificAttribute()))
    {
      foundApparel = inventory[i];
      return foundApparel;
    }
  }
  return foundApparel;
}