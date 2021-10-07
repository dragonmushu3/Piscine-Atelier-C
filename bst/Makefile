CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
LIBFLAG = -lcriterion

check: testsuite
	./testsuite

testsuite: bst.o testsuite.o bst_static.o
	$(CC) $^ -fsanitize=address -o testsuite $(LIBFLAG)

clean:
	rm *.o testsuite
