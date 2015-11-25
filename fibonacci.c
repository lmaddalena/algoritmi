// f(1)=1, f(2)=1, fn = f(n-1) + f(n-2) , n > 2

#include <stdio.h>

#define MAX_NUMBERS	20

int fibonacci(int n);


int main(int argc, char *argv[]){

	int f1=1, f2=0, fn;
	int n;

	printf("Serie di Fibonacci per n in [1:%i]\n", MAX_NUMBERS);

	for(n = 1; n <= MAX_NUMBERS; n++){
		if( n <= 2)
			fn = 1;
		else
			fn = f1 + f2;

		f2 = f1;
		f1 = fn;
		printf("%i ", fn);

	}

	printf("\n");
	for(n = 1; n <= MAX_NUMBERS; n++){
		printf("%i ", fibonacci(n));
	}
	

	printf("\n");
	return 0;
}

// numero di Fibonacci definito ricorsivamente
int fibonacci(int n){

	int fn;

	if(n == 0)
		fn = 0;
	else if(n <= 2)
		fn = 1;
	else
		fn = fibonacci(n - 1) + fibonacci(n - 2);

	return fn;
}
	
