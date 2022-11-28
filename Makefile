all:
		g++ main.cpp sol1.cpp sol3i.cpp sol3o.cpp sol5.cpp -o m
clean:
		rm -rf *.o m
distclean:
		rm -rf *.o m
		rm *.txt
