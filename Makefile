make : flags.o otrezki.o
	g++ -o make flags.o otrezki.o
clean :
		rm *.o make
distclean : clean
		rm -f make
