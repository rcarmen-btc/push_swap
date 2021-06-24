/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 03:19:35 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void _print_stacks_and_arr(t_head head)
{
	int i;

	printf("%s\n", "PRINT A");
	printf("==== next: %d ==== mid: %d ==== max: %d ====\n", head.next, head.mid, head.max);
	printf("|%-7s|%-7s|%-7s|%-7s|%-7s|\n", "rx:", "val:", "order:", "rrx:", "flag:"); //=====///////0000
	printf("-----------------------------------------\n");
	while (head.a)
	{
		printf("|%-7d|%-7d|%-7d|%-7d|%-7d|\n", head.a->rx, head.a->val, head.a->order, head.a->rrx, head.a->flag);
		head.a = head.a->next;
	}
	printf("\n");
	printf("%s\n", "PRINT B");
	printf("|%-7s|%-7s|%-7s|%-7s|%-7s|\n", "rx:", "val:", "order:", "rrx:", "flag:"); //=====///////0000
	printf("----------------------------------------\n");
	while (head.b)
	{
		printf("|%-7d|%-7d|%-7d|%-7d|%-7d|\n", head.b->rx, head.b->val, head.b->order, head.b->rrx, head.b->flag);
		// printf("|%-7d|%-7d|%-7d|\n", head.b->val, head.b->order, head.b->flag);
		head.b = head.b->next;
	}
	printf("\n");
	printf("======================================\n");
	printf("\n");
}


void	init(t_head *head)
{
	head->a = NULL;
	head->b = NULL;
	head->commands = NULL;
	head->flag = 0;
	head->max = 0;
	head->mid = 0;
	head->next = 0;
}

void	parse(int ac, char **av, t_head *head)
{
	while (ac - 1 > 0)
	{
		push(&head->a, ft_atoi(*(av + (ac - 1))));
		head->a->flag = 0;
		ac--;
	}
}

int	main(int ac, char **av)
{
	t_head	*head;
	t_lst	*tmp;
	int		i;

	if (ac < 3)
		return (write(2, "Error\n", 6) - 5);
	head = (t_head *)malloc(sizeof(t_head));
	init(head);
	parse(ac, av, head);
	get_sorted_arr(head);
	set_order(*head);
	// _print_stacks_and_arr(*head);
	// printf("=================START====================\n");
	qsort_stack_loop(head);
	if (get_lst_len(head->a) > 5)
		optimize_command_count(head);
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
	// _print_stacks_and_arr(*head);
	printf("<%d> [%ld] -> %d\n", head->comand_counter, get_lst_len(head->commands), i);
	return (0);
}
