# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#              #
#    Updated: 2021/07/10 00:34:32 by rcarmen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBS = -L./srcs/libft -lft

CC = gcc
FLAGS = -g -Wall -Werror -Wextra -pipe 

INC_DIRS = inc/ srcs/libft/inc/

SRCS =	checking.c         main.c                    qsort_stack_loop.c  special_cases.c\
		checking_helper.c  optimize_command_count.c  rrp.c               special_cases_helper.c\
		del_lst.c          pop_lst.c                 rrp_off.c           sr.c\
		exists.c           push_lst.c                second_phase.c      sr_off.c\
		get_lst.c          qsort_arr.c               set_and_choise.c

SRCS_DIR = srcs/

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_DIR = od/

PATH_TO_SRCS = $(addprefix $(SRCS_DIR), $(SRCS))

PATH_TO_OBJS = $(addprefix $(OBJS_DIR), $(OBJS))

D_PATH = $(patsubst %.o, %.d, $(PATH_TO_OBJS))

all: od $(NAME)

$(NAME): $(PATH_TO_OBJS)
	@$(MAKE) -C srcs/libft
	$(CC) $^ -o $(NAME) $(LIBS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32mSuccessfully compiled push_swap\033[0m"

include	$(wildcard $(D_PATH))

VPATH = $(SRCS_DIR)

$(OBJS_DIR)%.o: %.c $(INC_DIR)
	gcc -c -MD $(FLAGS) $< -o $@ -MD $(addprefix -I, $(INC_DIRS))
	@echo "\033[90m[\033[32mOK\033[90m]\033[33mCompiling $<\033[0m"

od:
	mkdir -p od/

clean:
	@$(MAKE) clean -C srcs/libft
	rm -rf od/

fclean: clean
	@$(MAKE) fclean -C srcs/libft
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re




