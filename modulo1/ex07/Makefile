
output: array_sort1.o main.o
	gcc array_sort1.o main.o -o output

array_sort1.o: array_sort1.c
	gcc -g -Wall -c array_sort1.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
	

