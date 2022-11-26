CC = g++
CFLAGS += -c
RM = del -f
OBJS = main.o funcs.o

.PHONY: all clean distclean
all: make
make: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o main
main.o: main.cpp funcs.h
	$(CC) $(CFLAGS) main.cpp -o main.o
funcs.o: funcs.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)
distclean: clean
	$(RM) main.exe output.txt