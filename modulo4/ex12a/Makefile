output: count_bits_one.o main.o
	gcc count_bits_one.o main.o -o output

count_bits_one.o: count_bits_one.c
	gcc -g -Wall -c count_bits_one.c
	
main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
