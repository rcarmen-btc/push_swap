/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 22:57:30 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	pa(t_head **head)
{
	t_lst	*tmp;

	(*head)->comand_counter++;
	push_back(&(*head)->commands, 1);
	tmp = (*head)->b;
	(*head)->b = (*head)->b->next;
	tmp->next = (*head)->a;
	(*head)->a = tmp;
}

void	pb(t_head **head)
{
	t_lst	*tmp;

	(*head)->comand_counter++;
	push_back(&(*head)->commands, 2);
	tmp = (*head)->a;
	(*head)->a = (*head)->a->next;
	tmp->next = (*head)->b;
	(*head)->b = tmp;
}

void	rra(t_head **head)
{
	t_lst	*tmp;	

	(*head)->comand_counter++;
	push_back(&(*head)->commands, 3);
	tmp = get_sec_to_last((*head)->a);
	get_last((*head)->a)->next = (*head)->a;
	(*head)->a = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_head **head)
{
	t_lst	*tmp;	

	(*head)->comand_counter++;
	push_back(&(*head)->commands, 4);
	tmp = get_sec_to_last((*head)->b);
	get_last((*head)->b)->next = (*head)->b;
	(*head)->b = tmp->next;
	tmp->next = NULL;
}
