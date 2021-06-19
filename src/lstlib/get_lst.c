/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/19 23:14:36 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_lst	*get_nth(t_lst *head, int n)
{
	int	i;

	i = 0;
	while (i < n && head)
	{
		head = head->next;
		i++;
	}
	return (head);
}

t_lst	*get_last(t_lst *head)
{
	t_lst *tmp;

	tmp = head;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_lst	*get_sec_to_last(t_lst *head)
{
	if (head == NULL)
		exit (1);
	if (head->next == NULL)
		return (NULL);
	while (head->next->next)
		head = head->next;
	return (head);
}

size_t	get_lst_len(t_lst *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}