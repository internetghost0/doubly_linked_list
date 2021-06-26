#include <stdio.h>
#include "playlist.h"

int main(void) {
	clist playlist = clist_create();
	clist_append(&playlist, "2");
	clist_append(&playlist, "3");
	clist_insert(&playlist, -2, "1");
	clist_insert(&playlist, 0, "0");
	clist_display(playlist, stdout);
	putchar('\n');
    
    clist_pop(&playlist);
    clist_display(playlist, stdout);
	clist_remove(&playlist);
	
	return 0;
}
