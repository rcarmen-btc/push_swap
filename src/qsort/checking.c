/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/25 16:18:02 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	checking_for_sorting_a(t_head *head)
{
	t_lst	*tmp;
	int		i;

	tmp = head->a;
	i = 0;
	while (tmp)
	{
		if (tmp->val == head->sorted_arr[i])
		{
			tmp = tmp->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	checking_for_sorting_b(t_head *head)
{
	t_lst	*tmp;
	int		len;
	int		pre;
	int		i;

	pre = head->b->order;
	tmp = head->b->next;
	len = get_lst_len(head->b);
	i = 0;
	while (tmp)
	{
		if (tmp->order < pre)
			return (0);
		pre = tmp->order;
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	check_zero_or_greater_cycle(t_head *head)
{
	t_lst	*tmp;

	tmp = head->a;
	while (tmp)
	{
		if (tmp->flag != 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_zeros_in_the_end(t_head *head)
{
	t_lst	*tmp;
	int		i;

	tmp = head->a;
	i = 1;
	while (tmp)
	{
		if (tmp->order != i)
			return (tmp->order);
		i++;
		tmp = tmp->next;
	}
	return (0);
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
