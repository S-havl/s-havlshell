#include <string.h>
#include "parser.h"

#define MAX_TOKENS 1024

char **parse_command(char *input) {
  static char *tokens[MAX_TOKENS];
  int i = 0;

  char *token = strtok(input, " ");
  while (token && i < MAX_TOKENS - 1) {

    tokens[i++] = token;
    token = strtok(NULL, " ");

  }

  tokens[i] = NULL;
  return tokens;
}
