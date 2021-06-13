/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/13 17:01:42 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	find_max_order(t_lst *head)
{
	int	max;

	max = head->order;
	head = head->next;
	while (head)
	{
		if (head->order > max)
			max = head->order;
		head = head->next;
	}
	return (max);
}

void	qsort_stack_loop(t_head *head)
{
	head->max = find_max_order(head->a);
	head->next = 1;
	head->mid = head->max / 2 + head->next;
	printf("%d - %d\n", head->max, head->mid);
}

int	find_el_with_order(t_lst *head, int order)
{
	while (head)
	{
		if (order == head->order)
			return (head->val);
		head = head->next;
	}
	return (-1);
}

void	set_order(t_head head)
{
	int		i;

	while (head.a)
	{
		i = 0;
		while (head.sorted_arr[i])
		{
			if (head.a->val == head.sorted_arr[i])
			{
				head.a->order = i + 1;
				break ;
			}
			i++;
		}
		head.a = head.a->next;
	}
}

void	parse(int ac, char **av, t_head *head)
{
	while (ac - 1 > 0)
	{
		push(&head->a, ft_atoi(*(av + (ac - 1))));
		ac--;
	}
}