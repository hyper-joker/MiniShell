/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** my_strcpy
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"

char *my_strcpy(char *dest, char const *src)
{
    int n = 0;
    int len = my_strlen(src);

    dest = malloc(sizeof(char) * (len + 1));
    while (src[n] != '\0') {
        dest[n] = src[n];
        n += 1;
    }
    dest[n] = '\0';
    return (dest);
}
