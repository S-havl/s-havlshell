#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define COMAND_LIMIT_CHARACTERS 1024
#define MAX_TOKENS 1024

int main(int argc, char *argv[]) {
  char comand[COMAND_LIMIT_CHARACTERS];
  char *tokens[MAX_TOKENS];

  signal(SIGINT, SIG_IGN);
  
  while(1) {
    printf("shavlshell> ");
    fgets(comand, sizeof(comand), stdin);

    comand[strcspn(comand, "\n")] = '\0';

    if (strcmp(comand, "cd ..") == 0) {

      chdir("..");
      continue;

    }

    if (strcmp(comand, "exit") == 0) {

      break;

    }

    int i = 0;
    char *token = strtok(comand, " ");

    while (token != NULL && i < MAX_TOKENS - 1) {

      tokens[i++] = token;

      token = strtok(NULL, " ");

      tokens[i] = NULL;

    }

    pid_t pid = fork();

    if (pid == 0) {

      signal(SIGINT, SIG_DFL);
      execvp(tokens[0], tokens);
      perror("execvp");
      exit(EXIT_FAILURE);
           
    } else if (pid > 0) {

      int status;
      waitpid(pid, &status, 0);

    } else {

      perror("fork");

    }
    
  }

  return 0;

}
        
