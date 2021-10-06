CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

check: testsuite
	./testsuite

debug: deb_levenshtein.o deb_main.o
	$(CC) -g deb_levenshtein.o deb_main.o -o $@
	gdb debug

deb_main.o:
	$(CC) $(CFLAGS) -g -c main.c -o $@

deb_levenshtein.o:
	$(CC) $(CFLAGS) -g -c levenshtein.c -o $@

testsuite: testsuite.o levenshtein.o
	$(CC) *.o -lcriterion -o $@

clean: 
	$(RM) *.o testsuite debug
