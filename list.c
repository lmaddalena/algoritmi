#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct litem {
	int id;
	char *name;
	struct litem *next;
};


static struct litem *first;
static struct litem *last;

struct litem* itemalloc(void);
struct litem* additem(int, char *);
int count(void);
void print(void);
void freeitem(struct litem *);

int main(int argc, char *argv[]){

	printf("Hello World!\n");

	struct litem *item;

	item = additem(1, "Luca");
	item = additem(2, "Giovanni");
	item = additem(3, "Paolo");
	item = additem(4, "Matteo");


	printf("Count %i\n", count());

	print();

	freeitem(first);

	return 0;
}


struct litem* additem(int id, char *name){


	struct litem *item = itemalloc();

	if(item == NULL || (item->name = strdup(name)) == NULL)		return NULL;

	item->id = id;
	item->next = NULL;

	if(first == NULL){
		first = item;
		last = item;
	}
	else {
		last->next = item;
		last = item;
	}

	return item;
}


int count(void){
	int c = 0;

	if(first != NULL){
		struct litem *pt = first;

		for(c = 0;  pt != NULL; pt = pt->next, c++)
			;
	}

	return c;


}

struct litem* itemalloc(void){

	struct litem *ptr = malloc(sizeof(struct litem));
	return ptr;
}

void print(){

	struct litem *p;

	for(p = first; p != NULL; p = p->next)
		printf("%i) %s\n", p->id, p->name);
}

void freeitem(struct litem *item){

	struct litem *p, *q;
	for(p = item; p != NULL; p = q){
		q = p->next;
		free(p);
	}

	/*
	if(item->next != NULL){
		freeitem(item->next);
		free(item);
	}
	*/
}
