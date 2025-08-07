#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "env.h"

t_env *create_node(const char *key, const char *value) {
    t_env *node = malloc(sizeof(t_env));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

