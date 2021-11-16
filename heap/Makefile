CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic

SRC = create.c add.c pop.c del.c print.c

library: libheap.a

libheap.a: ${SRC:.c=.o}

clean:
	$(RM) *.o libheap.a

%.a:
	$(AR) $(ARFLAGS) $@ $^
