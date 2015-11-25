#include "interface.h"

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;	
}

const struct library Library = {
	.add = add,
	.sub = sub,
	.myVal = 36	
};
