output: main.o print.o
	gcc main.o print.o -o output

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

print.0: print.c print.h
	gcc -g -Wall -c print.c -o print.0

clean:
	rm -f *.o output

run:
	./output
