CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address

library: libfifo.a

libfifo.a: fifo.o utilities.o


%.a:
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) *.o libfifo.a
