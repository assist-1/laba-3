main: main.o
	g++ main.o -o main
main.o : main.cpp
	 g++ -c main.cpp -o main.o
clean:
	rm *.o make
distclean: clean
	rm Makefile
