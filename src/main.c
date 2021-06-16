/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/16 16:36:08 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	_print_stacks_and_arr(t_head head)
{
	int	i;

	printf("%s\n", "PRINT A");
	printf("|%-7s|%-7s|%-7s|\n", "val:", "order:", "flag:");
	printf("-------------------------\n");
	while (head.a)
	{
		printf("|%-7d|%-7d|%-7d|\n", head.a->val, head.a->order, head.a->flag);
		head.a = head.a->next;
	}
	printf("\n");
	printf("%s\n", "PRINT B");
	printf("|%-7s|%-7s|%-7s|\n", "val:", "order:", "flag:");
	printf("-------------------------\n");
	while (head.b)
	{
		printf("|%-7d|%-7d|%-7d|\n", head.b->val, head.b->order, head.b->flag);
		head.b = head.b->next;
	}
	printf("\n");
	printf("======================================\n");
	printf("\n");
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
	t_head	*head;

	head = (t_head *)malloc(sizeof(t_head));
	head->a = NULL;
	head->b = NULL;
	if (ac < 3)
		return (write(2, "Error\n", 6) - 5);
	parse(ac, av, head);
	get_sorted_arr(head);
	set_order(*head);
	init_main_struct(head);
	_print_stacks_and_arr(*head);
	printf("=====================================\n");
	printf("=====================================\n");
	printf("=====================================\n");
	printf("=====================================\n");
	printf("=====================================\n");
	printf("=====================================\n");
	printf("=====================================\n");
	qsort_stack_loop(head);
	return (0);
}
