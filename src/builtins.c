#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "builtins.h"

int handle_builtin(char **args) {
    if (args[0] == NULL) {
        return 0;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    if (strcmp(args[0], "cd") == 0) {
        const char *target = args[1];

        if (target == NULL) {
            target = getenv("HOME");
            if (target == NULL) {
                fprintf(stderr, "cd: the HOME could not be determined\n");
                return 1;
            }
        }

        if (chdir(target) != 0) {
            perror("cd");
        }

        return 1;

    }

    return 0;
}
