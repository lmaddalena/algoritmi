#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "getword.h"


char *_strdup(char *);

// addtree: add a node with w, at or below p
Treeptr addtree(Treeptr p, char *w){

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
void treeprint(Treeptr p){

	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);		
	}

}

// destroytree: unalloc tree
void destroytree(Treeptr p){
	if(p != NULL){
		destroytree(p->left);
		destroytree(p->right);
		free(p);
	}
}

// search: search a word into the tree
Treeptr searchtree(Treeptr node, char *w){

	int cond;

	if(node != NULL){
		if((cond = strcmp(w, node->word)) == 0)
			return node;
		else if(cond < 0)
			searchtree(node->left, w);
		else
			searchtree(node->right, w);
	}
}

// talloc: make a tnode
Treeptr talloc(void){
	return (Treeptr)malloc(sizeof(Treenode));
}

// _strdup: makes a duplicate of s
char *_strdup(char *s){

	char *p;
	p = (char *)malloc(strlen(s) + 1);	// +1 for '\0'

	if(p != NULL)
		strcpy(p, s);

	return p;

}



