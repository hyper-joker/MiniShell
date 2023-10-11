/*
** EPITECH PROJECT, 2022
** str_to_array
** File description:
** str_to_array+
*/

#include <stdlib.h>
#include <string.h>
#include "struct.h"

int count_sep(char *str, char sep)
{
    int sep_nb = 0;

    if (str == NULL) return 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == sep)
            sep_nb += 1;
    }

    return sep_nb;
}

int count_char(char *str, char sep, smd_t *index)
{
    int str_char = 0;

    if (str == NULL) return 0;
    for (; str[index->stock2] != '\0'
    && str[index->stock2] != sep; index->stock2 += 1){
        str_char += 1;
    }
    index->stock2 += 1;

    return str_char;
}

void fill(const char *first, char *second, char sep, smd_t *i)
{
    int tmp = 0;

    if (first == NULL || second == NULL) return;
    for (; first[i->stock] != '\0'
    && first[i->stock] != sep; i->stock += 1, tmp += 1){
        second[tmp] = first[i->stock];
    }
    second[tmp] = '\0';
    i->stock += 1;
}

char **str_to_str_array(char *str, char sep, smd_t *index)
{
    int sep_nb = count_sep(str, sep);
    char **tmp =  malloc(sizeof(char *) * (sep_nb + 2));
    int len = 0;
    int i = 0;

    if (str == NULL) return NULL;
    if (tmp == NULL) return NULL;
    for (; i < sep_nb + 1; i += 1) {
        len = count_char(str, sep, index);
        tmp[i] = malloc(sizeof(char) * (len + 1));
        if (tmp[i] == NULL) return NULL;
        fill(str, tmp[i], sep, index);
    }
    tmp[i] = NULL;
    return tmp;
}
