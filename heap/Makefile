CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic
LDFLAGS =

SRC = create.c add.c pop.c del.c print.c

check: test_main
	./test_main

test_main: CFLAGS+= -g -fsanitize=address
test_main: LDFLAGS+= -fsanitize=address
test_main: ${SRC:.c=.o} test_main.o

library: libheap.a

libheap.a: ${SRC:.c=.o}

clean:
	$(RM) *.o libheap.a test_main

%.a:
	$(AR) $(ARFLAGS) $@ $^
