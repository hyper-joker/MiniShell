/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** my_strncmp
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"
#include "struct.h"

int compare(const char *str, const char *str2, int n)
{
    int i = 0;

    for (; str[i] != '\0' && str2[i] != '\0' && i < n; i += 1) {
        if (str[i] != str2[i])
            return 0;
    }
    if (i != n && (str[i] != '\0' || str2[i] != '\0'))
        return 0;
    return 1;
}
