/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/15 02:28:29 by rcarmen          ###   ########.fr       */
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
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	i = 0;
	while (i < head->max)
	{
		if (tmphead->a->order <= head->mid)
			pb(&tmphead);
		else
			ra(&tmphead);
		i++;
	}
	_print_stacks_and_arr(*head);
	head->max = head->mid;
	head->mid = (head->max - head->next) / 2 + head->next;
	head->flag++;
	i = 0;
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	while (i < head->max)
	{
		_print_stacks_and_arr(*head);
		if (tmphead->b->order >= head->mid)
		{
			tmphead->b->flag = head->flag;
			if (tmphead->b->order == tmphead->next)
			{
				pa(&tmphead);
				ra(&tmphead);
				tmphead->next++;
			}
			else
				pa(&tmphead);
		}
		else
		{
			if (tmphead->b->order == tmphead->next)
			{
				tmphead->b->flag = head->flag;
				pa(&tmphead);
				ra(&tmphead);
				tmphead->next++;
			}
			else
				rb(&tmphead);
		}
		i++;
	}
	i = 0;
	while (tmphead->a->flag != 0)
	{
		pb(&tmphead);
	}
	i = 0;
	head->flag++;
	tmphead->max = find_max_order(tmphead->b);
	tmphead->mid = (tmphead->max - tmphead->next) / 2 + tmphead->next;
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	while (tmphead->b)
	{
		_print_stacks_and_arr(*head);
		if (tmphead->b->order >= head->mid)
		{
			tmphead->b->flag = head->flag;
			if (tmphead->b->order == tmphead->next)
			{
				pa(&tmphead);
				ra(&tmphead);
				tmphead->next++;
			}
			else
				pa(&tmphead);
		}
		else
		{
			if (tmphead->b->order == tmphead->next)
			{
				tmphead->b->flag = head->flag;
				pa(&tmphead);
				ra(&tmphead);
				tmphead->next++;
			}
			else
				rb(&tmphead);
		}
		i++;
	}
	// while (tmphead->a)
	// {
	// 	/* code */
	// }
	head->flag++;
	tmphead->max = find_max_order(tmphead->a);
	tmphead->mid = (tmphead->max - tmphead->next) / 2 + tmphead->next;
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	i = 0;
	while (tmphead->a->order != 1)
	{
		if (tmphead->a->order <= head->mid)
			pb(&tmphead);
		else
			ra(&tmphead);
		i++;
	}
	while (tmphead->a->order < tmphead->next)
	{
		if (tmphead->b->order != tmphead->next)
		{
			ra(&tmphead);
			rb(&tmphead);
		}
		else
			ra(&tmphead);
	}
	_print_stacks_and_arr(*head);
	while (tmphead->b)
	{
		_print_stacks_and_arr(*head);
		if (tmphead->b->order >= head->mid)
		{
			tmphead->b->flag = head->flag;
			if (tmphead->b->order == tmphead->next)
			{
				pa(&tmphead);
				ra(&tmphead);
				tmphead->next++;
			}
			else
				pa(&tmphead);
		}
		else
		{
			if (tmphead->b->order == tmphead->next)
			{
				tmphead->b->flag = head->flag;
				pa(&tmphead);
				ra(&tmphead);
				tmphead->next++;
			}
			else
				rb(&tmphead);
		}
		i++;
	}
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	while (tmphead->a->order != 1)
	{
		ra(&tmphead);
	}
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