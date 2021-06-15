/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/16 00:30:01 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_max_order(t_lst *head)
{
	int	max;

	max = head->order;
	head = head->next;
	while (head)
	{
		if (head->order > max)
			max = head->order;
		head = head->next;
	}
	return (max);
}

// void	first_phase(t_head *head)
// {
// 	int		i;

// 	head->max = find_max_order(head->a);
// 	head->mid = (head->max - head->next) / 2 + head->next;
// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
// 	i = 0;
// 	while (i < head->max)
// 	{
// 		if (head->a->order <= head->mid)
// 			pb(&head);
// 		else
// 			ra(&head);
// 		i++;
// 	}
// 	_print_stacks_and_arr(*head);
// 	head->max = find_max_order(head->b);
// 	head->mid = (head->max - head->next) / 2 + head->next;
// 	head->flag++;
// 	i = 0;
// 	while (head->b)
// 	{
// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
// 		_print_stacks_and_arr(*head);
// 		if (head->b->order >= head->mid)
// 		{
// 			head->b->flag = head->flag;
// 			if (head->b->order == head->next)
// 			{
// 				head->b->flag = head->flag;
// 				pa(&head);
// 				ra(&head);
// 				head->next++;
// 			}
// 			else
// 				pa(&head);
// 		}
// 		else
// 		{
// 			if (head->b->order == head->next)
// 			{
// 				head->b->flag = head->flag;
// 				pa(&head);
// 				ra(&head);
// 				head->next++;
// 			}
// 			else
// 				rb(&head);
// 		}
// 		i++;
// 	}
// 	while (head->a->order == head->next)
// 	{
// 		ra(&head);
// 		head->next++;
// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
// 		printf("-----dkfjalkd-------\n");
// 		_print_stacks_and_arr(*head);
// 	}
// }

// void	second_phase(t_head *head)
// {
// 	while (head->a->flag != 0)
// 	{
// 		pb(&head);
// 	}
// 	head->flag++;
// 	head->max = find_max_order(head->b);
// 	head->mid = (head->max - head->next) / 2 + head->next;
// 	while (head->b && head->next <= head->max)
// 	{
// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
// 		printf("-----12456-------\n");
// 		_print_stacks_and_arr(*head);
// 		if (head->b->order >= head->mid)
// 		{
// 			head->b->flag = head->flag;
// 			if (head->b->order == head->next)
// 			{
// 				head->b->flag = head->flag;
// 				pa(&head);
// 				ra(&head);
// 				head->next++;
// 			}
// 			else
// 				pa(&head);
// 		}
// 		else
// 		{
// 			if (head->b->order == head->next)
// 			{
// 				head->b->flag = head->flag;
// 				pa(&head);
// 				ra(&head);
// 				head->next++;
// 			}
// 			else
// 				rb(&head);
// 		}
// 	}
// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
// 	while (head->a->order == head->next && head->next <= head->max)
// 	{
// 		ra(&head);
// 		head->next++;
// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
// 		printf("-----dkfjalkd-------\n");
// 		_print_stacks_and_arr(*head);
// 	}
// }

// void	qsort_stack_loop(t_head *head)
// {
// 	int		i;

// 	head->next = 1;
// 	head->flag = 0;
// 	first_phase(head);
// 	//check stack	
// 	// second_phase(head);
// 	// second_phase(head);
// 	// first_phase(head);
// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
// 	_print_stacks_and_arr(*head);
// }

int	checking_for_sorting(t_head *head)
{
	t_lst	*tmp;
	int		i;

	tmp = head->a;
	i = 0;
	while (tmp)
	{
		if (tmp->val == head->sorted_arr[i])
		{
			tmp = tmp->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	exists_smaller_or_eq_mid_a(t_head *head)
{
	t_lst	*tmp;

	tmp = head->a;
	while (tmp)
	{
		if (tmp->order <= head->mid)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	exists_grater_or_eq_mid_b(t_head *head)
{
	t_lst	*tmp;

	tmp = head->b;
	while (tmp)
	{
		if (tmp->order >= head->mid || tmp->order == head->next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	qsort_stack_loop(t_head *head)
{
	int	save;

	if (checking_for_sorting(head))
		printf("HAHAHAHA\n");
	head->flag = 0;
	head->next = 1;
	head->max = get_max_order(head->a);
	head->mid = (head->max - head->next) / 2 + head->next;
	while (exists_smaller_or_eq_mid_a(head))
	{
		if (head->a->order <= head->mid)
			pb(&head);
		else
			ra(&head);
	}
	_print_stacks_and_arr(*head);
	head->max = get_max_order(head->b);
	head->mid = (head->max - head->next) / 2 + head->next;
	while (exists_grater_or_eq_mid_b(head))
	{
		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
		_print_stacks_and_arr(*head);
		head->max = get_max_order(head->b);
		head->mid = (head->max - head->next) / 2 + head->next;
		if (head->b->order >= head->mid)
		{
			if (head->b->order == head->next)
			{
				head->b->flag++;
				head->next++;
				pa(&head);
				ra(&head);
			}
			else
			{
				head->b->flag++;
				pa(&head);
			}
		}	
		else
		{
			if (head->b->order == head->next)
			{
				head->b->flag++;
				head->next++;
				pa(&head);
				ra(&head);
			}
			else
				rb(&head);
		}
	}
	while (head->a->flag != 0)
	{
		save = head->a->flag;
		printf("%d\n", save);
		while (head->a->flag == save)
			pb(&head);
		head->max = get_max_order(head->b);
		head->mid = (head->max - head->next) / 2 + head->next;
		while (exists_grater_or_eq_mid_b(head))
		{
			printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
			_print_stacks_and_arr(*head);
			head->max = get_max_order(head->b);
			head->mid = (head->max - head->next) / 2 + head->next;
			if (head->b->order >= head->mid)
			{
				if (head->b->order == head->next)
				{
					head->b->flag++;
					head->next++;
					pa(&head);
					ra(&head);
				}
				else
				{
					head->b->flag++;
					pa(&head);
				}
			}	
			else
			{
				if (head->b->order == head->next)
				{
					head->b->flag++;
					head->next++;
					pa(&head);
					ra(&head);
				}
				else
					rb(&head);
			}
		}
		_print_stacks_and_arr(*head);
	}
	head->max = get_max_order(head->b);
	head->mid = (head->max - head->next) / 2 + head->next;
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	_print_stacks_and_arr(*head);
}

int	find_el_with_order(t_lst *head, int order)
{
	while (head)
	{
		if (order == head->order)
			return (head->val);
		head = head->next;
	}
	return (-1);
}

void	set_order(t_head head)
{
	int		i;

	while (head.a)
	{
		i = 0;
		while (head.sorted_arr[i])
		{
			if (head.a->val == head.sorted_arr[i])
			{
				head.a->order = i + 1;
				break ;
			}
			i++;
		}
		head.a = head.a->next;
	}
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