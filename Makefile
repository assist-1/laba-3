

out: main.o func.o
	g++ -o out main.cpp func.cpp

clean : 
	$(RM) *.o

distclean :
	$(RM) out *.o
