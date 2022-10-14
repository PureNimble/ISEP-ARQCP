
output: populate.o main.o
	gcc populate.o main.o -o output

populate.o: populate.c
	gcc -g -Wall -c populate.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
	
