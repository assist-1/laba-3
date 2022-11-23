TR = lab5
CC = g++
OB = func.o lab5.o
$(TR) : $(OB)
	$(CC) func.o lab5.o -o $(TR)

func.o : func.cpp
	$(CC) -c func.cpp -o func.o

lab5.o : lab5.cpp
	$(CC) -c lab5.cpp -o lab5.o

clean :
	rm $(OB)
distclean : clean
	rm $(TR)