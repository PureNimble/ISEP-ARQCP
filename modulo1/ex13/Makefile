output: where_is.o main.o
	gcc where_is.o main.o -o output

where_is.o: where_is.c
	gcc -g -Wall -c where_is.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
