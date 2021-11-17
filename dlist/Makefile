CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

SRC= dlist_th1.c dlist_th2.c dlist_th3.c

OBJ= ${SRC:.c=.o}

MAIN=

TEST_MAIN= testsuite.c



library: libdlist.a

libdlist.a: ${OBJ}

debug: main
main: CFLAGS+= -fsanitize=address -g
main: LDFLAGS+= -fsanitize=address
main: ${OBJ} main.o

check: testsuite
	./testsuite



testsuite: CFLAGS+= -fsanitize=address
testsuite: LDFLAGS+= -lcriterion -fsanitize=address
testsuite: ${OBJ} $(TEST_MAIN:.c=.o)




%.a:
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) *.o libdlist.a testsuite main
