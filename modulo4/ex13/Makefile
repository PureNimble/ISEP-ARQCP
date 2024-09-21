output: c.o main.o
	gcc c.o main.o -o output

c.o: c.c
	gcc -g -Wall -c c.c
	
main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
