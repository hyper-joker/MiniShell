/*
** EPITECH PROJECT, 2021
** my_getenv
** File description:
** my_getenv
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"
#include "struct.h"

char **my_getenv(smd_t *smd)
{
    int i = 0;
    char **path = NULL;
    int error = 0;

    for (; smd->env[i] != NULL; i += 1) {
        error = compare(smd->env[i], "PATH=", 5);
        if (error == 1) {
            smd->stock = smd->stock2 = 0;
            path = str_to_str_array(smd->env[i] + 5, ':', smd);
            break;
        }
    }
    return path;
}
