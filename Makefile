CC=g++
CFLAGS=-c

all: lab_5

lab_5: main.o
	$(CC) main.o -o lab_5

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm -rf lab_5 *.o

distclean:
	rm -rf lab_5 *.o *.txt
