#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define COMAND_LIMIT_CHARACTERS 1024

int main(int argc, char *argv[]) {
  char comand[COMAND_LIMIT_CHARACTERS];

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

    pid_t pid = fork();

    if (pid == 0) {

      printf("I am the son.\n");
      exit(0);
           
    } else if (pid > 0) {

      printf("I am the father.\n");
      while(NULL);

    } else {

      perror("fork");

    }
    
  }

  return 0;

}
        
