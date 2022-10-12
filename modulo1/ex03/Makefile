
output: sum_even.o main.o
	gcc sum_even.o main.o -o output

sum_even.o: sum_even.c
	gcc -g -Wall -c sum_even.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
