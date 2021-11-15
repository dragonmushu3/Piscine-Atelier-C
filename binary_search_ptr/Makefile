CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic
LDFLAGS = -lcriterion

SRC = bsearch.c testsuite.c
OBJ = ${SRC:.c=.o}

check: testsuite
	./testsuite

testsuite: ${OBJ}

clean:
	$(RM) *.o testsuite
