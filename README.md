```ARG=\`ruby -e "puts (1..500).to_a.shuffle.join(' ')"\`; ./push_swap $ARG | ./checker $ARG && ./push_swap $ARG | wc -l && echo $ARG```

OR

```make && ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG) | ./checker $(echo $ARG) ;  echo $ARG ;valgrind ./push_swap $(echo $ARG)```

INC_DIRS = srcs/libft/inc/ srcs

LIBFT = srcs/libft/libft.a

CFLAGS = -Wall -Wextra -Werror
OPT_FLUGS = -O -g3
CC = gcc
FLAGS = -g -Wall -Werror -Wextra -pipe

SRCS = checking.c         exists.c   optimize_command_count.c  qsort_arr.c         rrp_off.c         special_cases.c         sr_off.c\
	checking_helper.c  get_lst.c  pop_lst.c                 qsort_stack_loop.c  second_phase.c    special_cases_helper.c \
	del_lst.c          main.c     push_lst.c                rrp.c               set_and_choise.c  sr.c 
SRCS_DIR = srcs/

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_DIR = od/

PATH_TO_SRCS = $(addprefix $(SRCS_DIR), $(SRCS))

PATH_TO_OBJS = $(addprefix $(OBJS_DIR), $(OBJS))
