/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_command_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/19 23:53:2 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	optimize_command_count(t_head *head)
{
	t_lst	*first_prt;
	t_lst	*second_prt;

	first_prt = head->commands;
	second_prt = head->commands->next;
	while (second_prt)
	{
		if (first_prt->val != 0 && ((first_prt->val == 3 && second_prt->val == 4) || (first_prt->val == 4 && second_prt->val == 3)))
		{
			first_prt->val = 9;
			second_prt->val = 0;
		}
		if (first_prt->val != 0 && ((first_prt->val == 5 && second_prt->val == 6) || (first_prt->val == 6 && second_prt->val == 5)))
		{
			first_prt->val = 10;
			second_prt->val = 0;
		}
		if (first_prt->val != 0 && ((first_prt->val == 7 && second_prt->val == 8) || (first_prt->val == 8 && second_prt->val == 7)))
		{
			first_prt->val = 11;
			second_prt->val = 0;
		}
		first_prt = first_prt->next;
		second_prt = second_prt->next;
	}
}

