# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 09:10:15 by wasahmed          #+#    #+#              #
#    Updated: 2019/08/30 19:08:34 by wasahmed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = blocks.c check_link.c checker.c displayl.c exec.c filetype.c l_perms.c \
	  ls_basic.c ls_flag_handler.c ls_printer.c ls_sorter.c main.c mod_ctime.c \
	  r_l.c recurse.c
	  
OBJ_NAME = blocks.o check_link.o checker.o displayl.o exec.o filetype.o l_perms.o \
	  ls_basic.o ls_flag_handler.o ls_printer.o ls_sorter.o main.o mod_ctime.o \
	  r_l.o recurse.o

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	@echo "<<<<<Compiling $(NAME)>>>>>"
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(SRC) libft/libft.a
	@echo "DONE!"

clean:
		/bin/rm -f $(OBJ_NAME)

fclean:
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "<<<<<Removed exe and cleaned libft>>>>>"

re: fclean all

normall:
	@norminette $(SRC) *.h libft/*

git:
	git add -A
	git commit -m "progress"
	git push origin master
