output: inc_nsets.o populate.o check.o main.o
	gcc inc_nsets.o populate.o check.o main.o -o output

check.o: check.c
	gcc -g -Wall -c check.c

populate.o: populate.c
	gcc -g -Wall -c populate.c

inc_nsets.o: inc_nsets.c
	gcc -g -Wall -c inc_nsets.c
	
main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
