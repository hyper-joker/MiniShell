/*
** EPITECH PROJECT, 2022
** free_shit.c
** File description:
** free_shit.c
*/

#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"
#include "struct.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
}