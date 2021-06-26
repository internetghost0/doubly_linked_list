CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic #-ggdb

playlist: main.c playlist.c playlist.h
	$(CC) $(CFLAGS) -o main main.c playlist.c
	./main



