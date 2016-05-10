OBJ = main.o BMScontrol.o UImanager.o CourseArray.o BookArray.o Course.o Book.o Inventory.o Pen.o CoverFile.o BaseballBat.o

a3:	$(OBJ)
	g++ -o a3 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h
	g++ -c BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

CourseArray.o:	CourseArray.cc CourseArray.h Course.h
	g++ -c CourseArray.cc

BookArray.o:	BookArray.cc BookArray.h Book.h
	g++ -c BookArray.cc

Course.o:	Course.cc Course.h defs.h
	g++ -c Course.cc

Book.o:	Book.cc Book.h defs.h Inventory.h
	g++ -c Book.cc

Inventory.o: Inventory.cc Inventory.h defs.h
	g++ -c Inventory.cc

Pen.o: Pen.cc Pen.h Inventory.h
	g++ -c Pen.cc	

BaseballBat.o: BaseballBat.cc BaseballBat.h Inventory.h
	g++ -c BaseballBat.cc

CoverFile.o: CoverFile.cc CoverFile.h Inventory.h
	g++ -c CoverFile.cc	
clean:
	rm -f *.o a3

