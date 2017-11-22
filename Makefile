# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaille <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 14:22:43 by jcaille           #+#    #+#              #
#    Updated: 2017/11/21 12:29:05 by jcaille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

SRC_NAME	=	
OBJ_NAME	=	$(SRC:.c=.o)
SRC_PATH	=	.
OBJ_PATH	=	.
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(SRC_NAME))

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
CPPFLAGS	=	-I.

LDLIBS		=	-lft
LDFLAGS		=	-Llibft

all: lft $(NAME)
	
lft:
	$(MAKE) -C libft

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $<

clean:
	$(MAKE) clean -C libft
	@$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
