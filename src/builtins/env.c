#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "env.h"

typedef struct s_env {
    char *key;
    char *value;
    struct s_env *next;
} t_env;
