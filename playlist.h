#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_SIZE 256

typedef struct node_s {
	char data[STRING_SIZE];
	struct node_s* next;	
	struct node_s* prev;	
} node;

typedef struct clist_s {
	node* head;
	node* tail;
	size_t length;
}clist;

clist clist_create(void) ;
void clist_remove(clist* list); 

void clist_append(clist* list, const char* string); 
void clist_insert(clist* list, int index, const char* string); 

void clist_rem(clist* list, int index); 
const char* clist_pop(clist* list); 

size_t clist_length(clist list); 

void clist_print(clist list, FILE* file); 
void clist_display(clist list, FILE* file); 


