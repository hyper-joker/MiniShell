/*
** EPITECH PROJECT, 2022
** command_execution
** File description:
** command execution
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"
#include "struct.h"

char *my_strconcat(char *str, char *str2)
{
    int len = my_strlen(str);
    int len2 = my_strlen(str2);
    int len3 = len + len2;
    char *result = NULL;
    int count = 0;

    result = malloc(sizeof(char) * (len3 + 1));
    for (int i = 0; str[i] != '\0'; i += 1, count += 1)
        result[count] = str[i];
    for (int x = 0; str2[x] != '\0'; x += 1, count += 1)
        result[count] = str2[x];
    result[count] = '\0';
    return result;
}