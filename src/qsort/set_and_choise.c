/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_choise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 07:09:43 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

void	choise_helper(t_head *head, t_lst **tmp, int *min_rx, int *min_rrx)
{
	if (exists_smaller_or_eq_mid_a(head))
	{
		if ((*tmp)->order >= head->mid && (*tmp)->rx < *min_rx)
			*min_rx = (*tmp)->rx;
		if ((*tmp)->order >= head->mid && (*tmp)->rrx < *min_rrx)
			*min_rrx = (*tmp)->rrx;
	}
	else
	{
		if ((*tmp)->order == head->next && (*tmp)->rx < *min_rx)
			*min_rx = (*tmp)->rx;
		if ((*tmp)->order == head->next && (*tmp)->rrx < *min_rrx)
			*min_rrx = (*tmp)->rrx;
	}
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
		choise_helper(head, &tmp, &min_rx, &min_rrx);
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
