/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/25 13:13:41 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void _print_stacks_and_arr(t_head head)
{
	int i;

	printf("%s\n", "PRINT A");
	printf("==== next: %d ==== mid: %d ==== max: %d ====\n", head.next, head.mid, head.max);
	printf("|%-7s|%-7s|%-7s|%-7s|%-7s|\n", "rx:", "val:", "order:", "rrx:", "flag:"); //=====///////0000
	printf("-----------------------------------------\n");
	while (head.a)
	{
		printf("|%-7d|%-7d|%-7d|%-7d|%-7d|\n", head.a->rx, head.a->val, head.a->order, head.a->rrx, head.a->flag);
		head.a = head.a->next;
	}
	printf("\n");
	printf("%s\n", "PRINT B");
	printf("|%-7s|%-7s|%-7s|%-7s|%-7s|\n", "rx:", "val:", "order:", "rrx:", "flag:"); //=====///////0000
	printf("----------------------------------------\n");
	while (head.b)
	{
		printf("|%-7d|%-7d|%-7d|%-7d|%-7d|\n", head.b->rx, head.b->val, head.b->order, head.b->rrx, head.b->flag);
		// printf("|%-7d|%-7d|%-7d|\n", head.b->val, head.b->order, head.b->flag);
		head.b = head.b->next;
	}
	printf("\n");
	printf("======================================\n");
	printf("\n");
}


void	init(t_head **head)
{
	*head = (t_head *)malloc(sizeof(t_head));
	(*head)->a = NULL;
	(*head)->b = NULL;
	(*head)->commands = NULL;
	(*head)->flag = 0;
	(*head)->max = 0;
	(*head)->mid = 0;
	(*head)->next = 0;
}

void	check_input(char *num, t_head *head)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (i == 0 && (num[i] != '-' && !ft_isdigit(num[i])))
		{
			write(0, "Error\n", 6);
			free_and_exit(head, 5);
		}
		else if (i == 0 && num[i] == '-' && !ft_isdigit(num[i + 1]))
		{
			write(0, "Error\n", 6);
			free_and_exit(head, 5);
		}
		else if (i != 0 && !ft_isdigit(num[i]))
		{
			write(0, "Error\n", 6);
			free_and_exit(head, 5);
		}
		i++;
	}
}

long long	ft_atoi_long_long(const char *np)
{
	int					sign;
	long				res;

	sign = 1;
	res = 0;
	while (ft_isspace(*np))
		np++;
	if (*np == '-' || *np == '+')
		if (*np++ == '-')
			sign = -1;
	while (ft_isdigit(*np))
		res = (res * 10) + (*np++ - '0');
	return (res * sign);
}

void	check_max_int(char *num, t_head *head)
{
	if (ft_atoi_long_long(num) > 2147483647 || ft_atoi_long_long(num) < -2147483648)
	{
		write(0, "Error\n", 6);
		free_and_exit(head, 5);
	}
}

void	parse(int ac, char **av, t_head *head)
{
	int i;

	i = ac - 1;
	while (i > 0)
	{
		check_input(*(av + i), head);
		check_max_int(*(av + i), head);
		push(&head->a, ft_atoi(*(av + i)));
		head->a->flag = 0;
		i--;
	}
}

int	free_and_exit(t_head *head, int i)
{
	if (i == 0)
	{
		del_lst(head->a);
		free(head->sorted_arr);
		free(head);
	}
	else
	{
		del_lst(head->commands);
		del_lst(head->a);
		free(head->sorted_arr);
		free(head);
	}
	exit(1);
}

void	check_dup(t_lst *lsthead, t_head *head)
{
	t_lst	*tmp1;
	t_lst	*tmp2;
	int		eq;

	tmp1 = lsthead;
	while (tmp1)
	{
		eq = 0;
		tmp2 = lsthead;
		while (tmp2)
		{
			if (tmp1->val == tmp2->val)	
				eq++;
			tmp2 = tmp2->next;
		}
		if (eq > 1)
		{
			write(0, "Error\n", 6);
			free_and_exit(head, 4);
		}
		tmp1 = tmp1->next;
	}
	
}

int	main(int ac, char **av)
{
	t_head	*head;
	t_lst	*tmp;
	int		i;

	init(&head);
	parse(ac, av, head);
	get_sorted_arr(head);
	set_order(*head);
	check_dup(head->a, head);
	if (checking_for_sorting_a(head))
		return (free_and_exit(head, 0));
	qsort_stack_loop(head);
	optimize_command_count(head);
	print_optimized_commands(head);
	free_and_exit(head, 1);
	return (0);
}
