make : flags.o otrezki.o
	g++ -o make flags.o otrezki.o
clean :
		rm *.o 
distclean : clean
		rm -f make
