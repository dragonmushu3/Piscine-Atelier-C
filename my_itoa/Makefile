CC= gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g -fsanitize=address
LDFLAGS = -fsanitize=address

check: main
	./main
main: main.o my_itoa.o

clean:
	$(RM) *.o main
