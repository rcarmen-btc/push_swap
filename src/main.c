/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/13 16:35:30 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	_print_stacks_and_arr(t_head head)
{
	int	i;

	printf("%s\n", "PRINT STACKS");
	while (head.a)
	{
		printf("|%d - %d|\n", head.a->val, head.a->order);
		head.a = head.a->next;
	}
	i = 0;
	while (head.sorted_arr[i])
	{
		printf("(%d - %d)\n", head.sorted_arr[i], i + 1);
		i++;
	}
}

void	init_main_struct(t_head *head)
{
	head->flag = 0;
	head->max = 0;
	head->mid = 0;
	head->next = NULL;
}

int	main(int ac, char **av)
{
	t_head	head;

	head.a = NULL;
	head.b = NULL;
	if (ac < 3)
		return (write(2, "Error\n", 6) - 5);
	parse(ac, av, &head);
	_print_stacks_and_arr(head);
	get_sorted_arr(&head);
	_print_stacks_and_arr(head);
	set_order(head);
	_print_stacks_and_arr(head);
	init_main_struct(&head);
	qsort_stack_loop(&head);
	return (0);
}
