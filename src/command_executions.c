/*
** EPITECH PROJECT, 2021
** command_execution
** File description:
** command execution
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "funkytimes.h"
#include "struct.h"

char *path_finder(char *buffer, char **path)
{
    int y = 0;
    int i = 0;
    char string[200];

    for (; path[i] != NULL; i += 1) {
        for (y = 0; path[i][y] != '\0'; y += 1)
            string[y] = path[i][y];
        string[y] = '/';
        y += 1;
        for (int x = 0; buffer[x] != '\0'; x += 1, y += 1)
            string[y] = buffer[x];
        string[y] = '\0';
        if (checkIfFileExists(string))
            if (access(string, X_OK) != -1)
                return my_strdup(string);
    }
    if (checkIfFileExists(buffer)) {
        if (access(buffer, X_OK) != -1)
            return my_strdup(buffer);
    }
    path[i] = NULL;
    return my_strdup("not exist");
}

void command_execution(char *input, smd_t *i)
{
    i->stock = 0;
    i->stock2 = 0;
    char **buffer = str_to_str_array(input, ' ', i);
    int fk = 0;
    int status = 0;
    char **path = my_getenv(i);
    char *checker = path_finder(buffer[0], path);
    char *check = "not exist";

    if (my_global_checker(input, i) == 1) {
        free_tab(path);
        free_tab(buffer);
        free(checker);
        return;
    }
    if (checker == check) {
        my_putstr(buffer[0]);
        my_putstr(": no such file or directory\n");
        free_tab(path);
        free_tab(buffer);
        free(checker);
        return;
    } else {
        fk = fork();
        if (fk > 0)
            waitpid(fk, &status, WUNTRACED | WCONTINUED);
        else if (fk == 0) {
            free(buffer[0]);
            buffer[0] = checker;
            execve(checker, buffer, i->env);
        }
    }
    free_tab(path);
    free_tab(buffer);
    free(checker);
}

char *my_getpwd(char *pwd, char *name)
{
    char string[1000];
    int tmp = 0;

    for (int i = 0; pwd[i] != '\0'; i += 1, tmp += 1)
        string[tmp] = pwd[i];
    string[tmp] = '/';
    tmp += 1;
    for (int x = 0; name[x] != '\0'; x += 1, tmp += 1)
        string[tmp] = name[x];
    string[tmp] = '\0';
    return my_strdup(string);
}

void my_cd(char **env, char **buffer, smd_t *i)
{
    char *home = NULL;
    char *old_pwd = NULL;
    int x = 0;
    if (buffer[1] == NULL || my_strcmp(buffer[1], "--") == 0) {
        home = my_gethome(env);
        x = chdir(home);
    } else if (buffer[1] != NULL) {
        old_pwd = getcwd(old_pwd, 1000);
        if (my_strcmp(buffer[1], "-") == 0) {
            x = chdir(old_pwd);
        } else {
            x = chdir(buffer[1]);
        }
        free(old_pwd);
    }
    if (x < 0)
        my_putstr("directory couldn't be changed\n");
    free(home);
}
