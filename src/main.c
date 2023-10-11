/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
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

int find_nb_args(char **program)
{
    int nb = 0;

    if (program[1] != NULL)
        for (int i = 1; program[i] != NULL; i += 1)
            nb += 1;
    return nb;
}

int main(int ac, char **av, char **env)
{
    char *buffer = NULL;
    (void) av;
    smd_t *smd = malloc(sizeof(smd_t));
    size_t bufsize = 0;
    ssize_t characters = 0;

    copy_env_struct(env, smd);
    if (ac > 1)
        return (84);
    while (characters >= 0) {
        my_putstr("$>my_prompt ");
        characters = getline(&buffer, &bufsize, stdin);
        if (characters != -1) {
            buffer[characters - 1] = '\0';
            command_execution(buffer, smd);
        } else {
            my_putchar('\n');
            break;
        }
    }
    free(smd);
    free(buffer);
    return 0;
}
