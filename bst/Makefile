CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
LIBFLAG = -lcriterion

check: testsuite
	./testsuite

testsuite: bst.o testsuite.o bst_static.o
	$(CC) $^ -fsanitize=address -o testsuite $(LIBFLAG)

CFLAGS += -g -fsanitize=address
debug: bst_static.o main.o
	$(CC) -g -fsanitize=address $^ -o $@

clean:
	$(RM) *.o testsuite debug
