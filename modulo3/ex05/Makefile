output: vec_avg.o vec_sum.o main.o
	gcc vec_avg.o vec_sum.o main.o -o output

vec_sum.o: vec_sum.s
	gcc -g -Wall -c vec_sum.s

vec_avg.o: vec_avg.s
	gcc -g -Wall -c vec_avg.s
		
main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
		./output
