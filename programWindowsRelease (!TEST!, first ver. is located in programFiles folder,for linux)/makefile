CC = g++
CFLAGS = -c -Wall

all: helloWorld

helloWorld:main.o func.o
	$(CC) main.o func.o -o helloWorld.exe

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

func.o: func.cpp
	$(CC) $(CFLAGS) func.cpp -o func.o

clean:
	del /s *.o

distclean:
	del /s *.o
	del /s helloWorld.exe