CC=g++
Fcu = -c
Fend = -o

make : main.o lib.cpp
	$(CC) main.o $(Fend) main lib.cpp

main.o : main.cpp
	$(CC) $(Fcu) main.cpp

clean :
	rm *.o main

distclean :
	rm *.o