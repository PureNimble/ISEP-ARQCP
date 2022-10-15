output: populate.o check.o main.o
	gcc populate.o check.o main.o -o output

check.o: check.c
	gcc -g -Wall -c check.c

populate.o: populate.c
	gcc -g -Wall -c populate.c
	
main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
