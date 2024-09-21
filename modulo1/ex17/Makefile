
output: swap.o main.o
	gcc swap.o main.o -o output

sum_even.o: swap.c
	gcc -g -Wall -c swap.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
