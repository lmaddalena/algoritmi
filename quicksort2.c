#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBERS	100

void swap(int *, int, int);
void quicksort(int *argv, int left, int right);

int main(int argc, char *argv[]){

	int n[MAX_NUMBERS];
	int i;

	if(argc < 2)
		printf("usage: quicksort 3 99 2 ...\n");
	else if(argc > MAX_NUMBERS + 1)
		printf("too many numbers\n");
	else {
		for(i = 1; i< argc; i++)
			n[i-1] = atoi(argv[i]);

		quicksort(n, 0, argc-1);
	}

	for(i = 0; i < argc - 1; i++)
		printf("%i\n", n[i]);
	
	return 0;

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


