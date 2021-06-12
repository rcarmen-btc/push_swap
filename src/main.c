/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/12 21:57:54 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_lst(t_lst *head)
{
	while (head)
	{
		printf("%d - %d\n", head->val, head->order);
		head = head->next;
	}
}

void	set_order(t_head head, int *arr)
{
	int		i;

	while (head.a)
	{
		i = 0;
		while (arr[i])
		{
			if (head.a->val == arr[i])
			{
				head.a->order = i + 1;
				break ;
			}
			i++;
		}
		head.a = head.a->next;
	}
}

void	init_main_struct(t_head *head)
{
	head->flag = 0;
	head->max = 0;
	head->mid = 0;
	head->next = 0;
}

t_lst	*find_el_with_order(t_lst *head, int order)
{
	while ()
	{
		/* code */
	}
	
}

void	qsort_loop(t_head *head)
{
	head->next = find_el_with_order(1);
	head->mid = 
}

int	parse(int ac, char **av, t_head **head)
{
	int		i;
	int		*arr;

	while (ac - 1 > 0)
	{
		push(&(*head)->a, ft_atoi(*(av + (ac - 1))));
		ac--;
	}
	arr = get_sort_arr((*head)->a);
	set_order(**head, arr);
	print_lst((*head)->a);
	printf("\n");
	i = 0;
	while (arr[i])
	{
		printf("%d - %d\n", arr[i], i + 1);
		i++;
	}
	init_main_struct(*head);
	printf("%d\n", (*head)->flag);
	qsort_loop();
}

int	main(int ac, char **av)
{
	t_head	*head;

	head->a = NULL;
	head->b = NULL;
	if (ac < 3)
		write(2, "Error\n", 5);
	else if (ac >= 3)
		return (parse(ac, av, &head));
	return (1);
}
