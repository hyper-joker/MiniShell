/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdio.h>
#include <stdlib.h>
#include "funkytimes.h"

int my_getnbr(char const *str)
{
    int x = 0;
    int result = 0;
    int sign = 1;

    for (int y = 0; str[y] == '-' || str[y] == '+'; y += 1)
        sign *= -1;
    for (; str[x] != '\0'; x += 1);
    for (int i = 0; i < x; i += 1) {
        if (str[i] >= '0' && str[i] <= '9') {
            result *= 10;
            result += (str[i] - 48);
        } else if (str[i] != '-' && str[i] != '+')
            break;
    }
    return (result * sign);
}
