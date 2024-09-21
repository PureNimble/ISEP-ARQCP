output: copy_vec.o main.o
	gcc copy_vec.o main.o -o output

power_ref.o: copy_vec.c
	gcc -g -Wall -c copy_vec.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
