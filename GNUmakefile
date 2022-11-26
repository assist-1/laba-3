OBJECTS=functions.o main.o

answer: $(OBJECTS)
	g++ -o answer $(OBJECTS)

.PHONY: clean
clean:
	$(RM) $(OBJECTS)

distclean: clean
	$(RM) answer