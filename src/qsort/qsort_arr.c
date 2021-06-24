/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 07:04:41 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*qsort_iter(int **arr, int middle, int *left, int *right)
{
	while ((*arr)[*left] < middle)
		(*left)++;
	while ((*arr)[*right] > middle)
		(*right)--;
}

void	*qsort_arr(int **arr, int first, int last)
{
	int	left;
	int	right;
	int	middle;
	int	tmp;

	if (first < last)
	{
		left = first;
		right = last;
		middle = (*arr)[(left + right) / 2];
		qsort_iter(arr, middle, &left, &right);
		while (left <= right)
		{
			tmp = (*arr)[left];
			(*arr)[left] = (*arr)[right];
			(*arr)[right] = tmp;
			left++;
			right--;
			qsort_iter(arr, middle, &left, &right);
		}
		qsort_arr(arr, first, right);
		qsort_arr(arr, left, last);
	}
}

void	get_sorted_arr(t_head *head)
{
	size_t	lstlen;
	size_t	i;
	t_lst	*tmp_lst_head;

	tmp_lst_head = head->a;
	lstlen = get_lst_len(tmp_lst_head);
	i = 0;
	head->sorted_arr = (int *)ft_calloc(sizeof(int), (lstlen + 1));
	while (tmp_lst_head)
	{
		head->sorted_arr[i] = tmp_lst_head->val;
		tmp_lst_head = tmp_lst_head->next;
		i++;
	}
	qsort_arr(&head->sorted_arr, 0, i - 1);
}

int	find_el_with_order(t_lst *head, int order)
{
	while (head)
	{
		if (order == head->order)
			return (head->val);
		head = head->next;
	}
	return (-1);
}

void	set_order(t_head head)
{
	int	i;
	int	len;

	len = get_lst_len(head.a);
	while (head.a)
	{
		i = 0;
		while (i < len)
		{
			if (head.a->val == head.sorted_arr[i])
			{
				head.a->order = i + 1;
				break ;
			}
			i++;
		}
		head.a = head.a->next;
	}
}
