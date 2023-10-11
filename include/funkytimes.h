/*
** EPITECH PROJECT, 2021
** funkytimes
** File description:
** funkytimes
*/

#ifndef __PROTOTYPES__
    #define __PROTOTYPES__

#include "struct.h"

int main(int ac, char **av, char **env);
int find_nb_args(char **program);
int my_getnbr(char const *str);
void my_print_env(char **env);
int my_put_nbr(int n);
int checkIfFileExists(const char *filename);
int my_strcmp(char const *str1, char const *str2);
void my_putchar(char c);
char *path_finder(char *buffer, char **path);
char **my_getenv(smd_t *index);
int my_putstr(char const *str);
int my_strlen(char const *str);
int count_char(char *str, char sep, smd_t *index);
void command_execution(char *input, smd_t *i);
char *my_strdup(char  const *src);
char *my_gethome(char **env);
int my_cd_checker(char **input, char **env, smd_t *smd);
int my_global_checker(char *input, smd_t *smd);
void my_cd(char **env, char **buffer, smd_t *smd);
char **str_to_str_array(char *str, char sep, smd_t *index);
void my_setenv(char **args, smd_t *smd);
char **copy_env(char **env, char *str, char *str2);
void copy_env_struct(char **env, smd_t *smd);
char *my_strcpy(char *dest, char const *src);
char *my_strconcat(char *str, char *str2);
int compare(const char *str, const char *str2, int n);
char **my_unsetenv(char **env, char *str);
void free_tab(char **tab);
int len_env(char **env);

#endif
