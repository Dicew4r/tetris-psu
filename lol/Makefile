##
## Makefile for Makefile in /home/saumon/pool/CPool_Day10/lib/my
##
## Made by mwamem
## Login   <anatole.zeyen@epitech.eu>
##
## Started on  Fri Oct 14 09:09:57 2016 Maxime Louet
## Last update Thu Mar  2 10:22:43 2017 Antoine
##

CFLAGS	=	-Wextra -Wall -Werror -g3

SRCS	=	main.c			\
		my_strlen.c		\
		new_str_to_wordtab.c	\
		my_strncpy.c		\
		tools.c			\
		my_strdup.c		\
		debug.c			\
		my_getnbr.c		\
		my_strcmp.c		\
		fcts_parse_args.c	\
		parse_args.c		\
		fcts_arrays.c		\
		fcts_arrays2.c		\
		check_double_arg.c	\
		init_infos.c		\
		my_putnbr.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

NAME	=	tetris

all:	 $(NAME)

$(NAME):	 $(OBJS)
	gcc $(OBJS) -lncurses -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
