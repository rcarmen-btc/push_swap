# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#              #
#    Updated: 2021/06/11 04:29:17 by rcarmen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INC_DIR = include src/libft/inc
INC = include/lst.h include/main.h src/libft/inc/libft.h

SRC_DIR = src
SRC = main.c 

LST_DIR = src/lstlib
LST_SRC = get_lst.c pop_lst.c push_lst.c

OPER_DIR = src/operations
OPER_SRC = sr.c rrp.c

LIBFT = src/libft/libft.a

ALL_SRC = $(addprefix $(SRC_DIR)/, $(SRC)) \
	$(addprefix $(LST_DIR)/, $(LST_SRC)) \
	$(addprefix $(OPER_DIR)/, $(OPER_SRC)) 

OBJ = $(patsubst %.c, %.o, $(ALL_SRC))

CC = gcc

FLAGS = -g # -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(ALL_SRC) $(INC)
	@$(MAKE) -C src/libft
	$(CC) $(FLAGS) $(ALL_SRC) $(addprefix -I, $(INC_DIR)) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C src/libft

fclean:
	$(MAKE) fclean -C src/libft
	rm -f push_swap

nclean:
	rm -f push_swap

re: nclean all