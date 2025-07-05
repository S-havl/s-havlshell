CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -Iinclude

SRCS = src/main.c src/builtins.c src/parser.c src/executor.c
OBJS = $(SRCS:.c=.o)

shell: $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o shell

clean:
	rm -f shell
