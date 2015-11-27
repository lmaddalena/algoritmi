#include <stdio.h>

int strlen(char *);

int main(int argc, char *argv[])
{
	if(argc < 2)
		printf("no such word!\n");
	else
		printf("len = % i", strlen(argv[1]));
}

int strlen(char *s)
{	
	int i;
	for(i = 0; *s != '\0'; s++, i++)
		;
	
	return i;
}