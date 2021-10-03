CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic
CDBG=-g -fsanitize=address
CT=-lcriterion

con4: connect4.c
	$(CC) $(CFLAGS) $(CDBG) -o con4 connect4.c $(CT)

check: test
	./test

test: connect4.o testsuite.o
	$(CC) -lcriterion -o $@ $^

clean: 
	$(RM) *.o test 
