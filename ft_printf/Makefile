# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:38:13 by fhuang            #+#    #+#              #
#    Updated: 2016/09/13 10:41:24 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

SRC_PATH = ./SRC/

SRC_NAME = $(shell ls SRC)

SRC = $(addprefix $(SRC_PATH), $(SCR_NAME))

OBJ_PATH = ./OBJ/

OBJ_NAME = $(SRC_NAME:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

HEADER_PATH = -Iinclude/

LIBFT = -lft


.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@echo "\033[32m" "-> Ft_printf" "\033[0m"
#	@echo "----------------------------FT_PRINTF----------------------------"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
#	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADER_PATH)  -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re : fclean all
