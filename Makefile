# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#              #
#    Updated: 2021/07/07 23:06:56 by rcarmen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = srcs/libft/libft.a
CC = gcc

INC_DIR = srcs/libft/inc

MAIN_SRCS = main.c
MAIN_SRCS_DIR = srcs

LST_SRCS = get_lst.c pop_lst.c push_lst.c del_lst.c
LST_SRCS_DIR = srcs/lstlib

OPER_SRCS = sr.c rrp.c sr_off.c rrp_off.c
OPER_SRCS_DIR = srcs/operations

QSORT_STACKS_SRCS = checking.c qsort_stack_loop.c \
	checking_helper.c         second_phase.c \
	exists.c                  set_and_choise.c \
	optimize_command_count.c  special_cases.c \
	qsort_arr.c               special_cases_helper.c
QSORT_STACKS_SRCS_DIR = srcs/qsort

SRCS = $(MAIN_SRCS) $(LST_SRCS) $(OPER_SRCS) $(QSORT_STACKS_SRCS)
SRCS_DIRS = $(MAIN_SRCS_DIR) $(LST_SRCS_DIR) $(OPER_SRCS_DIR) $(QSORT_STACKS_SRCS_DIR)

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_DIR = objs

PATH_TO_SRCS = $(addprefix $(MAIN_SRCS_DIR)/, $(MAIN_SRCS)) \
	$(addprefix $(LST_SRCS_DIR)/, $(LST_SRCS)) \
	$(addprefix $(OPER_SRCS_DIR)/, $(OPER_SRCS)) \
	$(addprefix $(QSORT_STACKS_SRCS_DIR)/, $(QSORT_STACKS_SRCS))

PATH_TO_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))

FLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(PATH_TO_OBJS)
	@$(MAKE) -C srcs/libft
	echo $(OBJ)
	$(CC) $^ @S

VPATH = $(SRCS_DIRS)

%.o: %.c
	gcc -c -MD $(addprefix -I, $(SRCS_DIRS)) $(FLAGS) -Ift $<

clean:
	$(MAKE) clean -C srcs/libft
	rm -f *

fclean:
	$(MAKE) fclean -C srcs/libft
	rm -f push_swap

nclean:
	rm -f push_swap

re: fclean all

lol:
	$(CC) $(FLAGS) $(ALL_SRCS) $(addprefix -I, $(INC_DIR)) $(LIBFT) -o $(NAME)