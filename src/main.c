/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/14 03:07:40 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	_print_stacks_and_arr(t_head head)
{
	int	i;

	printf("%s\n", "PRINT A");
	while (head.a)
	{
		printf("|%d - %d|\n", head.a->val, head.a->order);
		head.a = head.a->next;
	}
	printf("\n");
	printf("%s\n", "PRINT B");
	while (head.b)
	{
		printf("|%d - %d|\n", head.b->val, head.b->order);
		head.b = head.b->next;
	}
	printf("\n");
	// i = 0;
	// while (head.sorted_arr[i])
	// {
		// printf("(%d - %d)\n", head.sorted_arr[i], i + 1);
		// i++;
	// }
}

void	init_main_struct(t_head *head)
{
	head->flag = 0;
	head->max = 0;
	head->mid = 0;
	head->next = 0;
}

void	test(t_head *head)
{
	_print_stacks_and_arr(*head);
	ra(&head);
	_print_stacks_and_arr(*head);
}

int	main(int ac, char **av)
{
	t_head	head;

	head.a = NULL;
	head.b = NULL;
	if (ac < 3)
		return (write(2, "Error\n", 6) - 5);
	parse(ac, av, &head);
	get_sorted_arr(&head);
	set_order(head);
	init_main_struct(&head);
	qsort_stack_loop(&head);
	_print_stacks_and_arr(head);
	return (0);
}
