output: fill_student.o main.o
	gcc fill_student.o main.o -o output

fill_student.o: fill_student.c
	gcc -g -Wall -c fill_student.c
	
main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
