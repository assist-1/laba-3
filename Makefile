G++ = g++

all: clean lab4

lab4:
	$(G++) lab.cpp -o lab4

clean:
	rm -rf lab4 tofile.txt