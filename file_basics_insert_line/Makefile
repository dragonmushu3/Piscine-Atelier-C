CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -D_XOPEN_SOURCE=700 -g

all:
	$(CC) $(CFLAGS) -fsanitize=address -g main.c insert_line.c -o insert_line

clean:
	$(RM) *.o insert_line
