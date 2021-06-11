/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/11 03:51:16 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_lst(t_lst *head)
{
	while (head)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
}

int	parse(int ac, char **av, t_head **head)
{
	int		i;

	(*head)->a = NULL;
	(*head)->b = NULL;
	i = ac - 1;
	while (i > 0)
	{
		push(&(*head)->a, ft_atoi(*(av + i)));
		i--;
	}
}

int	main(int ac, char **av)
{
	t_head	*head;

	if (ac < 3)
		write(2, "Error\n", 5);
	else if (ac >= 3)
		return (parse(ac, av, &head));
	return (1);
}