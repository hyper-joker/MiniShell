/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** my_strlen
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"
#include "struct.h"

int my_strlen(char const *str)
{
    int i = 0;
    if (str == NULL)
        return 0;
    for (;str[i] != '\0'; i += 1);
    return (i);
}
