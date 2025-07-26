#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
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

        char **args = parse_command(input);

        if (args == NULL || args[0] == NULL) {
            free(args);
            continue;
        }

        if (handle_builtin(args)) {
            free(args);
            continue;
        }

        execute_command(args);

        free(args);
    }
    
      return 0;
}
        
