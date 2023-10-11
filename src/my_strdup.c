/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *src);

char *my_strdup(char  const *src)
{
    char *string;
    int n = 0;
    int x = my_strlen(src);
    string = malloc(sizeof(char) * (x + 1));
    if (string == NULL)
        return NULL;
    while (src[n] != '\0') {
        string[n] = src[n];
        n += 1;
    }
    string[n] = '\0';
    return (string);
}
