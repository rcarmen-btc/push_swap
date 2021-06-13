# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#              #
#    Updated: 2021/06/13 11:32:55 by rcarmen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INC_DIR = include src/libft/inc
INC = include/lst.h include/main.h src/libft/inc/libft.h

SRC = main.c
SRC_DIR = src

LST_SRC = get_lst.c pop_lst.c push_lst.c
LST_SRC_DIR = src/lstlib

OPER_SRC = sr.c rrp.c
OPER_SRC_DIR = src/operations

QSORT_ARR_SRC = qsort_arr.c
QSORT_ARR_SRC_DIR = src/qsort_arr

QSORT_STACKS_SRC = init_stack_a.c
QSORT_STACKS_SRC_DIR = src/qsort_stacks

LIBFT = src/libft/libft.a

ALL_SRC = $(addprefix $(SRC_DIR)/, $(SRC)) \
	$(addprefix $(LST_SRC_DIR)/, $(LST_SRC)) \
	$(addprefix $(OPER_SRC_DIR)/, $(OPER_SRC)) \
	$(addprefix $(QSORT_ARR_SRC_DIR)/, $(QSORT_ARR_SRC)) \
	$(addprefix $(QSORT_STACKS_SRC_DIR)/, $(QSORT_STACKS_SRC))


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