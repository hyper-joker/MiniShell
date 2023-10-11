##
## EPITECH PROJECT, 2021
## MakeFile
## File description:
## make
##

CC = gcc

SRC =	src/main.c 					\
		src/my_putstr.c 			\
		src/my_put_nbr.c 			\
		src/my_putchar.c 			\
		src/file_checker.c 			\
		src/my_getnbr.c 			\
		src/my_strcpy.c 			\
		src/unsetenv.c 				\
		src/my_strncmp.c 			\
		src/my_strconcat.c 			\
		src/setenv.c 				\
		src/len_env.c 				\
		src/free_shit.c 			\
		src/my_strdup.c				\
		src/my_strcmp.c				\
		src/my_getenv.c				\
		src/my_gethome.c			\
		src/command_executions.c	\
		src/my_strlen.c				\
		src/str_to_str_array.c

OBJS = $(SRC:.c=.o)

RM = rm -f

CFLAGS = -W -Wall -Wextra -g -I./include

NAME = mysh

all: 	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

sweat: clean all

.phony: all clean fclean re sweat
