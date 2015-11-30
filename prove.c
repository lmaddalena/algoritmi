#include <stdio.h>

void pointers();

int main(int argc, char *argv[])
{
	
	pointers();
	return 0;
}


void pointers()
{
	int *p; 		// pointer to int
	int a = 1;		
	p = &a;			// p point to a
	
	printf("address of p: %p \n", p);
	printf("value of p: %i \n", *p);
	
	char s[] = "Helllo World!";
	
	char *pc;		// pointer to char
	pc = s;
	
	printf("address of pc: %pc \n", p);
	printf("value of pc: %s \n", pc);
	
	while(*pc != '\0')
		putchar(*pc++);
		
	printf("\n");
	
	char *months[] = {
		"gennaio",
		"febbrario",
		"marzo",
		"aprile",
		"maggio",
		"giugno",
		"luglio",
		"agosto",
		"settembre",
		"ottobre",
		"novembre",
		"dicembre"
	};			
	
	char **mm = months;
	
	int i;
	for(i = 0; i < 12; i++)
	{
		//printf("%s\n", mm[i]);
		printf("%s\n", *mm++);
	}
}