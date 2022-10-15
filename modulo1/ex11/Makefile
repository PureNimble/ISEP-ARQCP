output: palindrome.o main.o
	gcc palindrome.o main.o -o output

palindrome.o: palindrome.c
	gcc -g -Wall -c palindrome.c

main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
