CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
LDFLAGS = -g -fsanitize=address

string_replace: main.o string_replace.o

clean:
	$(RM) *.o string_replace
