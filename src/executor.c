#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include "executor.h"

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {

        signal(SIGINT, SIG_DFL);
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);  

    } else if (pid > 0) {

        int status;
        waitpid(pid, &status, 0);

    } else {

        perror("fork");

    }
}
