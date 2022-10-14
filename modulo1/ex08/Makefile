
output: array_sort2.o main.o
	gcc array_sort2.o main.o -o output

array_sort1.o: array_sort2.c
	gcc -g -Wall -c array_sort2.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
	
