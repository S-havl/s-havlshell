#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "shell.h"
#include "parser.h"
#include "executor.h"
#include "builtins.h"

#define MAX_COMMAND_LENGTH 1024

int main() {
  char input[MAX_COMMAND_LENGTH];

  signal(SIGINT, SIG_IGN);

  while (1) {
    printf("shavlshell> ");
    if (!fgets(input, sizeof(input), stdin)) break;

    input[strcspn(input, "\n")] = '\0';

    if (handle_builtin(input)) continue;

    char **args = parse_command(input);

    if (args != NULL) {
      execute_command(args);
    }

  }
    
  return 0;
}
        
