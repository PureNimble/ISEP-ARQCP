
output: frequencies.o main.o
	gcc frequencies.o main.o -o output

sort_without_reps.o: frequencies.c
	gcc -g -Wall -c frequencies.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
	
