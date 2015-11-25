typedef struct tnode *Treeptr;

typedef struct tnode {				// the tree node
	char *word;			// pointer to the word
	int count;			// word occurrences
	Treeptr left;			// pointer to left child
	Treeptr right;			// pointer to the right child

} Treenode;

// addtree: add a node with w, at or below p
Treeptr addtree(Treeptr, char *);

// treeprint: in-order print of tree p
void treeprint(Treeptr);

// destroytree: unalloc tree
void destroytree(Treeptr);

// talloc: make a tnode
Treeptr talloc(void);

// searchtree: search a word into the tree
Treeptr searchtree(Treeptr, char *);
