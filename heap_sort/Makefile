CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic
LDFLAGS =

check: test_main
	./test_main

test_main: CFLAGS+= -g -fsanitize=address
test_main: LDFLAGS+= -fsanitize=address
test_main: heap_sort.o test_main.o

clean:
	$(RM) *.o test_main
