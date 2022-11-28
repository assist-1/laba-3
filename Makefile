CC=g++
CFLAGS=-c -std=c++17

all: laba_3

laba_3: main.o
	$(CC) main.o -o laba_3

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm -rf *.o laba_3

distclean:
	rm -rf laba_3 *.o *.txt
