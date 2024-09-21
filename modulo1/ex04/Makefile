
output: upper1.o main.o
	gcc upper1.o main.o -o output

upper1.o: upper1.c
	gcc -g -Wall -c upper1.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
	

