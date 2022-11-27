OBJS=test.o

result: $(OBJS)
	g++ -o result $(OBJS)

.PHONY: clean
clean:
	$ (RM)  $(OBJS)

distclean: clean
	$ (RM) result