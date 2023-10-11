/*
** EPITECH PROJECT, 2021
** file_checker
** File description:
** file_checker
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"
#include "struct.h"

int checkIfFileExists(const char *filename)
{
    struct stat buffer;
    int exist = stat(filename, &buffer);

    if (exist == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void my_print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

int my_global_checker_2(char *input, smd_t *smd)
{
    char **buffer = NULL;
    char **tmp = NULL;
    char *error_unset = "unsetenv: Too few arguments.\n";
    char *error_set = "setenv: Too many arguments.\n";
    char *error_cd = "cd: Too many arguments.\n";
    int count = 0;

    smd->stock = smd->stock2 = 0;
    buffer = str_to_str_array(input, ' ', smd);
    for (int i = 0; buffer[i] != NULL; i += 1, count += 1);
    if (my_strcmp(buffer[0], "setenv") == 0) {
        if (count > 3) {
            write(2, error_set, my_strlen(error_set));
            return 84;
        }
        my_setenv(buffer, smd);
        free_tab(buffer);
        return 1;
    } else if (my_strcmp(buffer[0], "cd") == 0) {
        if (count > 2) {
            write(2, error_cd, my_strlen(error_cd));
            return 84;
        }
        my_cd(smd->env, buffer, smd);
        free_tab(buffer);
        return 1;
    } else if (my_strcmp(buffer[0], "unsetenv") == 0) {
        if (count == 1) {
            write(2, error_unset, my_strlen(error_unset));
            return 84;
        }
        tmp = smd->env;
        smd->env = my_unsetenv(smd->env, buffer[1]);
        free_tab(tmp);
        free_tab(buffer);
        return 1;
    }
    free_tab(buffer);
    return 0;
}

int my_global_checker(char *input, smd_t *smd)
{
    int result = 0;

    smd->stock = smd->stock2 = 0;
    if (my_strcmp(input, "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    } else if (my_strcmp(input, "env") == 0) {
        my_print_env(smd->env);
        return 1;
    } else {
        result = my_global_checker_2(input, smd);
    }
    return result;
}
