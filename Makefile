G++ = g++ -Wall -Werror -Wextra

all: distclean lab_3

lab_3:
	$(G++) lab.cpp -o lab_3

tests:
	@echo "-------Test #1: File output-------"
	./lab_3 --fromfile read1.txt --tofile output.txt
	@echo " "
	cat output.txt
	@echo "\n"

	@echo "-------Test #2: Output file doesn't exist-------"
	./lab_3 --fromfile --tofile
	@echo "\n"

	@echo "-------Test #3: Output to Terminal-------"
	./lab_3 --fromfile read1.txt
	@echo "\n"

	@echo "-------Test #4: Output to Terminal (Sentences with the same length)-------"
	./lab_3 --fromfile read2.txt
	@echo "\n"

	@echo "-------Test #5: Unnamed File output-------"
	./lab_3 --fromfile read1.txt --tofile
	@echo " "
	cat tofile.txt
	@echo "\n"

clean:
	rm -rf tofile.txt

distclean: clean
	rm -rf lab_3

rebuild: distclean all