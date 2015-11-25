#include <stdio.h>
#include "interface.h"


int main(void)
{
	printf("sub(3,2)=%d\n", Library.sub(3, 2));
	printf("add(3,2)=%d\n", Library.add(3, 2));
	printf("%d\n", Library.myVal);
	
	return 0;
}