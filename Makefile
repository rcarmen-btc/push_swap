# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#              #
#    Updated: 2021/06/25 13:13:37 by rcarmen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INC_DIR = include src/libft/inc
INC = include/lst.h include/main.h src/libft/inc/libft.h

SRC = main.c
SRC_DIR = src

LST_SRC = get_lst.c pop_lst.c push_lst.c del_lst.c
LST_SRC_DIR = src/lstlib

OPER_SRC = sr.c rrp.c sr_off.c rrp_off.c
OPER_SRC_DIR = src/operations

QSORT_STACKS_SRC = optimize_command_count.c qsort_stack_loop.c checking.c exists.c set_and_choise.c  qsort_arr.c second_phase.c special_cases.c
QSORT_STACKS_SRC_DIR = src/qsort

LIBFT = src/libft/libft.a

ALL_SRC = $(addprefix $(SRC_DIR)/, $(SRC)) \
	$(addprefix $(LST_SRC_DIR)/, $(LST_SRC)) \
	$(addprefix $(OPER_SRC_DIR)/, $(OPER_SRC)) \
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

t500:
	@echo ""
	@ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; \
	echo $$ARG ; ./push_swap $$ARG | ./checker_linux $$ARG; sleep 1; echo ""; \
	echo "The size of the list of instructions: "; ./push_swap $$ARG | wc -l;
	@echo ""

t100:
	@echo ""
	@ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; \
	echo $$ARG ; ./push_swap $$ARG | ./checker_linux $$ARG; sleep 1; echo ""; \
	echo "The size of the list of instructions: "; ./push_swap $$ARG | wc -l
	@echo ""

t5:
	@echo ""
	@ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; \
	echo $$ARG ; ./push_swap $$ARG | ./checker_linux $$ARG; sleep 1; echo ""; \
	echo "The size of the list of instructions: "; ./push_swap $$ARG | wc -l
	@echo ""

t3:
	@echo ""
	@ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; \
	echo $$ARG ; ./push_swap $$ARG | ./checker_linux $$ARG; sleep 1; echo ""; \
	echo "The size of the list of instructions: "; ./push_swap $$ARG | wc -l
	@echo ""
