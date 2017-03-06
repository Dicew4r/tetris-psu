##
## Makefile for Makefile in /home/saumon/pool/CPool_Day10/lib/my
##
## Made by mwamem
## Login   <anatole.zeyen@epitech.eu>
##
## Started on  Fri Oct 14 09:09:57 2016 Maxime Louet
## Last update Mon Mar  6 14:46:26 2017 anatole zeyen
##

CFLAGS	=	-Wextra -Wall -g3

SRCS	=	lol/main.c			\
		lol/my_strlen.c		\
		lol/new_str_to_wordtab.c	\
		lol/verif_param.c		\
		lol/my_strncpy.c		\
		lol/tools.c			\
		lol/my_strdup.c		\
		lol/debug.c			\
		lol/my_getnbr.c		\
		lol/my_strcmp.c		\
		lol/fcts_parse_args.c	\
		lol/parse_args.c		\
		lol/fcts_arrays.c		\
		lol/fcts_arrays2.c		\
		transform_tetrimino.c		\
		lol/check_double_arg.c	\
		lol/init_infos.c		\
		main.c			\
		handle_map.c		\
		create_map.c		\
		init.c			\
		lol/my_putnbr.c

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
