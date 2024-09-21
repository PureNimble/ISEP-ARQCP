output:  notas.o calcular.o main.o
	gcc  notas.o calcular.o main.o -o output
	
main.o: main.c
	gcc -g -Wall -c main.c
	
calcular.o: calcular.s
	gcc -g -Wall -c calcular.s
	
notas.o: notas.s
	gcc -g -Wall -c notas.s
clean:
	rm -f *.0 output
	
run: output
	./output
