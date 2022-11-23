PROJECT = main
CC = g++


$(PROJECT): main.o functions.o
	$(CC) main.o functions.o -o $(PROJECT)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

functions.o: functions.cpp
	$(CC) -c functions.cpp -o functions.o

clean:
	rm -rf $(PROJECT) *.o

distclean: clean
	rm -f make
