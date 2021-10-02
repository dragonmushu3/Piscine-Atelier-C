CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

library: library.a

library.a: dlist_th1.o dlist_th2.o dlist_th3.o

%.a:
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) *.o library.a
