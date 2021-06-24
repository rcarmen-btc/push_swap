/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/23 15:58:03 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sort_three_el_a(t_head *head)
{
	if (checking_for_sorting_a(head))
		return ;
	sa_off(&head);
	if (checking_for_sorting_a(head))
	{
		sa_off(&head);
		sa(&head);
		return ;
	}
	else
		sa_off(&head);
	sa_off(&head);
	rra_off(&head);
	if (checking_for_sorting_a(head))
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
	if (checking_for_sorting_a(head))
	{
		rra_off(&head);
		ra(&head);
		return ;
	}
	else
		rra_off(&head);
	sa_off(&head);
	ra_off(&head);
	if (checking_for_sorting_a(head))
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
	if (checking_for_sorting_a(head))
	{
		ra_off(&head);
		rra(&head);
		return ;
	}
	else
		ra_off(&head);
}

void	sort_three_el_b(t_head *head)
{
	if (checking_for_sorting_b(head))
		return ;
	sb_off(&head);
	if (checking_for_sorting_b(head))
	{
		sb_off(&head);
		sb(&head);
		return ;
	}
	else
		sb_off(&head);
	sb_off(&head);
	rrb_off(&head);
	if (checking_for_sorting_b(head))
	{
		rb_off(&head);
		sb_off(&head);
		sb(&head);
		rrb(&head);
		return ;
	}
	else
	{
		rb_off(&head);
		sb_off(&head);
	}
	rb_off(&head);
	if (checking_for_sorting_b(head))
	{
		rrb_off(&head);
		rb(&head);
		return ;
	}
	else
		rrb_off(&head);
	sb_off(&head);
	rb_off(&head);
	if (checking_for_sorting_b(head))
	{
		rrb_off(&head);
		sb_off(&head);
		sb(&head);
		rb(&head);
		return ;
	}
	else
	{
		rrb_off(&head);
		sb_off(&head);
	}
	rrb_off(&head);
	if (checking_for_sorting_b(head))
	{
		rb_off(&head);
		rrb(&head);
		return ;
	}
	else
		rb_off(&head);
}