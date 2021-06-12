/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/12 14:29:17 by rcarmen          ###   ########.fr       */
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

int	*get_sort_arr(t_lst *head)
{
	size_t	lstlen;
	int		*arr;
	size_t	i;

	i = 0;
	lstlen = get_lst_len(head);
	arr = (int *)ft_calloc(sizeof(int), (lstlen + 1));
	while (head)
	{
		arr[i] = head->val;
		head = head->next;
		i++;
	}
	qsort_arr(&arr, 0, i - 1);
	return (arr);
}
