laba5 : main.o mylib.o
	g++ main.cpp mylib.o -o laba5
main.o : main.cpp
	g++ -c main.cpp -o main.o
mylib.o : mylib.cpp
	g++ -c mylib.cpp -o mylib.o

clean :
	rm laba5 *.o

dist-clean :clean
	rm *.txt

