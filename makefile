out : main.o solution.o
	g++ main.o solution.o -o out
main.o : main.cpp
	g++ -c main.cpp -o main.o
solution.o : solution.cpp
	g++ -c solution.cpp -o solution.o
clean :
	rm out *.o
distclean :
	rm out *.o test.txt