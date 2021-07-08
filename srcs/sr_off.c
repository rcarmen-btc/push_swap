/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sr_off.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/17 05:21:36 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sa_off(t_head **head)
{
	t_lst	*tmp;

	tmp = (*head)->a->next;
	(*head)->a->next = tmp->next;
	tmp->next = (*head)->a;
	(*head)->a = tmp;
}

void	sb_off(t_head **head)
{
	t_lst	*tmp;

	tmp = (*head)->b->next;
	(*head)->b->next = tmp->next;
	tmp->next = (*head)->b;
	(*head)->b = tmp;
}

void	ra_off(t_head **head)
{
	t_lst	*tmp;

	tmp = (*head)->a->next;
	get_last((*head)->a)->next = (*head)->a;
	(*head)->a->next = NULL;
	(*head)->a = tmp;
}

void	rb_off(t_head **head)
{
	t_lst	*tmp;

	tmp = (*head)->b->next;
	get_last((*head)->b)->next = (*head)->b;
	(*head)->b->next = NULL;
	(*head)->b = tmp;
}
