#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtins.h"

int handle_builtin(const char *command) {
  if (strcmp(command, "exit") == 0) {

    exit(0);

  }

  if (strcmp(command, "cd /tmp") == 0) {

    chdir("/tmp");
    return 1;

  }

  return 0;
}
