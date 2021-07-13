/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_stack_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/07/09 16:38:19 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_max_order(t_lst *head)
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

void	first_phase_a_small_half_to_b(t_head *head)
{
	head->max = get_max_order(head->a);
	head->mid = (head->max - head->next) / 2 + head->next;
	while (head->a->flag == 0 && exists_smaller_or_eq_mid_a(head))
	{
		if (head->a->order <= head->mid)
			pb(&head);
		else
			ra(&head);
	}
}

void	third_phase_a_ones_to_b(t_head *head)
{
	int	save;

	while (!checking_for_sorting_a(head) && head->a->flag != 0)
	{
		save = head->a->flag;
		while (head->a->flag == save)
		{
			if (head->a->order == head->next)
			{
				head->a->flag++;
				head->next++;
				ra(&head);
			}
			else
				pb(&head);
		}
	}
}

void	pre_third_phase(t_head *head)
{
	if (head->a->flag != 0)
	{
		third_phase_a_ones_to_b(head);
		while (head->b != NULL)
		{
			second_phase_b_greatest_half_to_a(head);
			third_phase_a_ones_to_b(head);
		}
		while (head->a->order == head->next)
		{
			head->next++;
			ra(&head);
		}
		if (checking_for_sorting_a(head))
			return ;
	}
}

int	qsort_stack_loop(t_head *head)
{
	head->next = 1;
	head->flag = 0;
	if (!checking_for_sorting_a(head) && get_lst_len(head->a) <= 5)
	{
		sort_five_or_less_count_a(head);
		return (0);
	}
	while (!checking_for_sorting_a(head))
	{
		first_phase_a_small_half_to_b(head);
		if (checking_for_sorting_a(head))
			return (0);
		second_phase_b_greatest_half_to_a(head);
		if (checking_for_sorting_a(head))
			return (0);
		pre_third_phase(head);
	}
	return (0);
}
