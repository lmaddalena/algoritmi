#include <stdio.h>
#include <stdlib.h>

// define the point type
typedef struct point {
	int x;
	int y;
	char *name;				
} t_point;	

// define the rect type
typedef struct rect {
	t_point p1;
	t_point p2;	
} t_rect;

// functions
void pointers(void);
void structures(void);
void printpoint(t_point *);
t_point *makepoint(int, int, char *);
t_rect *makerect(t_point, t_point);
int calcarea(t_rect *);
int calcarea2(t_rect rect);
void printrect(t_rect *);

// main
int main(int argc, char *argv[])
{	
	//pointers();
	structures();
	return 0;
}

//
// structures
void structures()
{		
	t_point *pt = makepoint(2, 3, "alfa");
	printpoint(pt);
	
	t_rect *rect = makerect(*makepoint(10, 10, "p1"), *makepoint(20, 20, "p2"));
	
	printrect(rect);
	printf("Area: %d\n", calcarea(rect));
	printf("Area: %d\n", calcarea2(*rect));
	
	free(pt);
	free(rect);
					
}


//
// calcarea
int calcarea(t_rect *rect)
{
	int b = rect->p2.x - rect->p1.x;
	int h = rect->p2.y - rect->p1.y;
	return (b * h);	
}

//
// calcarea2
int calcarea2(t_rect rect)
{
	int b = rect.p2.x - rect.p1.x;
	int h = rect.p2.y - rect.p1.y;
	return (b * h);	
}

// 
// make a point
t_point *makepoint(int x, int y, char *name)
{
	// memory allocation
	t_point *p;
	p = (t_point *)malloc(sizeof(t_point));
	
	// set members
	p->x = x;
	p->y = y;
	p->name = name;

	// ret the point
	return p;
}

//
// make a rect
t_rect *makerect(t_point p1, t_point p2)
{
	t_rect *r;
	r = (t_rect *)malloc(sizeof(t_rect));
	
	r->p1 = p1;
	r->p2 = p2;
	return r;
}

//
// print the point
void printpoint(t_point *pt)
{
	printf("point: %s, %i, %i\n", pt->name, pt->x, pt->y);
}

//
// print the rect
void printrect(t_rect *rect)
{
	printpoint(&(rect->p1));
	printpoint(&(rect->p2));
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