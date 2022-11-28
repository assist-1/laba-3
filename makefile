OUT		= run
CC		= g++
FLAGS	= -g -c 
SRC		= ./src/
OBJ		= ./obj/
SOURCE	= main.cpp
OBJS	= $(OBJ)main.o
PY		= python3

all: $(OBJS)
	$(CC) -w $(OBJS) -o $(OUT)


$(OBJ)main.o: $(SRC)main.cpp
	$(CC) $(FLAGS) $(SRC)main.cpp -o $(OBJ)main.o

$(OBJ)parse.o: $(SRC)parse.cpp
	$(CC) $(FLAGS) $(SRC)parse.cpp -o $(OBJ)parse.o

$(OBJ)sort.o: $(SRC)sort.cpp
	$(CC) $(FLAGS) $(SRC)sort.cpp -o $(OBJ)sort.o

test:
	$(PY) $(SRC)tests.py
	./$(OUT) --fromfile test.txt
	$(PY) $(SRC)plot.py

retry:
	./$(OUT) --fromfile test.txt
	$(PY) $(SRC)plot.py

clean:
	rm $(OUT) $(OBJ)*.o

dist-clean: clean
	rm *.txt