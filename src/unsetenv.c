/*
** EPITECH PROJECT, 2022
** unsetenv.c
** File description:
** unsetenv.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funkytimes.h"
#include "struct.h"

int check_if_var_exists(char **env, char *str)
{
    int i = 0;

    for (;env[i] != NULL; i += 1) {
        if (compare(env[i], str, my_strlen(str)) == 1)
            return 1;
    }
    return 0;
}

char **my_unsetenv(char **env, char *str)
{
    int i = 0;
    int len = len_env(env);
    char **new_env = NULL;
    int j = 0;

    if (check_if_var_exists(env, str) == 1)
        len -= 1;
    new_env = malloc(sizeof(char *) * (len + 1));
    if (new_env == NULL)
        return NULL;
    for (; env[i] != NULL; i += 1) {
        if (compare(env[i], str, my_strlen(str)) != 1) {
            new_env[j] = my_strdup(env[i]);
            j += 1;
        }
    }
    new_env[j] = NULL;
    return new_env;
}
