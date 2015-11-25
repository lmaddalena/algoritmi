#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#define MAX_NUMBERS	100

void printa(int argc, int *argv);
void swap(int *a, int *b);
int bubblesort(int argc, int *argv, int(*comp)(int,int));
int compasc(int, int);
int compdesc(int, int);
void runsample(int);

int main(int argc, char* argv[])
{
	int desc = 0;
	char c;

	while(--argc > 0 && (*++argv)[0] == '-')
		while(c = *++argv[0])
			switch(c){
				case 'd':
					desc = 1;
					break;
				default:
					printf("bubblesort: %c option not allowed\n", c);
					argc = 0;
					break;
			}

	if(argc != 0)
		printf("usage: bubblesort -d\n");
	else	
		runsample(desc);

	printf("Press [ENTER] to quit\n");
	getchar();
	exit(EXIT_SUCCESS);
}

void runsample(int desc){

	int a[MAX_NUMBERS];
	int i;
	int min = 1;
	int max = 99;

	printf("%i random numbers from %i to %i:\n", MAX_NUMBERS, min, max);

	// initializes random number generator
	srand((unsigned)time(NULL));

	// generate ranom number
	for (i = 0; i < MAX_NUMBERS; i++)
		a[i] = min + rand() % (max - 1);

	// print the numbers
	printa(MAX_NUMBERS, a);

	// sorting
	if(desc == 1)
		bubblesort(MAX_NUMBERS, a, compdesc);
	else
		bubblesort(MAX_NUMBERS, a, compasc);

	printf("%i ordered random numbers from %i to %i:\n", MAX_NUMBERS, min, max);

	// print the ordered numbers
	printa(MAX_NUMBERS, a);

}


// bubble sort
int bubblesort(int argc, int *argv, int(*comp)(int,int)){

	int i;
	int ordered = 0;

	while (!ordered)
	{
		ordered = 1;

		for (i = 0; i < argc; i++){
			if (i < argc - 1){
				if ((*comp)(argv[i], argv[i + 1]) == 1) {
					swap(&argv[i], &argv[i + 1]);
					ordered = 0;
				}
			}
		}
	}

	return ordered;
}

// comparison function for ascendant sort
int compasc(int a, int b){
	return a > b;
}

// comparison function for descendant sort
int compdesc(int a, int b){
	return b > a;
}

void swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

// print int array
void printa(int argc, int *argv){
	int i=0;
	int num_per_line = 10;

	while (i < argc){
		printf("%3i ", argv[i]);
		if ((i + 1) % num_per_line == 0) printf("\n");
		i++;
	}

	if ((i + 1) % num_per_line != 0) printf("\n");
}

