/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** my_strcmp
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"
#include "struct.h"

int my_strcmp(char const *str1, char const *str2)
{
    int len_str1 = 0;
    int len_str2 = 0;

    for (len_str1 = 0; str1[len_str1] != '\0'; len_str1 += 1);
    for (len_str2 = 0; str2[len_str2] != '\0'; len_str2 += 1);
    if (len_str1 > len_str2 || len_str1 < len_str2)
        return 1;
    for (int i = 0; str1[i] != '\0'; i += 1)
        if (str1[i] != str2[i])
            return 1;
    return 0;
}
