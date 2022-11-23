CC=g++
Fcu = -c
Fend = -o

make : main.o func.cpp
	$(CC) main.o $(Fend) main func.cpp

main.o : main.cpp
	$(CC) $(Fcu) main.cpp

clean :
	rm *.o main

distclean : clean
	rm -f make