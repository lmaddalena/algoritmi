namespace : interface.o main.o
	gcc -std=c99 interface.o main.o -o namespace

main.o : ../main.c ../interface.h
	gcc -std=c99 -c ../main.c

interface.o : ../interface.h ../interface.c 
	gcc -std=c99 -c ../interface.c
