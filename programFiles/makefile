CC = g++
CFLAGS = -c -Wall

all: helloWorld

helloWorld:main.o func.o
	$(CC) main.o func.o -o helloWorld

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

func.o: func.cpp
	$(CC) $(CFLAGS) func.cpp

clean:
	rm -rf *.o

distclean:
	rm -rf *.o
	rm -rf helloWorld