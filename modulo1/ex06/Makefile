
output: power_ref.o main.o
	gcc power_ref.o main.o -o output

power_ref.o: power_ref.c
	gcc -g -Wall -c power_ref.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
