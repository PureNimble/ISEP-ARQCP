output: asm.o main.o
	gcc asm.o main.o -o output
	
main.o: main.c
	gcc -g -Wall -c main.c
	
asm.o: asm.s
	gcc -g -Wall -c asm.s
	
clean:
	rm -f *.0 output
	
run: output
	./output
