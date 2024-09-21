output: upper2.o main.o
	gcc upper2.o main.o -o output

upper2.o: upper2.c
	gcc -g -Wall -c upper2.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
