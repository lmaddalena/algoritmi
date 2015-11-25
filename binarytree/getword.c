#include <stdio.h>
#include "getword.h"

// getword: get next word or character from input
int getword(char *word, int lim){

	int c;
	
	int getch(void);
	void ungetch(int);

	char *w = word;
	
	// elimina spazi bianchi iniziali
	while (isspace(c = getch()))
		;

	// primo carattere
	if (c != EOF)
		*w++ = c;

	// se non è un carattere alfabetico esce
	if (!isalpha(c)){
		*w = '\0';
		return c;
	}

	// legge i successivi caratteri dal buffer 
	// fino a quando non trova un carattere non alfanumerico
	for (; --lim > 0; w++){
		if (!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	}

	// aggiunge un terminatore di stringa
	*w = '\0';

	// restituisce il primo carattere trovato
	return word[0];
}


#define MAXBUFF 100
static char BUFF[MAXBUFF];
static int ptrbuff = 0;

int getch(void){
	return ptrbuff > 0 ? BUFF[--ptrbuff] : getchar();

}

void ungetch(int c){
	if (ptrbuff < MAXBUFF)
		BUFF[ptrbuff++] = c;
	else
		printf("The buffer is full\n");
}

