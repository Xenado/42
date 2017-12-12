# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaille <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 14:22:43 by jcaille           #+#    #+#              #
#    Updated: 2017/11/24 16:21:45 by jcaille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

SRC_NAME	=	main.c				\
				ft_readfile.c		\
				ft_checker.c		\
				ft_change_n_ret.c	\
				ft_place_ul.c		\
				ft_fill_list.c		\
				ft_fill_grid.c		\
				ft_fillit.c

OBJ_NAME	=	$(SRC:.c=.o)
SRC_PATH	=	.
OBJ_PATH	=	.
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
CPPFLAGS	=	-I.

LDLIBS		=	-lft
LDFLAGS		=	-Llibft

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $^

clean:
	@$(MAKE) clean -C libft
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
