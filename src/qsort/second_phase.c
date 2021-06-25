/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_phase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/25 13:18:34 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	second_phase_helper(t_head *head)
{
	set_rrx_or_rx_b(head);
	if (choise_bw_rrx_and_rx_b(head) == 1)
	{
		if (head->b->order == head->next)
		{
			head->next++;
			head->b->flag++;
			pa(&head);
			ra(&head);
		}
		else
			rb(&head);
	}
	else if (choise_bw_rrx_and_rx_b(head) == 2)
	{
		if (head->b->order == head->next)
		{
			head->next++;
			head->b->flag++;
			pa(&head);
			ra(&head);
		}
		else
			rrb(&head);
	}
}

void	second_phase_heler_while(t_head *head)
{
	if (head->b->order == head->next)
	{
		head->b->flag++;
		head->next++;
		pa(&head);
		ra(&head);
	}
	else if (head->b->order >= head->mid)
	{
		head->b->flag++;
		pa(&head);
	}
	else
		second_phase_helper(head);
	while (head->a->order == head->next)
	{
		head->next++;
		head->a->flag++;
		ra(&head);
	}
}

void	second_phase_b_greatest_half_to_a(t_head *head)
{
	int	zero_order;

	while (check_zero_or_greater_cycle(head) == 1
		&& get_last(head->a)->flag == 0)
	{
		rra(&head);
		if (head->b->order != head->next)
			rrb(&head);
	}
	head->max = get_max_order(head->b);
	head->mid = (head->max - head->next) / 2 + head->next;
	while (exists_grater_or_eq_mid_b(head))
		second_phase_heler_while(head);
}
