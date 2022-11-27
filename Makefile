all: lab5
lab5: lab5.o f_add.o engine.o tests.o dop.o
	g++ lab5.o f_add.o engine.o tests.o dop.o -o lab5
engine.o: engine.cpp
	g++ -c engine.cpp
lab5.o: lab5.cpp
	g++ -c lab5.cpp
f_add.o: f_add.cpp
	g++ -c f_add.cpp
tests.o: tests.cpp	
	g++ -c tests.cpp
dop.o: dop.cpp	
	g++ -c dop.cpp
clean: 
	rm *.o
distclean: clean
	rm tmp_file
	rm lab5
