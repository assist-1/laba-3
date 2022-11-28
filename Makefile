lab3: lab3.o
	g++ lab3.o -o lab3
lab3.o : lab3.cpp
	 g++ -c lab3.cpp -o lab3.o
clean:
	rm *.o make
distclean: clean
	rm Makefile
	rm fileTemp
