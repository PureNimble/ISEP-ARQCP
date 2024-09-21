output:  function.o asm.o main.o
	gcc  function.o asm.o main.o -o output

asm.o: asm.s
	gcc  -g -Wall -c asm.s
	
function.o: function.c
	gcc -g -Wall -c function.c
		
main.o: main.c
	gcc -g -Wall -c main.c
	
clean:
	rm -f *.0 output
	
run: output
	./output
