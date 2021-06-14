/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/14 04:09:30 by rcarmen          ###   ########.fr       */
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
	t_head	*tmphead;
	int		i;

	head->max = find_max_order(head->a);
	head->next = 1;
	head->mid = head->max / 2 + head->next;
	head->flag = 0;
	tmphead = head;
	i = 0;
	while (i < head->max)
	{
		if (tmphead->a->order <= head->mid)
			pb(&tmphead);
		else
			ra(&tmphead);
		i++;
	}
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	_print_stacks_and_arr(*head);
	head->max = head->mid;
	head->mid = (head->max - head->next) / 2 + head->next;
	head->flag++;
	i = 0;
	while (i < head->max)
	{
		if (tmphead->b->order <= head->mid)
		{
			if (tmphead->b->order == tmphead->next)
			{
				pa(&tmphead);
				ra(&tmphead);
				tmphead->next++;
			}
			else
			{
				tmphead->b->flag = head->flag;
				pa(&tmphead);
			}
		}
		else
			rb(&tmphead);
		i++;
	}
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	_print_stacks_and_arr(*head);
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