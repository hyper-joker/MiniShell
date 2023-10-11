/*
** EPITECH PROJECT, 2022
** len_env.c
** File description:
** len_env.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funkytimes.h"
#include "struct.h"

int len_env(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i += 1);
    return i;
}