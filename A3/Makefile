OBJ = main.o BMScontrol.o UImanager.o Dlist.o BookArray.o Course.o Book.o BookstoreInventory.o Games.o Technology.o Apparel.o 

a1:	$(OBJ)
	g++ -o a3 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h
	g++ -c BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

Dlist.o:	Dlist.cc Dlist.h Course.h
	g++ -c Dlist.cc

BookArray.o:	BookArray.cc BookArray.h Book.h
	g++ -c BookArray.cc

Course.o:	Course.cc Course.h defs.h
	g++ -c Course.cc

BookstoreInventory.o:	BookstoreInventory.cc BookstoreInventory.h defs.h
	g++ -c BookstoreInventory.cc

Book.o:	Book.cc Book.h defs.h
	g++ -c Book.cc

Games.o:	Games.cc Games.h defs.h
	g++ -c Games.cc

Technology.o:	Technology.cc Technology.h defs.h
	g++ -c Technology.cc

Apparel.o:	Apparel.cc Apparel.h defs.h
	g++ -c Apparel.cc

clean:
	rm -f *.o a3

