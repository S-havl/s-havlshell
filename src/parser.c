#include "parser.h"
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

char **parse_command(char *input) {
    char **args = malloc(MAX_TOKENS * sizeof(char *));
    if (!args) return NULL;

    char *token = strtok(input, " ");
    int i = 0; 
    while (token != NULL && i < MAX_TOKENS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;
    return args;
}
