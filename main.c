#include "list.c"
#include <stdio.h>

int main(void) {
	clist playlist = create_clist();
	clist_append(&playlist, "ghost girl");
	clist_append(&playlist, "Kino");
	clist_insert(&playlist, -2, "PUNK!");
	clist_insert(&playlist, 0, "I'm goofy");
	printf("Length: %d\n", playlist.length);
	clist_display(playlist, stdout);
	puts("");

	clist_rem(&playlist, 0);
	clist_pop(&playlist);
	printf("Length: %d\n", playlist.length);
	clist_print(playlist, stdout);

	remove_clist(&playlist);
	
	return 0;
}
