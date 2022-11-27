main : main.o Fynk.o
	 g++ main.o Fynk.o -o main

main.o : main.cpp
	 g++ -c main.cpp -o main.o

Fynk.o : Fynk.cpp
	g++ -c Fynk.cpp -o Fynk.o

clean:
	rm main.o Fynk.o
	
distclean: clean
	rm main	