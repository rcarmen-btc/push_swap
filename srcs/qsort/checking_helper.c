/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/25 17:16:53 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_input(char *num, t_head *head)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (i == 0 && (num[i] != '-' && !ft_isdigit(num[i])))
		{
			write(0, "Error\n", 6);
			free_and_exit(head, 5);
		}
		else if (i == 0 && num[i] == '-' && !ft_isdigit(num[i + 1]))
		{
			write(0, "Error\n", 6);
			free_and_exit(head, 5);
		}
		else if (i != 0 && !ft_isdigit(num[i]))
		{
			write(0, "Error\n", 6);
			free_and_exit(head, 5);
		}
		i++;
	}
}

void	check_max_int(char *num, t_head *head)
{
	if (ft_atoi_long_long(num) > 2147483647
		|| ft_atoi_long_long(num) < -2147483648)
	{
		write(0, "Error\n", 6);
		free_and_exit(head, 5);
	}
}

int	checking_for_sorting_a_without_arr(t_head *head)
{
	t_lst	*tmp;
	int		i;

	tmp = head->a;
	i = tmp->order;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->order > i)
		{
			i = tmp->order;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}
