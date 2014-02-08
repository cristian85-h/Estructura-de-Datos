tda:	main.o integer.o linkedlist.o object.o tdalist.o dllnode.o dlcursorlist.o
	g++ main.o integer.o dllnode.o linkedlist.o object.o tdalist.o dlcursorlist.o -o tda
main.o:	main.cpp tdalist.h linkedlist.h integer.h dlcursorlist.h
	g++ -c main.cpp
integer.o:	integer.cpp integer.h object.h
	g++ -c integer.cpp
dllnode.o:	dllnode.cpp dllnode.h
	g++ -c dllnode.cpp
tdalist.o:	tdalist.h tdalist.cpp
	g++ -c tdalist.cpp
linkedlist.o:	linkedlist.cpp linkedlist.h tdalist.h object.h
	g++ -c linkedlist.cpp
dlcursorlist.o:	dlcursorlist.cpp dlcursorlist.h tdalist.h object.h
	g++ -c dlcursorlist.cpp
object.o:	object.h object.cpp
	g++ -c object.cpp
clean:
	rm *.o tda

