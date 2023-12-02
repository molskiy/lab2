all: search.o main.o
	gcc search.o main.o -o lab2
search.o: search.c
	gcc -c search.c
main.o: main.c
	gcc -c main.c
clear:
	-rm *.o
