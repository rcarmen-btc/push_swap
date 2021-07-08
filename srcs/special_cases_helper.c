/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/25 17:46:08 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	sort_three_el_one(t_head *head)
{	
	if (checking_for_sorting_a_without_arr(head))
		return (69);
	sa_off(&head);
	if (checking_for_sorting_a_without_arr(head))
	{
		sa_off(&head);
		sa(&head);
		return (69);
	}
	else
		sa_off(&head);
	sa_off(&head);
	rra_off(&head);
	return (0);
}

int	sort_three_el_two(t_head *head)
{
	if (checking_for_sorting_a_without_arr(head))
	{
		ra_off(&head);
		sa_off(&head);
		sa(&head);
		rra(&head);
		return (69);
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
		return (69);
	}
	else
		rra_off(&head);
	sa_off(&head);
	ra_off(&head);
	return (0);
}

int	sort_three_el_three(t_head *head)
{
	if (checking_for_sorting_a_without_arr(head))
	{
		rra_off(&head);
		sa_off(&head);
		sa(&head);
		ra(&head);
		return (69);
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
		return (69);
	}
	else
		ra_off(&head);
	return (0);
}

void	sort_three_el_a(t_head *head)
{
	if (sort_three_el_one(head) == 69)
		return ;
	if (sort_three_el_two(head) == 69)
		return ;
	if (sort_three_el_three(head) == 69)
		return ;
}

int	find_min(t_lst *head)
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
