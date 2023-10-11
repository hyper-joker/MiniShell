/*
** EPITECH PROJECT, 2022
** my_gethome
** File description:
** my_gethome
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

char *my_gethome(char **env)
{
    char string[1000];
    int tmp = 0;

    for (int i = 0; env[i] != NULL; i += 1) {
        if (env[i][0] == 'H' && env[i][1] == 'O'
            && env[i][2] == 'M' && env[i][3] == 'E') {
            for (int g = 5; env[i][g] != '\0'; g += 1, tmp += 1)
                string[tmp] = env[i][g];
            string[tmp] = '\0';
            break;
        }
    }
    return my_strdup(string);
}

