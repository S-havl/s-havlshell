#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define COMAND_LIMIT_CHARACTERS 1024 

int main(int argc, char *argv[]) {
    char comand[COMAND_LIMIT_CHARACTERS];

    printf("shavlshell> ");
    fgets(comand, sizeof(comand), stdin);
    
    comand[strcspn(comand, "\n")] = '\0'; 
    
    if (strcmp(comand, "cd ..") == 0) {
        chdir(".."); 
    }  
    return 0;
}
