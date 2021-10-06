CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address

library: libdlist.a

libdlist.a: dlist_th1.o dlist_th2.o dlist_th3.o

debug: deb_dlist_th1.o deb_dlist_th2.o deb_dlist_th3.o deb_main.o
	$(CC) *.o  -g -fsanitize=address

check: dlist_th1.o dlist_th2.o dlist_th3.o testsuite.o
	$(CC) -lcriterion *.o -fsanitize=address -o $@
	./check


deb_main.o:
	$(CC) $(CFLAGS) -c -g main.c -fsanitize=address

deb_dlist_th1.o:
	$(CC) $(CFLAGS) -c -g dlist_th1.c -fsanitize=address

deb_dlist_th2.o:
	$(CC) $(CFLAGS) -c -g dlist_th2.c -fsanitize=address

deb_dlist_th3.o:
	$(CC) $(CFLAGS) -c -g dlist_th3.c -fsanitize=address

%.a:
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) *.o library.a check
