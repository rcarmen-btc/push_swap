/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/07/07 21:43:05 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

void	parse(int ac, char **av, t_head *head)
{
	int	i;

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

int	main(int ac, char **av)
{
	t_head	*head;

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
