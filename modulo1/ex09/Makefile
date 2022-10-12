
output: sort_without_reps.o main.o
	gcc sort_without_reps.o main.o -o output

sort_without_reps.o: sort_without_reps.c
	gcc -g -Wall -c sort_without_reps.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
	
