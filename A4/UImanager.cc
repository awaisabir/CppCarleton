#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UImanager.h"

using namespace std;



void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course(s)" << endl;
  cout << "  ( 2 )  Remove course(s)" << endl;
  cout << "  ( 3 )  List all courses" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 4 )  Add textbook" << endl;
  cout << "  ( 5 )  List course textbooks" << endl << endl;
  cout << "  Inventory Management:" << endl;
  cout << "  ( 6 )  Add Book (Not part of any Course): " <<endl;
  cout << "  ( 7 )  Add Technology (eg: Laptops, Printers and Phones)" << endl;
  cout << "  ( 8 )  Add Apparel" << endl;
  cout << "  ( 9 )  Add Games"  << endl;
  cout << "  ( 10 ) Print Inventory" << endl << endl;
  cout << "   Customer Interaction/Transaction:" <<endl; 
  cout << "  ( 11 ) Buy a Product"<<endl;
  cout << "  ( 12 ) Rent a Book"<<endl;
  cout << "  ( 13 ) Reserve a Product" <<endl;
  cout << "  ( 14 ) Return a Product"  << endl <<endl;
  cout << "  ( 15 ) Proccess all Transactions" <<endl <<endl <<endl; 
  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 15) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::transactionSubMenu(int* subChoice)
{
  string str;

  *subChoice = -1;

  cout << endl << "What product would you like to perform the action on? " <<endl <<endl;
  cout << "  ( 1 )  Book" <<endl;
  cout << "  ( 2 )  Apparel" <<endl;
  cout << "  ( 3 )  Techology" <<endl;
  cout << "  ( 4 )  Games" <<endl <<endl;

  while(*subChoice < 0 || *subChoice > 4){
    cout << "Enter your selection:  ";
    *subChoice = getInt();
  }
}

//Function to get the course code
string UImanager::getCourseCode()
{
  string codeToDel ="";

    while (codeToDel.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, codeToDel);
  }
 return codeToDel;
}

//Function to get course data
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

  cout<<"\n========================================================================="<< endl;
}

//Function to get the number of courses to add or remove
void UImanager::getNumCourseToAddOrRemove(int *c)
{
  while(*c < 1)
  {
    cout<< "\nHow many courses do you want to add or remove: ";
    *c = getInt();
  }
}


//Function to get the book data
void UImanager::getBookData(Book** book)
{
  string str = "";

  float price;
  string type, barcode, name, author, isbn;
  int edition, year;
  
  cout << endl;
  
  cout << endl <<"Enter the textbook name:  ";
  getline(cin, name);

    cout<< endl <<"Enter the price(e.g: $99.99):  $";
    while(getline(cin, str)){
    stringstream aa(str);
    if(aa >> price)
    {
      if(aa.eof()){
        break;
      }
    }
   cout<< endl <<"Enter the price(e.g: $99.99):  $";
  }

  cout<< endl <<"Enter the genre (type) of the book: ";
  getline(cin, type);

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

  while(barcode.length() != 12) {
  	cout<< endl << "Enter the barcode of the book(12 alphanumeric characters):    ";
  	getline(cin, barcode);
  }

  Book* tmpBook = new Book(type, name, barcode, price, author, isbn, edition, year);
  *book = tmpBook;
  
}

//Function to get the tecnology data
void UImanager::getTechnologyData(Technology** technology)
{
  string str = "";

  string type, name, barcode, serialNumber;
  float price;
  int warrantyPeriod;

  cout<< endl <<"Enter the type: ";
  getline(cin, type);

  cout<< endl<< "Enter the brand name: ";
  getline(cin,name);

  while(barcode.length() != 12) {
  	cout<< endl <<"Enter the barcode of the technology(12 alphanumeric characters): ";
  	getline(cin, barcode);
  }

    cout<< endl <<"Enter the price(e.g: $99.99):  $";
    while(getline(cin, str)){
    stringstream aa(str);
    if(aa >> price)
    {
      if(aa.eof()){
        break;
      }
    }
   cout<< endl <<"Enter the price(e.g: $99.99):  $";
  }


  cout<<  endl <<"Enter warranty period: ";
  getline(cin,str);
  stringstream bb(str);
  bb >> warrantyPeriod;

  cout<< endl<< "Enter Serial Number: ";
  getline(cin,serialNumber);

  Technology* tempTechnology = new Technology(type, name, barcode, price, warrantyPeriod, serialNumber);
  *technology = tempTechnology;
}

//Function to get the apparel data
void UImanager::getApparelData(Apparel** apparel)
{
	string str="";
	string type, name, size, color, barcode;
	float price;

	cout<< endl <<"Enter the type: ";
	getline(cin, type);

	cout<< endl <<"Enter the brand name: ";
	getline(cin, name);

	while(barcode.length() != 12) {
		cout<< endl <<"Enter the barcode(12 alphanumeric characters): ";
		getline(cin,barcode);
	}


    cout<< endl <<"Enter the price(e.g: $99.99):  $";
    while(getline(cin, str)){
    stringstream aa(str);
    if(aa >> price)
    {
      if(aa.eof()){
        break;
      }
    }
   cout<< endl <<"Enter the price(e.g: $99.99):  $";
  }

	cout<< endl <<"Enter the size(S/M/L/XL): ";
	getline(cin, size);

	cout<< endl <<"Enter the color: ";
	getline(cin,color);

	Apparel* tempApparel = new Apparel(type, name, barcode, price, size, color);
	*apparel = tempApparel;
}

//Function to get the games data
void UImanager::getGameData(Games** game)
{
	string str="";
	string name, barcode, platform, genre;
	float price;
	int rentalPeriod;

	cout<< endl<<"Enter the genre(type): ";
	getline(cin, genre);

	cout<< endl<<"Enter the name: ";
	getline(cin,name);

	while(barcode.length() != 12) {
		cout<< endl<<"Enter the barcode(12 alphanumeric characters): ";
		getline(cin,barcode);
	}

    cout<< endl <<"Enter the price(e.g: $99.99):  $";
    while(getline(cin, str)){
    stringstream aa(str);
    if(aa >> price)
    {
      if(aa.eof()){
        break;
      }
    }
   cout<< endl <<"Enter the price(e.g: $99.99):  $";
  }


	cout<< endl <<"Enter the platfform: ";
	getline(cin, platform);


	cout<< endl <<"Enter the rental period: ";
	getline(cin,str);
	stringstream bb(str);
	bb >> rentalPeriod;

	Games* tempGame = new Games(genre, name, barcode, price, platform, rentalPeriod);
	*game = tempGame;
}

//Function to find the course to remove
Course* UImanager::courseToRemove(Dlist<Course*>* list)
{
  string str = "";

  while (str.length() != 8) {
     cout << "Enter course code:  ";
     getline(cin, str);
   }
  if(list->findData(str) == 1)
  {
  	courseFound();
    return list->getData(str);
  }
  else
  {
    courseNotFound();
    return 0;
  }
}

//Function to add a textbook
void UImanager::addTextBook(Dlist<Course*>* list, Book** book)
{
  string str = "";

  while (str.length() != 8) {
     cout << "Enter course code:  ";
     getline(cin, str);
   }
  if(list->findData(str) == 1)
  {
  	courseFound();
  	getBookData(book);
    list->getData(str)->addBook(*book);
  } else {
      *book = 0;
     courseNotFound();
  }
}

//Function to prin the courses
void UImanager::printCourses(Dlist<Course*>* list)
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
  if(str == asc){
    string output ="";
    output << *list;
    cout << output;
  }
  else 
   cout <<list->printListDes();
}

//Function to prin the books
void UImanager::printBooks(Dlist<Course*>* list)
{
  string str = "";

  while (str.length() != 8) {
     cout << "Enter course code:  ";
     getline(cin, str);
   }
  
   Course* course = list->getData(str);

  if(course == 0)
  {
    courseNotFound();
  }
  else
  {
    cout << course->printTextbooks();
    //cout<< list->printTextBooks(list->getData(str));
  }
}

void UImanager::printInventory(string str)
{
  cout<<"\n"+str;
}


void UImanager::courseNotFound()
{
    cout<<"\nCourse is not found!"<<endl;
}
void UImanager::courseFound()
{
	cout<<"\nCourse is found!"<<endl;
}

void UImanager::itemNotFound()
{
  cout<<"\nItem is not found in Inventory! "<<endl;
}

void UImanager::itemFound()
{
  cout<<"\nItem is found in Inventory! "<<endl;
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

string UImanager::getInventoryName()
{
  string name = "";

  cout << endl << "Enter the name: ";
  getline(cin, name);

  return name;
}

float UImanager::getInventoryPrice()
{
  string str;
  float price;

  cout<< endl <<"Enter the price(e.g: $99.99):  $";

  while(getline(cin, str)){
    stringstream aa(str);
    if(aa >> price)
    {
      if(aa.eof()){
        break;
      }
    }
   cout<< endl <<"Enter the price(e.g: $99.99):  $";
  }
  return price;
}


string UImanager::getBookAuthors()
{
  string author = "";

  cout<< endl << "Enter the author(s): ";
  getline(cin,author);

  return author;
}

string UImanager::getInventoryType()
{
  string type ="";

  cout <<endl<< "Enter the type: ";
  getline(cin,type);

  return type;

}

string UImanager::getPlatform()
{
  string platform ="";

  cout <<endl<< "Enter the platform: ";
  getline(cin,platform);

  return platform;

}
string UImanager::getMethodOfPayment()
{
  string method = "";
  while(method != "Credit Card" && method != "Cash")
  {
      cout<< endl << "Please enter how you want to pay of this transation(Credit Card/Cash(EXACTLY AS STATED)): ";
      getline(cin, method);
  }

  return method;
}

float UImanager::getUserPrice()
{
  string userPrice = "";
  float  price;

  cout<< endl << "Enter the amount you want to pay:  $";
  while(getline(cin, userPrice)){
    stringstream aa(userPrice);
    if(aa >> price)
    {
      if(aa.eof()){
        return price;
      }
    }
   cout<< endl <<"Enter the amount you want to pay:  $";
  }
  return 0.0f;
}

string UImanager::getApparelSize()
{
  string size = "";
  cout<<endl<< "Enter the size of the Apparel: ";
  getline(cin, size);

  return size;
}

string UImanager::getColor()
{
  string color = "";
  cout<<endl <<  "Enter the color of the Apparel: ";
  getline(cin,color);

  return color;
}

int UImanager::getStartDate()
{
  string date = "";
  cout<<endl<<"Enter the starting date of your rental (ex. 10): ";
  getline(cin,date);
  int dateInput ;
  istringstream(date) >> dateInput;
  return dateInput;
}

int UImanager::getEndDate()
{
  string date = "";
  cout<<endl<<"\nEnter the date you want to return this book (ex. 30): ";
  getline(cin,date);
  int dateInput ;
  istringstream(date) >> dateInput;
  return dateInput;
}

string UImanager::getfName()
{
  string fName = "";


  cout << endl <<"Enter your First Name: ";
  getline(cin, fName);

  return fName;
}

string UImanager::getlName()
{
  string lName = "";
  cout << endl<< "Enter your Last Name: ";
  getline(cin, lName);

  return lName;
}

string UImanager::getAddress()
{
  string address = "";

  cout << endl<<"Enter your Address: ";
  getline(cin, address);

  return address;
}

string UImanager::getPostalCode()
{
  string postalCode = "";

  cout << endl<<"Enter your Postal Code: ";
  getline(cin, postalCode);

  return postalCode;
}

string UImanager::getDaysToReserve()
{
  string daysToReserve = "";
  
  cout << endl<<"Enter the number of days to Reserve: ";
  getline(cin, daysToReserve);

  return daysToReserve;
}

void UImanager::result(string result)
{
  cout << endl << result <<endl;
}

void UImanager::endPrompt()
{
  cout << endl << endl << "Thank you for Checking out. It was a pleasure having you! " <<endl;
}