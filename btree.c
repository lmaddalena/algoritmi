/* ==========================================================================================
binary tree:
the tree contains one node per distinct word, each node contains:
- a pointer to the word
- a count of the number of occurrences
- a pointer to the left child node
- a pointer to the right child node

No node may have more then 2 child node.
The nodes are manteined so that  at any node the left  subtree contains only
words that are lexographically less then the word at the node, and the right
subtree contains only words that are greater.
 
Example:

"now is the time for all good men to come to the aid of their party"

                                        now
                                 /                \
                               is                  the
                              /  \             /        \
                            for   men        of        time
                           /   \              \        /   \
                        all    good           party  their  to
                       /  \
                     aid  come         
                              

output:

   1 aid
   1 all
   1 come
   1 for
   1 good
   1 is
   1 men
   1 now
   1 of
   1 party
   2 the
   1 their
   1 time
   2 to
       
========================================================================================== */


#include <stdio.h>
#include <string.h>

#define MAXWORD 100

struct tnode {				// the tree node
	char *word;			// pointer to the word
	int count;			// word occurrences
	struct tnode *left;		// pointer to left child
	struct tnode *right;		// pointer to the right child

};

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

// main:
int main(int argc, char *argv[]){

	struct tnode *root;
	char word[MAXWORD];

	root = NULL;

	while((getword(word, MAXWORD)) != EOF)
		if(isalpha(word[0]))
			root = addtree(root, word);
	
	treeprint(root);


	return 0;
}

struct tnode *talloc(void);
char *_strdup(char *);

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w){

	int cond;

	if(p == NULL){					// a new word has arrived
		p = talloc();				// allocate space for a new node
		p->word = _strdup(w);			// copy the word in the node
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;				// word found in current node
	else if (cond < 0)				// less then into left subtree
		p->left = addtree(p->left, w);
	else						// greater then into left subtree
		p->right = addtree(p->right, w);

	return p;
}

// treeprint: in-order print of tree p
void treeprint(struct tnode *p){

	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);		
	}

}

#include <stdlib.h>

// talloc: make a tnode
struct tnode *talloc(void){
	return (struct tnode *)malloc(sizeof(struct tnode));
}

// _strdup: makes a duplicate of s
char *_strdup(char *s){

	char *p;
	p = (char *)malloc(strlen(s) + 1);	// +1 for '\0'

	if(p != NULL)
		strcpy(p, s);

	return p;

}


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
char BUFF[MAXBUFF];
int ptrbuff = 0;

int getch(void){
	return ptrbuff > 0 ? BUFF[--ptrbuff] : getchar();

}

void ungetch(int c){
	if (ptrbuff < MAXBUFF)
		BUFF[ptrbuff++] = c;
	else
		printf("The buffer is full\n");
}

