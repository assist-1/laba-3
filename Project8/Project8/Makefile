NN = main
CC = g++



$(NN): main.o So.o
	$(CC) main.o So.o -o $(NN)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

functions.o: functions.cpp
	$(CC) -c So.cpp -o So.o

clean:
	rm -rf $(NN) *.o

distclean: clean
	rm -f make