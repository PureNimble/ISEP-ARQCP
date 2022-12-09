output: update_address.o main.o
	gcc update_address.o main.o -o output
	
main.o: main.c
	gcc -g -Wall -c main.c
	
update_address.o: update_address.s
	gcc -g -Wall -c update_address.s
	
clean:
	rm -f *.0 output
	
run: output
	./output
