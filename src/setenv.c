/*
** EPITECH PROJECT, 2021
** command_execution
** File description:
** command execution
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funkytimes.h"
#include "struct.h"

void env_null(smd_t *smd)
{
    free(smd->env);
    smd->env = malloc(sizeof(char *) * 2);
    smd->env[0] = malloc(sizeof(char) * 10);
    smd->env[0] = my_strcpy(smd->env[0], "PATH=/bin");
    smd->env[1] = NULL;
}

void copy_env_struct(char **env, smd_t *smd)
{
    int i = 0;
    int len = len_env(env);

    smd->env = malloc(sizeof(char *) * (len + 1));
    if (smd->env == NULL)
        return;
    for (i = 0; env[i] != NULL; i += 1) {
        smd->env[i] = my_strdup(env[i]);
    }
    smd->env[i] = NULL;
    if (smd->env[0] == NULL)
        env_null(smd);
}

char **copy_env(char **env, char *str, char *str2)
{
    int i = 0;
    int len = len_env(env);
    char **new_env = malloc(sizeof(char *) * (len + 2));
    int len_string = 0;
    int x = 0;

    if (new_env == NULL)
        return NULL;
    for (; env[i] != NULL; i += 1) {
        new_env[i] = my_strdup(env[i]);
    }
    new_env[i] = my_strconcat(str, "=");
    if (str2 != NULL)
        new_env[i] = my_strconcat(new_env[i], str2);
    new_env[i + 1] = NULL;
    return new_env;
}

char **replace_full(char **new_env, char *str, char *str2)
{
    int len = my_strlen(str);
    int len2 = my_strlen(str2);
    int len3 = len + len2;

    for (int i = 0; new_env[i] != NULL; i += 1) {
        if (compare(new_env[i], str, len) == 1) {
            free(new_env[i]);
            new_env[i] = malloc(sizeof(char) * (len3 + 2));
            if (new_env[i] == NULL)
                return NULL;
            new_env[i] = my_strconcat(str, "=");
            if (str2 != NULL)
                new_env[i] = my_strconcat(new_env[i], str2);
        }
    }
    return new_env;
}

void my_setenv(char **args, smd_t *smd)
{
    char **tmp = smd->env;

    if (args[1] == NULL){
        my_print_env(smd->env);
        return;
    }
    if ((args[1][0] >= 'a' && args[1][0] <= 'z') ||
    (args[1][0] >= 'A' && args[1][0] <= 'Z')) {
        for (int i = 0; smd->env[i] != NULL; i += 1)
            if (compare(smd->env[i], args[1],
                my_strlen(args[1])) == 1) {
                tmp = smd->env;
                smd->env = replace_full(smd->env, args[1], args[2]);
                free_tab(tmp);
                return;
            }
        tmp = smd->env;
        smd->env = copy_env(smd->env, args[1], args[2]);
        free_tab(tmp);
    }
}
