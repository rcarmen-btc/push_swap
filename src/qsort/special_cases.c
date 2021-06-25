/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 21:26:02 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	checking_for_sorting_a_without_arr(t_head *head)
{
	t_lst	*tmp;
	int		i;

	tmp = head->a;
	i = tmp->order;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->order > i)
		{
			i = tmp->order;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}

void	sort_three_el_a(t_head *head)
{
	if (checking_for_sorting_a_without_arr(head))
		return ;
	sa_off(&head);
	if (checking_for_sorting_a_without_arr(head))
	{
		sa_off(&head);
		sa(&head);
		return ;
	}
	else
		sa_off(&head);
	sa_off(&head);
	rra_off(&head);
	if (checking_for_sorting_a_without_arr(head))
	{
		ra_off(&head);
		sa_off(&head);
		sa(&head);
		rra(&head);
		return ;
	}
	else
	{
		ra_off(&head);
		sa_off(&head);
	}
	ra_off(&head);
	if (checking_for_sorting_a_without_arr(head))
	{
		rra_off(&head);
		ra(&head);
		return ;
	}
	else
		rra_off(&head);
	sa_off(&head);
	ra_off(&head);
	if (checking_for_sorting_a_without_arr(head))
	{
		rra_off(&head);
		sa_off(&head);
		sa(&head);
		ra(&head);
		return ;
	}
	else
	{
		rra_off(&head);
		sa_off(&head);
	}
	rra_off(&head);
	if (checking_for_sorting_a_without_arr(head))
	{
		ra_off(&head);
		rra(&head);
		return ;
	}
	else
		ra_off(&head);
}

int		find_min(t_lst *head)
{
	int		min;
	t_lst	*tmp;

	tmp = head;
	min = tmp->order;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->order < min)		
			min = tmp->order;
		tmp = tmp->next;
	}
	return (min);
}

int	choise_bw_rrx_and_rx_for_less(t_head *head, int min)
{
	t_lst	*tmp;
	int		min_rx;
	int		min_rrx;

	tmp = head->a;
	min_rx = get_lst_len(tmp) + 1;
	min_rrx = get_lst_len(tmp) + 1;
	while (tmp)
	{
		if (tmp->order == min && tmp->rx < min_rx)
			min_rx = tmp->rx;
		if (tmp->order == min && tmp->rrx < min_rrx)
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

void	sort_four_el_a(t_head *head)
{
	while (head->a->order != find_min(head->a))
	{
		set_rrx_or_rx_a(head);
		if (choise_bw_rrx_and_rx_for_less(head, find_min(head->a)) == 1)
			ra(&head);
		else if (choise_bw_rrx_and_rx_for_less(head, find_min(head->a)) == 2)
			rra(&head);
	}
	pb(&head);
	sort_three_el_a(head);
	pa(&head);
}

void	sort_five_el_a(t_head *head)
{
	while (head->a->order != find_min(head->a))
	{
		set_rrx_or_rx_a(head);
		if (choise_bw_rrx_and_rx_for_less(head, find_min(head->a)) == 1)
			ra(&head);
		else if (choise_bw_rrx_and_rx_for_less(head, find_min(head->a)) == 2)
			rra(&head);
	}
	pb(&head);
	sort_four_el_a(head);
	pa(&head);
}

int	sort_five_or_less_count_a(t_head *head)
{
	if (get_lst_len(head->a) <= 3)
		sort_three_el_a(head);
	else if (get_lst_len(head->a) == 4)
		sort_four_el_a(head);
	else if (get_lst_len(head->a) == 5)
		sort_five_el_a(head);
	return (0);
}