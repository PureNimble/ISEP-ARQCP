
output: odd_sum.o main.o
	gcc odd_sum.o main.o -o output

odd_sum.o: odd_sum.c
	gcc -g -Wall -c odd_sum.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
	
