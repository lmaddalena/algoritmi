#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#define MAX_NUMBERS	100

void printa(int argc, int *argv);
void swap(int *, int, int);
void quicksort(int *argv, int left, int right);


int main(int argc, char* argv[])
{
	int a[MAX_NUMBERS];
	int i;
	int min = 1;
	int max = 99;

	printf("%i random numbers from %i to %i:\n", MAX_NUMBERS, min, max);

	// initializes random number generator
	srand((unsigned)time(NULL));

	// generate random number
	for (i = 0; i < MAX_NUMBERS; i++)
		a[i] = min + rand() % (max - 1);

	// print the numbers
	printa(MAX_NUMBERS, a);

	// sorting
	quicksort(a, 0, MAX_NUMBERS);

	printf("%i ordered random numbers from %i to %i:\n", MAX_NUMBERS, min, max);

	// print the ordered numbers
	printa(MAX_NUMBERS, a);

	printf("Press [ENTER] to quit\n");
	getchar();
	exit(EXIT_SUCCESS);
}

void quicksort(int *argv, int left, int right){
	int i, pivot;

	if(left >= right) return;

	swap(argv, left, (left + right) / 2);

	pivot = left;

	for(i = left+1; i<right; i++){
		if(argv[i] <= argv[left])
			swap(argv, ++pivot, i);
	}

	swap(argv, left, pivot);
	quicksort(argv, left, pivot-1);
	quicksort(argv, pivot+1, right);
}


void swap(int v[], int a, int b)
{
	int temp = 0;
	temp = v[a];
	v[a] = v[b];
	v[b] = temp;
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

