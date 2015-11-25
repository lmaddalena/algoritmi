#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "btree.h"

#define MAXWORD 100

// main:
int main(int argc, char *argv[]){

	Treeptr root;
	Treeptr node;

	char word[MAXWORD];

	root = NULL;

	while((getword(word, MAXWORD)) != EOF)
		if(isalpha(word[0]))
			root = addtree(root, word);

	// print the tree	
	treeprint(root);

	// search
	if(argc > 1){
		while(--argc > 0){
			printf("Serching for %s: \n", *(++argv));
			node = searchtree(root, *argv);
			if(node != NULL)
				printf("word found: %s %i\n", node->word, node->count);

		}

	}

	// destroy the tree
	destroytree(root);

	return 0;
}

