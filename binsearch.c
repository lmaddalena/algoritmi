#include <stdio.h>
#include <stdlib.h>


int numtab[] = { 1,  4,  6,  8, 10, 12, 13, 14, 18, 19,
                23, 24, 25, 27, 28, 37, 44, 56, 64, 73};

#define NITEMS (sizeof(numtab)/sizeof(int))

int main(int argc, char *argv[]){

		int n = 23;
		int i;
		int binsearch(int n, int *numtab, int max);
		
		i = binsearch(n, numtab, NITEMS);

		if(i != -1)
			printf("number %i found in position %i\n", n, i);
		else
			printf("number %i not found\n", n);
}


int binsearch(int n, int *numtab, int max){

	int low = 0;
	int high = max -1;
	int mid;

	while(low <= high){
		mid = (low + high) / 2;
		if(n > numtab[mid])
			low = mid + 1;
		else if (n < numtab[mid])
			high = mid - 1;
		else
			return mid;
		
	}

	return -1;

}

