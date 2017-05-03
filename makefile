p2: main.o toBinary.o toText.o binStats.o error.o
	gcc main.o toBinary.o toText.o binStats.o error.o -o p2
main.o: main.c headers.h prototypes.h
	gcc -c main.c
toBinary.o: toBinary.c headers.h
	gcc -c toBinary.c
toText.o: toText.c headers.h
	gcc -c toText.c
binStats.o: binStats.c headers.h
	gcc -c binStats.c
error.o: error.c headers.h
	gcc -c error.c
clean:
	rm -f *.o core p2
