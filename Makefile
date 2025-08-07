ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXEC = shell.exe
else
    RM = rm -f
    EXEC = shell
endif

CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -Iinclude

SRCS = src/main.c src/builtins/builtins.c src/parser.c src/executor.c

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(EXEC)

clean:
	$(RM) $(EXEC)
