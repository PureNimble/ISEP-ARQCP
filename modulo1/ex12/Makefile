
output: capitalize.o main.o
	gcc capitalize.o main.o -o output

capitalize.o: capitalize.c
	gcc -g -Wall -c capitalize.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
	

