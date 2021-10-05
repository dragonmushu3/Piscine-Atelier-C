CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

check: dump.o hash.o hash_map.o utilities.o
	$(CC) $^ -o main

clean:
	$(RM) *.o main
