OBJ = main.o BMScontrol.o UImanager.o BookArray.o Course.o Book.o BookstoreInventory.o Games.o Technology.o Apparel.o Transaction.o Buy.o Return.o BookRentalPeriod.o Reserve.o

a1:	$(OBJ)
	g++ -o a4 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h Dlist.h
	g++ -c BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

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

Transaction.o:	Transaction.cc Transaction.h defs.h
	g++ -c Transaction.cc

Buy.o:	Buy.cc Buy.h defs.h
	g++ -c Buy.cc

Return.o: Return.cc Return.h defs.h
	g++ -c Return.cc

BookRentalPeriod.o: BookRentalPeriod.cc BookRentalPeriod.h defs.h
	g++ -c BookRentalPeriod.cc

Reserve.o : Reserve.cc Reserve.h defs.h
	g++ -c Reserve.cc
	
clean:
	rm -f *.o a4

