/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/18 22:47:47 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sa(t_head **head)
{
	t_lst	*tmp;

	(*head)->comand_counter++;
	tmp = (*head)->a->next;
	printf("sa\n");
	(*head)->a->next = tmp->next;
	tmp->next = (*head)->a;
	(*head)->a = tmp;
}

void	sb(t_head **head)
{
	t_lst	*tmp;

	(*head)->comand_counter++;
	tmp = (*head)->b->next;
	printf("sb\n");
	(*head)->b->next = tmp->next;
	tmp->next = (*head)->b;
	(*head)->b = tmp;
}

void	ra(t_head **head)
{
	t_lst	*tmp;

	(*head)->comand_counter++;
	tmp = (*head)->a->next;
	printf("ra\n");
	get_last((*head)->a)->next = (*head)->a;
	(*head)->a->next = NULL;
	(*head)->a = tmp;
}

void	rb(t_head **head)
{
	t_lst	*tmp;

	(*head)->comand_counter++;
	tmp = (*head)->b->next;
	printf("rb\n");
	get_last((*head)->b)->next = (*head)->b;
	(*head)->b->next = NULL;
	(*head)->b = tmp;
}
