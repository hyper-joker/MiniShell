/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** my_putchar
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funkytimes.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
