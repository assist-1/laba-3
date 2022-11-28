make: main.o
	g++ -o make main.o
clean:
	rm *.o make
distclean: clean
	rm Makefile
