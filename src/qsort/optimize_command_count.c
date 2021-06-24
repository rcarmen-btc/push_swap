/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_command_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/19 23:53:2 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	optimize_hepler(t_lst **first_prt, t_lst **second_prt)
{
	if ((*first_prt)->val != 0
		&& (((*first_prt)->val == 3 && (*second_prt)->val == 4)
			|| ((*first_prt)->val == 4 && (*second_prt)->val == 3)))
	{
		(*first_prt)->val = 9;
		(*second_prt)->val = 0;
	}
	if ((*first_prt)->val != 0
		&& (((*first_prt)->val == 5 && (*second_prt)->val == 6)
			|| ((*first_prt)->val == 6 && (*second_prt)->val == 5)))
	{
		(*first_prt)->val = 10;
		(*second_prt)->val = 0;
	}
	if ((*first_prt)->val != 0
		&& (((*first_prt)->val == 7 && (*second_prt)->val == 8)
			|| ((*first_prt)->val == 8 && (*second_prt)->val == 7)))
	{
		(*first_prt)->val = 11;
		(*second_prt)->val = 0;
	}
	(*first_prt) = (*first_prt)->next;
	(*second_prt) = (*second_prt)->next;
}

int	optimize_command_count(t_head *head)
{
	t_lst	*first_prt;
	t_lst	*second_prt;

	if (get_lst_len(head->a) < 5)
		return (1);
	first_prt = head->commands;
	second_prt = head->commands->next;
	while (second_prt)
		optimize_hepler(&first_prt, &second_prt);
}

void	if_stuff(t_lst *tmp)
{
	if (tmp->val != 0)
	{
		if (tmp->val == 1)
			printf("pa\n");
		else if (tmp->val == 2)
			printf("pb\n");
		else if (tmp->val == 3)
			printf("rra\n");
		else if (tmp->val == 4)
			printf("rrb\n");
		else if (tmp->val == 5)
			printf("sa\n");
		else if (tmp->val == 6)
			printf("sb\n");
		else if (tmp->val == 7)
			printf("ra\n");
		else if (tmp->val == 8)
			printf("rb\n");
		else if (tmp->val == 9)
			printf("rrr\n");
		else if (tmp->val == 10)
			printf("ss\n");
		else if (tmp->val == 11)
			printf("rr\n");
	}
}

void	print_optimized_commands(t_head *head)
{
	t_lst	*tmp;

	tmp = head->commands;
	while (tmp)
	{
		if_stuff(tmp);
		tmp = tmp->next;
	}
}
