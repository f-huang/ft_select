# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:38:13 by fhuang            #+#    #+#              #
#    Updated: 2016/09/16 13:52:10 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra

SRC_PATH = ./SRC/

SRC_NAME = $(shell ls $(SRC_PATH))

SRC = $(addprefix $(SRC_PATH), $(SCR_NAME))

OBJ_PATH = ./OBJ/

OBJ_NAME = $(SRC_NAME:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

HEADER_PATH = -Iinclude/

LIBFT_PATH = -Llibft -Lft_printf

LIBFT = -lft -lftprintf

LIB = -ltermcap

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@echo "----------------------------FT_SELECT----------------------------"
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(LIBFT_PATH) $(LIBFT) $^ -o $@ $(LIB)	#$^ for $(OBJ) and $@ for $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
#	@$(CC) $(CFLAGS) $(HEADER_PATH)  -c $< -o $@
	@$(CC) $(HEADER_PATH)  -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C libft
	@$(MAKE) fclean -C ft_printf

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf

re : fclean all
