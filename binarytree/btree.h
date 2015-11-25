struct tnode {				// the tree node
	char *word;			// pointer to the word
	int count;			// word occurrences
	struct tnode *left;		// pointer to left child
	struct tnode *right;		// pointer to the right child

};

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *, char *);

// treeprint: in-order print of tree p
void treeprint(struct tnode *);

// destroytree: unalloc tree
void destroytree(struct tnode *);

// talloc: make a tnode
struct tnode *talloc(void);

// searchtree: search a word into the tree
struct tnode *searchtree(struct tnode *, char *);
