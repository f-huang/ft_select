# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:52:41 by fhuang            #+#    #+#              #
#    Updated: 2016/09/13 10:41:43 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

CFLAGS = -c -Wall -Wextra -Werror

SRC_PATH = ./SRC/
SRC_NAME = $(shell ls SRC)
SRC = $(addprefix $(SRC_PATH), $(SCR_NAME))

OBJ_PATH = ./OBJ/
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INCLUDE_PATH = -Iinclude

.PHONY: clean fclean re all

all : $(NAME)

$(NAME): $(OBJ) $(SRC)
#	@echo "----------------------------LIBFT----------------------------"
	@echo "\033[32m" "-> Libft" "\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
#	@echo "\033[32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INCLUDE_PATH) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
