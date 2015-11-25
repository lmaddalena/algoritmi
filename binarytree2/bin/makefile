btree : main.o btree.o getword.o
	gcc main.o btree.o getword.o -o btree

main.o : ../btree.h ../main.c 
	gcc -c ../main.c

btree.o : ../btree.h ../btree.c
	gcc -c ../btree.c

getword.o : ../getword.h ../getword.c
	gcc -c ../getword.c
