output: update_grades.o main.o
	gcc update_grades.o main.o -o output
	
main.o: main.c
	gcc -g -Wall -c main.c

update_grades.o: update_grades.s
	gcc -g -Wall -c update_grades.s

clean:
	rm -f *.0 output
	
run: output
	./output
