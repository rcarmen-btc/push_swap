/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/17 14:49:27 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int get_max_order(t_lst *head)
{
	int max;

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

int checking_for_sorting_a(t_head *head)
{
	t_lst *tmp;
	int i;

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

int checking_for_sorting_b(t_head *head)
{
	t_lst *tmp;
	int len;
	int	pre;
	int	i;

	pre = head->b->order;
	tmp = head->b->next;
	len = get_lst_len(head->b);
	// exit(1);	
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->order < pre)
			return 0;
		pre = tmp->order;
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int exists_smaller_or_eq_mid_a(t_head *head)
{
	t_lst *tmp;

	tmp = head->a;
	while (tmp)
	{
		if (tmp->order <= head->mid || tmp->order == head->next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int exists_grater_or_eq_mid_b(t_head *head)
{
	t_lst *tmp;

	tmp = head->b;
	while (tmp)
	{
		if (tmp->order >= head->mid || tmp->order == head->next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sort_three_el(t_head *head)
{
	printf("++++++++++++30295023940==========\n");
	if (checking_for_sorting_b(head))
		return ;
	sb_off(&head);
	if (checking_for_sorting_b(head))
	{
		printf("++++++++++++30295023940==========\n");
		sb_off(&head);
		sb(&head);
		return ;
	}
	else
		sb_off(&head);
	sb_off(&head);
	rrb_off(&head);
	if (checking_for_sorting_b(head))
	{
		rb_off(&head);
		sb_off(&head);
		sb(&head);
		rrb(&head);
		return ;
	}
	else
	{
		rb_off(&head);
		sb_off(&head);
	}
	rb_off(&head);
	if (checking_for_sorting_b(head))
	{
		rrb_off(&head);
		rb(&head);
		return ;
	}
	else
		rrb_off(&head);
	sb_off(&head);
	rb_off(&head);
	if (checking_for_sorting_b(head))
	{
		rrb_off(&head);
		sb_off(&head);
		sb(&head);
		rb(&head);
		return ;
	}
	else
	{
		rrb_off(&head);
		sb_off(&head);
	}
	rrb_off(&head);
	if (checking_for_sorting_b(head))
	{
		rb_off(&head);
		rrb(&head);
		return ;
	}
	else
		rb_off(&head);
}	

void first_phase_a_small_half_to_b(t_head *head)
{
	head->max = get_max_order(head->a);
	head->mid = (head->max - head->next) / 2 + head->next;
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	printf("HELLO--, %d\n", head->a->order);
	_print_stacks_and_arr(*head);
	while (head->a->flag == 0 && exists_smaller_or_eq_mid_a(head))
	{
		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
		printf("--HELLO, %d\n", head->a->order);
		_print_stacks_and_arr(*head);
		if (head->a->order <= head->mid)
			pb(&head);
		else
			ra(&head);	
	}
	// while (get_last(head->a)->flag == 0)
	// {
	// 	rra(&head);
	// }
	printf("HELLO, %d\n", head->a->order);
	_print_stacks_and_arr(*head);
	// exit(1);

	while (head->a->flag != 0 && head->a->order == head->next)
	{
		// printf("HELLO, %d\n", head->a->order);
		// _print_stacks_and_arr(*head);
		while (head->a->order == head->next)
		{
			ra(&head);
			head->next++;
		}
		if (head->a->flag != 0)
			ra(&head);
		// head->next++;
	}
	while (head->a->order == head->next)
	{
		ra(&head);
		head->next++;
	}
}

void second_phase_b_greatest_half_to_a(t_head *head)
{
	if (get_lst_len(head->b) > 3)
	{
		head->max = get_max_order(head->b);
		head->mid = (head->max - head->next) / 2 + head->next;
		printf("max: %d next: %d mid: %d===============\n", head->max, head->next, head->mid);
		while (exists_grater_or_eq_mid_b(head))
		{
			printf("max: %d next: %d mid: %d++++++++++++\n", head->max, head->next, head->mid);
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
				{
					rb(&head);
					while (head->a->order == head->next)
					{
						head->b->flag++;
						head->next++;
						ra(&head);
					}
				}
			}
		}
	}
	else if (get_lst_len(head->b) > 1)
	{
		sort_three_el(head);	
		while (head->b != NULL && head->b->order == head->next)
		{
			// head->b->flag++;
			head->next++;
			pa(&head);
			ra(&head);
		}
	}
	else if (get_lst_len(head->b) == 1)
	{
		pa(&head);
		ra(&head);
	}
	while (head->a->order == head->next)
	{
		ra(&head);
		// head->a->flag++;
		head->next++;
	}
	// while (head->a->flag != 0)
	// {
	// 	ra(&head);
	// 	head->next++;
	// }
}

void third_phase_a_ones_to_b_and_back(t_head *head)
{
	int save;

	while (!checking_for_sorting_a(head) && head->a->flag != 0)
	{
		_print_stacks_and_arr(*head);
		save = head->a->flag;
		while (head->a->flag == save)
		{
			printf("heeeee====\n");
			if (head->a->order == head->next)
			{
				head->a->flag++;
				head->next++;
				ra(&head);
				_print_stacks_and_arr(*head);
			}
			else
				pb(&head);
		}
		while (head->a->order == head->next)
		{
			head->a->flag++;
			head->next++;
			ra(&head);
		}
		printf("max: %d next: %d mid: %d===============\n", head->max, head->next, head->mid);
		printf("+++++heeeee====\n");
		_print_stacks_and_arr(*head);
	}
}

void qsort_stack_loop(t_head *head)
{
	head->next = 1;
	head->flag = 0;
	while (!checking_for_sorting_a(head))
	{
		int save;

		if (checking_for_sorting_a(head))
		{
			printf("===============+END+==============\n");
			printf("===============+ZERO+==============\n");
			printf("===============+END+==============\n");
			return;
		}
		first_phase_a_small_half_to_b(head);
		_print_stacks_and_arr(*head);
		if (checking_for_sorting_a(head))
		{
			printf("===============+END+==============\n");
			printf("===============+FIRST+==============\n");
			printf("===============+END+==============\n");
			return;
		}
		second_phase_b_greatest_half_to_a(head);
		_print_stacks_and_arr(*head);
		if (checking_for_sorting_a(head))
		{
			printf("===============+END+==============\n");
			printf("===============+SECOND+==============\n");
			printf("===============+END+==============\n");
			return;
		}
		if (head->a->flag != 0)
		{
			third_phase_a_ones_to_b_and_back(head);
			while (head->b != NULL)
			{
				second_phase_b_greatest_half_to_a(head);
				while (head->b != NULL && head->b->order == head->next)
				{
					pa(&head);
					ra(&head);
				}
				// printf("ddfd\n");
				printf("max: %d next: %d mid: %d===============\n", head->max, head->next, head->mid);
				_print_stacks_and_arr(*head);
				third_phase_a_ones_to_b_and_back(head);
				// exit(1);
			}
			_print_stacks_and_arr(*head);
			if (checking_for_sorting_a(head))
			{
				printf("===============+END+==============\n");
				printf("===============+SECOND+==============\n");
				printf("===============+END+==============\n");
				return;
			}
		}
		// printf(">>>>>>>>>\n");
		// _print_stacks_and_arr(*head);
		// while (head->b != NULL && head->b->order == head->next)
		// {
		// 	pa(&head);
		// 	ra(&head);
		// }

		// =========1==========
		
		first_phase_a_small_half_to_b(head);
		_print_stacks_and_arr(*head);
		if (checking_for_sorting_a(head))
		{
			printf("===============+END+==============\n");
			printf("===============+FIRST+==============\n");
			printf("===============+END+==============\n");
			return;
		}
		// second_phase_b_greatest_half_to_a(head);
		// _print_stacks_and_arr(*head);
		// if (checking_for_sorting_a(head))
		// {
		// 	printf("===============+END+==============\n");
		// 	printf("===============+SECOND+==============\n");
		// 	printf("===============+END+==============\n");
		// 	return;
		// }
		// if (head->a->flag != 0)
		// {
		// 	third_phase_a_ones_to_b_and_back(head);
		// 	while (head->b != NULL)
		// 	{
		// 		second_phase_b_greatest_half_to_a(head);
		// 		while (head->b != NULL && head->b->order == head->next)
		// 		{
		// 			pa(&head);
		// 			ra(&head);
		// 		}
		// 		// printf("ddfd\n");
		// 		printf("max: %d next: %d mid: %d===============\n", head->max, head->next, head->mid);
		// 		_print_stacks_and_arr(*head);
		// 		third_phase_a_ones_to_b_and_back(head);
		// 		// exit(1);
		// 	}
		// 	_print_stacks_and_arr(*head);
		// 	if (checking_for_sorting_a(head))
		// 	{
		// 		printf("===============+END+==============\n");
		// 		printf("===============+SECOND+==============\n");
		// 		printf("===============+END+==============\n");
		// 		return;
		// 	}
		// }
		// _print_stacks_and_arr(*head);
		// // =========1==========
		
		// first_phase_a_small_half_to_b(head);
		// _print_stacks_and_arr(*head);
		// if (checking_for_sorting_a(head))
		// {
		// 	printf("===============+END+==============\n");
		// 	printf("===============+FIRST+==============\n");
		// 	printf("===============+END+==============\n");
		// 	return;
		// }
		// second_phase_b_greatest_half_to_a(head);
		// _print_stacks_and_arr(*head);
		// if (checking_for_sorting_a(head))
		// {
		// 	printf("===============+END+==============\n");
		// 	printf("===============+SECOND+==============\n");
		// 	printf("===============+END+==============\n");
		// 	return;
		// }
		// if (head->a->flag != 0)
		// {
		// 	third_phase_a_ones_to_b_and_back(head);
		// 	while (head->b != NULL)
		// 	{
		// 		second_phase_b_greatest_half_to_a(head);
		// 		while (head->b != NULL && head->b->order == head->next)
		// 		{
		// 			pa(&head);
		// 			ra(&head);
		// 		}
		// 		// printf("ddfd\n");
		// 		printf("max: %d next: %d mid: %d===============\n", head->max, head->next, head->mid);
		// 		_print_stacks_and_arr(*head);
		// 		third_phase_a_ones_to_b_and_back(head);
		// 		// exit(1);
		// 	}
		// 	_print_stacks_and_arr(*head);
		// 	if (checking_for_sorting_a(head))
		// 	{
		// 		printf("===============+END+==============\n");
		// 		printf("===============+SECOND+==============\n");
		// 		printf("===============+END+==============\n");
		// 		return;
		// 	}
		// }
		_print_stacks_and_arr(*head);
		exit(1);
	}
}

int find_el_with_order(t_lst *head, int order)
{
	while (head)
	{
		if (order == head->order)
			return (head->val);
		head = head->next;
	}
	return (-1);
}

void set_order(t_head head)
{
	int i;

	while (head.a)
	{
		i = 0;
		while (head.sorted_arr[i])
		{
			if (head.a->val == head.sorted_arr[i])
			{
				head.a->order = i + 1;
				break;
			}
			i++;
		}
		head.a = head.a->next;
	}
}

void parse(int ac, char **av, t_head *head)
{
	while (ac - 1 > 0)
	{
		push(&head->a, ft_atoi(*(av + (ac - 1))));
		head->a->flag = 0;
		ac--;
	}
}