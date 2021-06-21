/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/20 16:50:58 by rcarmen          ###   ########.fr       */
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
	// _print_stacks_and_arr(*head);
	ra(&head);
	// _print_stacks_and_arr(*head);
}

int	main(int ac, char **av)
{
	t_head	*head;

	head = (t_head *)malloc(sizeof(t_head));
	head->a = NULL;
	head->b = NULL;
	head->commands = NULL;
	if (ac < 3)
		return (write(2, "Error\n", 6) - 5);
	parse(ac, av, head);
	get_sorted_arr(head);
	set_order(*head);
	init_main_struct(head);
	_print_stacks_and_arr(*head);
	printf("=====================================\n");
	printf("=====================================\n");
	// printf("=====================================\n");
	qsort_stack_loop(head);
	if (get_lst_len(head->a) > 5)
		optimize_command_count(head);
	t_lst *tmp;
	int		i;

	tmp = head->commands;
	i = 0;
	while (tmp)
	{
		if (tmp->val != 0)
		{
			if (tmp->val == 1)
				printf("pa\n");
			else if (tmp->val == 2)
				printf("pb\n");
			else if (tmp->val == 3)
				printf("rra\n");
			else if (tmp->val == 4)
				printf("rrb\n");
			else if (tmp->val == 5)
				printf("sa\n");
			else if (tmp->val == 6)
				printf("sb\n");
			else if (tmp->val == 7)
				printf("ra\n");
			else if (tmp->val == 8)
				printf("rb\n");
			else if (tmp->val == 9)
				printf("rrr\n");
			else if (tmp->val == 10)
				printf("ss\n");
			else if (tmp->val == 11)
				printf("rr\n");
			i++;
		}
		tmp = tmp->next;
	}
	printf("<%d> [%ld] -> %d\n", head->comand_counter, get_lst_len(head->commands), i);
	
	return (0);
}
