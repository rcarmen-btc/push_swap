/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exists.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 02:53:22 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	exists_smaller_or_eq_mid_a(t_head *head)
{
	t_lst	*tmp;

	tmp = head->a;
	while (tmp)
	{
		if ((tmp->order <= head->mid || tmp->order == head->next) && tmp->flag == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	exists_grater_or_eq_mid_b(t_head *head)
{
	t_lst	*tmp;

	tmp = head->b;
	while (tmp)
	{
		if (tmp->order >= head->mid || tmp->order == head->next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
