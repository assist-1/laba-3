AA.exe : AA.cpp
	g++ AA.cpp -o AA.exe

clean :
	rm AA.exe
	rm NINE.txt

distclean :
	rm AA.exe
	rm NINE.txt
	rm Makefile