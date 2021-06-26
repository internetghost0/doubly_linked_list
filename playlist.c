#include "playlist.h"
#include <string.h>
clist clist_create(void) 
{
	clist list;
	list.head = list.tail = NULL;
	list.length = 0;
	return list;
}

void clist_append(clist* list, const char* string) 
{
	
	node* head = list->head;
	node* tail = list->tail;
	
	if (head == NULL) {
		head = tail = malloc(sizeof(node));
		strncpy(head->data, string, STRING_SIZE);
		head->next = NULL;
		head->prev = NULL;
	}
	else if (head == tail) {
		tail = malloc(sizeof(node));
		strncpy(tail->data, string, STRING_SIZE);
		tail->next = NULL;
		tail->prev = head;
		head->next = tail;
	}
	else {
		node* tmp = malloc(sizeof(node));
		strncpy(tmp->data, string, STRING_SIZE);
		tmp->next = NULL;
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
	//printf("HEAD:[%d] TAIL:[%d] LEN:[%d]\n", list->head, list->tail, list->length);
	list->head = head;
	list->tail = tail;
	list->length += 1;
}

size_t clist_length(clist  list) 
{
	return list.length;
}

size_t _clist_real_index(clist* l, int index) {
	if ((index + (int)l->length) < 0 || index >= (int)l->length) {
		fprintf(stderr, "IndexError: list index out of range\n");
        exit(-1);
	}
	size_t real_index = 0;
	if (index < 0) {
		real_index = (size_t)(index + (int)l->length);
	} else {
        real_index = index;
    }

    return real_index;
}


void clist_insert(clist* list, int _index, const char* string) 
{
    size_t index = _clist_real_index(list, _index);
	if (index == list->length-1) {
		clist_append(list, string);
		return;
	}
	else if (index == 0) {
		node* x = malloc(sizeof(node));
		strncpy(x->data, string, STRING_SIZE);
		x->prev = NULL;
		x->next = list->head;
		list->head->prev = x;
		list->head = x;
		list->length++;
		return;
	}	
	
	node* x = malloc(sizeof(node));
	strncpy(x->data, string, STRING_SIZE);
	
	if (index < (list->length / 2) ) {
		node* tmp = list->head;
		for(size_t i = 0; i < index; i++)
			tmp = tmp->next;
			
		x->prev = tmp->prev;
		tmp->prev->next = x;
		tmp->prev = x;
		x->next = tmp;
	}
	else {
		node* tmp = list->tail;
		for(size_t i = list->length-1; i > index; i--)
			tmp = tmp->prev;
			
		tmp->next->prev = x;
		x->next = tmp->next;
		tmp->next = x;
		x->prev = tmp;
	}
}

const char* clist_pop(clist* list) 
{
	node* tmp = list->tail;
	list->tail = tmp->prev;
	list->tail->next = NULL;
	list->length--;

    char* res = tmp->data;	
	free(tmp);
	
    return res;
}

void clist_rem(clist* list, int _index) 
{
	size_t index = _clist_real_index(list, _index);
	node* tmp = NULL;
	
	if (index == 0) {
		tmp = list->head;
		list->head = tmp->next;
		list->head->prev = NULL;
		free(tmp);
		list->length--;
		return;
		
	}
	
	if (index == list->length-1) {
		clist_pop(list);
		return;
	}
	
	if (index < (list->length / 2) ) {
		tmp = list->head;
		for(size_t i = 0; i < index; i++)
			tmp = tmp->next;
	}
	else {
		node* tmp = list->tail;
		for(size_t i = list->length-1; i > index; i--)
			tmp = tmp->prev;
	}	
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	free(tmp);
	list->length--;
}

void clist_remove(clist* list) 
{
	node* tmp = list->head->next;
	while (tmp != list->tail) {
		//printf("DEL [%s]\n", tmp->prev->data);
		if (tmp->prev) free(tmp->prev);
		tmp = tmp->next;
	}
	if (tmp->prev) free(tmp->prev);
	if (tmp) free(tmp);
	list->length = 0;
	list->head = list->tail = NULL;
	
}

void clist_print(clist list, FILE* file) 
{
	node* tmp = list.head;
	while (tmp != list.tail) {
		fprintf(file, "%s\n", tmp->data);
		tmp = tmp->next;
	}
	if (list.tail) fprintf(file, "%s\n", list.tail->data);
}

void clist_display(clist list, FILE* file) 
{
	node* tmp = list.head;
	while (tmp != list.tail) {
		fprintf(file, "%s, ", tmp->data);
		tmp = tmp->next;
	}
	if (list.tail) fprintf(file, "%s\n", list.tail->data);
}

