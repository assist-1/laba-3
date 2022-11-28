OBJS=functions.o main.o

prog: $(OBJS)
	g++ -o prog $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) prog