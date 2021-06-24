/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 02:37:33 by rcarmen          ###   ########.fr       */
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
	// printf("pa\n");
	// _print_stacks_and_arr(**head);
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
	// printf("pb\n");
	// _print_stacks_and_arr(**head);
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
	// printf("rra\n");
	// _print_stacks_and_arr(**head);
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
	// printf("rrb\n");
	// _print_stacks_and_arr(**head);
}
