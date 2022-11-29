TARGET = MyProg
CC=g++
CFLAGS=-I.

PREF_SRC = ./src/
PREF_OBJ = ./obj/

$(TARGET) : $(PREF_OBJ)progmake.o $(PREF_OBJ)progfunc.o
	$(CC) $(PREF_OBJ)progmake.o $(PREF_OBJ)progfunc.o -o $(TARGET)

$(PREF_OBJ)progmake.o : $(PREF_SRC)progmake.cpp
	$(CC) -c $(PREF_SRC)progmake.cpp -o $(PREF_OBJ)progmake.o

$(PREF_OBJ)progfunc.o : $(PREF_SRC)progfunc.cpp
	$(CC) -c $(PREF_SRC)progfunc.cpp -o $(PREF_OBJ)progfunc.o

mytest : $(PREF_OBJ)tests.o $(PREF_OBJ)progfunc.o
	$(CC) $(PREF_OBJ)tests.o $(PREF_OBJ)progfunc.o -o mytest

$(PREF_OBJ)tests.o : $(PREF_SRC)tests.cpp
	$(CC) -c $(PREF_SRC)tests.cpp -o $(PREF_OBJ)tests.o

clean:
	rm $(TARGET) $(PREF_OBJ)*.o

dist-clean: clean
	rm -f *.txt mytest

