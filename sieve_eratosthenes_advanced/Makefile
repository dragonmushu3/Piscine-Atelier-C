CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic
CDEBUG=-fsanitize=address -lcriterion

all: sieve.c
	$(CC) $(CFLAGS) -c -o sieve.o sieve.c

check: sieve.o testsuite.o
	$(CC) $(CDEBUG) *.o

sieve.o: sieve.c
	$(CC) $(CFLAGS) $(CDEBUG) -c sieve.c

testsuite.o: testsuite.c
	$(CC) $(CFLAGS) $(CDEBUG) -c testsuite.c

clean:
	$(RM) *.o check
