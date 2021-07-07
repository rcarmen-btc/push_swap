/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrp_off.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/17 05:21:54 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	pa_off(t_head **head)
{
	t_lst	*tmp;

	tmp = (*head)->b;
	(*head)->b = (*head)->b->next;
	tmp->next = (*head)->a;
	(*head)->a = tmp;
}

void	pb_off(t_head **head)
{
	t_lst	*tmp;

	tmp = (*head)->a;
	(*head)->a = (*head)->a->next;
	tmp->next = (*head)->b;
	(*head)->b = tmp;
}

void	rra_off(t_head **head)
{
	t_lst	*tmp;	

	tmp = get_sec_to_last((*head)->a);
	get_last((*head)->a)->next = (*head)->a;
	(*head)->a = tmp->next;
	tmp->next = NULL;
}

void	rrb_off(t_head **head)
{
	t_lst	*tmp;	

	tmp = get_sec_to_last((*head)->b);
	get_last((*head)->b)->next = (*head)->b;
	(*head)->b = tmp->next;
	tmp->next = NULL;
}
