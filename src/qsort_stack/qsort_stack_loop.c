/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_stack_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 05:09:14 by rcarmen          ###   ########.fr       */
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

void	set_rrx_or_rx_a(t_head *head)
{
	t_lst	*tmp;
	int		len;
	int		i;

	tmp = head->a;
	len = get_lst_len(tmp);
	i = 0;
	while (tmp)
	{
		tmp->rrx = len - i;
		tmp->rx = i;
		i++;
		tmp = tmp->next;
	}
}

void	set_rrx_or_rx_b(t_head *head)
{
	t_lst	*tmp;
	int		len;
	int		i;

	tmp = head->b;
	len = get_lst_len(tmp);
	i = 0;
	while (tmp)
	{
		tmp->rrx = len - i;
		tmp->rx = i;
		i++;
		tmp = tmp->next;
	}
}

int	choise_bw_rrx_and_rx_a(t_head *head)
{
	t_lst	*tmp;
	int		min_rx;
	int		min_rrx;

	tmp = head->a;
	min_rx = get_lst_len(tmp) + 1;
	min_rrx = get_lst_len(tmp) + 1;
	while (tmp)
	{
		if (tmp->flag == 0 && tmp->order <= head->mid && tmp->rx < min_rx)
			min_rx = tmp->rx;
		if (tmp->flag == 0 && tmp->order <= head->mid && tmp->rrx < min_rrx)
			min_rrx = tmp->rrx;
		tmp = tmp->next;
	}
	if (min_rrx != 0 && min_rx != 0)
	{
		if (min_rx < min_rrx)
			return (1);
		return (2);
	}
	return (3);
}

int	choise_bw_rrx_and_rx_b(t_head *head)
{
	t_lst	*tmp;
	int		min_rx;
	int		min_rrx;

	tmp = head->b;
	min_rx = get_lst_len(tmp) + 1;
	min_rrx = get_lst_len(tmp) + 1;
	while (tmp)
	{
		if (exists_smaller_or_eq_mid_a(head))
		{
			if (tmp->order >= head->mid && tmp->rx < min_rx)
				min_rx = tmp->rx;
			if (tmp->order >= head->mid && tmp->rrx < min_rrx)
				min_rrx = tmp->rrx;
		}
		else
		{
			if (tmp->order == head->next && tmp->rx < min_rx)
				min_rx = tmp->rx;
			if (tmp->order == head->next && tmp->rrx < min_rrx)
				min_rrx = tmp->rrx;
		}
		tmp = tmp->next;
	}
	if (min_rrx != 0 && min_rx != 0)
	{
		if (min_rx < min_rrx)
			return (1);
		return (2);
	}
	return (3);
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
		{
			set_rrx_or_rx_a(head);
			if (choise_bw_rrx_and_rx_a(head) == 1)
				ra(&head);
			else if (choise_bw_rrx_and_rx_a(head) == 2 && get_last(head->a)->order != head->next - 1)
				rra(&head);
		}
	}
}

void	second_phase_b_greatest_half_to_a(t_head *head)
{
	int	zero_order;

	while (check_zero_or_greater_cycle(head) == 1 && get_last(head->a)->flag == 0)
	{
		rra(&head);
		if (head->b->order != head->next)
			rrb(&head);
	}
	head->max = get_max_order(head->b);
	head->mid = (head->max - head->next) / 2 + head->next;
	while (exists_grater_or_eq_mid_b(head))
	{
		
		_print_stacks_and_arr(*head);
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
		while (head->a->order == head->next)
		{
			head->next++;
			head->a->flag++;
			ra(&head);
		}
	}
}

void	third_phase_a_ones_to_b_and_back(t_head *head)
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

void	qsort_stack_loop(t_head *head)
{
	int	save;

	head->next = 1;
	head->flag = 0;
	while (!checking_for_sorting_a(head))
	{
		// if (get_lst_len(head->a) <= 5 )
		// {
		// 	sort_five_or_less_count(head);
		// 	return ;
		// }
		first_phase_a_small_half_to_b(head);
		if (checking_for_sorting_a(head))
			return ;
		second_phase_b_greatest_half_to_a(head);
		if (checking_for_sorting_a(head))
			return ;
		if (head->a->flag != 0)
		{
			third_phase_a_ones_to_b_and_back(head);
			while (head->b != NULL)
			{
				second_phase_b_greatest_half_to_a(head);
				third_phase_a_ones_to_b_and_back(head);
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
}
