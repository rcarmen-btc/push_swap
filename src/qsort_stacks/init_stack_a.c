/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/17 00:08:18 by rcarmen          ###   ########.fr       */
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
		if (tmp->order <= head->mid || tmp->order == head->next)
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

void	first_phase_a_small_half_to_b(t_head *head)
{
	head->max = get_max_order(head->a);
	head->mid = (head->max - head->next) / 2 + head->next;
	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	printf("HELLO, %d\n", head->a->order);
	_print_stacks_and_arr(*head);
	while (exists_smaller_or_eq_mid_a(head) && head->a->flag == 0)
	{
		if (head->a->order <= head->mid)
			pb(&head);
		else
			ra(&head);
	}
	while (head->a->flag != 0)	
	{
		while (head->a->order == head->next)	
		{
			ra(&head);
			// head->next++;
		}
		if (head->a->flag != 0)
			ra(&head);
		// head->next++;
	}
	while (head->a->order == head->next)	
	{
		ra(&head);
		// head->next++;
	}
}

void	second_phase_b_greatest_half_to_a(t_head *head)
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
					ra(&head);
					head->next++;
				}
			}
		}
	}
	// while (head->a->order == head->next)	
	// {
	// 	ra(&head);
	// 	head->next++;
	// }
	// while (head->a->flag != 0)	
	// {
	// 	ra(&head);
	// 	head->next++;
	// }
}

void	third_phase_a_ones_to_b_and_back(t_head *head)
{
	int	save;
	
	while (!checking_for_sorting(head) && head->a->flag != 0)
	{
		save = head->a->flag;
		while (head->a->flag == save)
		{
			printf("heeeee====\n");
			ra(&head);
			if (head->a->order == head->next)
				head->next++;
			_print_stacks_and_arr(*head);
		}
		printf("+++++heeeee====\n");
		second_phase_b_greatest_half_to_a(head);
		// head->max = get_max_order(head->b);
		// head->mid = (head->max - head->next) / 2 + head->next;
		// while (exists_grater_or_eq_mid_b(head))
		// {
		// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
		// 	_print_stacks_and_arr(*head);
		// 	head->max = get_max_order(head->b);
		// 	head->mid = (head->max - head->next) / 2 + head->next;
		// 	if (head->b->order >= head->mid)
		// 	{
		// 		if (head->b->order == head->next)
		// 		{
		// 			head->b->flag++;
		// 			head->next++;
		// 			pa(&head);
		// 			ra(&head);
		// 		}
		// 		else
		// 		{
		// 			head->b->flag++;
		// 			pa(&head);
		// 		}
		// 	}	
		// 	else
		// 	{
		// 		if (head->b->order == head->next)
		// 		{
		// 			head->b->flag++;
		// 			head->next++;
		// 			pa(&head);
		// 			ra(&head);
		// 		}
		// 		else
		// 			rb(&head);
		// 	}
		// }
		// printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
		// _print_stacks_and_arr(*head);
	}
	// _print_stacks_and_arr(*head);
}

void	qsort_stack_loop(t_head *head)
{
	while (!checking_for_sorting(head))
	{
		head->next = 1;
		head->flag = 0;
		if (checking_for_sorting(head))
		{
			printf("===============+END+==============\n");
			printf("===============+ZERO+==============\n");
			printf("===============+END+==============\n");
			return ;
		}
		first_phase_a_small_half_to_b(head);
		_print_stacks_and_arr(*head);
		if (checking_for_sorting(head))
		{
			printf("===============+END+==============\n");
			printf("===============+FIRST+==============\n");
			printf("===============+END+==============\n");
			return ;
		}
		// second_phase_b_greatest_half_to_a(head);
		// _print_stacks_and_arr(*head);
		// if (checking_for_sorting(head))
		// {
		// 	printf("===============+END+==============\n");
		// 	printf("===============+SECOND+==============\n");
		// 	printf("===============+END+==============\n");
		// 	return ;
		// }
		// third_phase_a_ones_to_b_and_back(head);
		// _print_stacks_and_arr(*head);
		// if (checking_for_sorting(head))
		// {
		// 	printf("===============+END+==============\n");
		// 	printf("===============+THIRD+==============\n");
		// 	printf("===============+END+==============\n");
		// 	return ;
		// }
		// first_phase_a_small_half_to_b(head);
		// _print_stacks_and_arr(*head);
		// if (checking_for_sorting(head))
		// {
		// 	printf("===============+END+==============\n");
		// 	printf("===============+FIRST+==============\n");
		// 	printf("===============+END+==============\n");
		// 	return ;
		// }
		// second_phase_b_greatest_half_to_a(head);
		// third_phase_a_ones_to_b_and_back(head);
		printf("Hell\n");
		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
		// third_phase_a_ones_to_b_and_back(head);
		// first_phase_a_small_half_to_b(head);
		_print_stacks_and_arr(*head);
		// first_phase_a_small_half_to_b(head);
		// rra(&head);
		// while (head->a->flag == 0)
		// {
		// 	rra(&head);
		// 	if (head->b->order != head->next)
		// 		rrb(&head);
		// }
		// ra(&head);
		// second_phase_b_greatest_half_to_a(head);
		if (checking_for_sorting(head))
		{
			printf("===============+END+==============\n");
			printf("===============+SECOND+3+==============\n");
			printf("===============+END+==============\n");
			return ;
		}
		// third_phase_a_ones_to_b_and_back();
		// _print_stacks_and_arr(*head);
		exit(1);
	}
	// if (checking_for_sorting(head))
	// {
	// 	printf("===============+END+==============\n");
	// 	printf("===============+FIRST+2+==============\n");
	// 	printf("===============+END+==============\n");
	// 	return ;
	// }
	// _print_stacks_and_arr(*head);
	// second_phase_b_greatest_half_to_a(head);
	// if (checking_for_sorting(head))
	// {
	// 	printf("===============+END+==============\n");
	// 	printf("===============+SECOND+2+==============\n");
	// 	printf("===============+END+==============\n");
	// 	return ;
	// }
	// third_phase_a_ones_to_b_and_back(head);
	// _print_stacks_and_arr(*head);
	// fourth_pre_cycle_ending(head);
	// if (checking_for_sorting(head))
	// {
	// 	printf("===============+END+==============\n");
	// 	printf("===============+FOURTH+==============\n");
	// 	printf("===============+END+==============\n");
	// 	return ;
	// }
	// head->max = get_max_order(head->b);
	// head->mid = (head->max - head->next) / 2 + head->next;
	// while (exists_grater_or_eq_mid_b(head))
	// {
	// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 	_print_stacks_and_arr(*head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->b->order >= head->mid)
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 		{
	// 			head->b->flag++;
	// 			pa(&head);
	// 		}
	// 	}	
	// 	else
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 			rb(&head);
	// 	}
	// }
	// while (head->a->flag != 0)
	// {
	// 	save = head->a->flag;
	// 	printf("%d\n", save);
	// 	while (head->a->flag == save)
	// 		pb(&head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	while (exists_grater_or_eq_mid_b(head))
	// 	{
	// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 		_print_stacks_and_arr(*head);
	// 		head->max = get_max_order(head->b);
	// 		head->mid = (head->max - head->next) / 2 + head->next;
	// 		if (head->b->order >= head->mid)
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 			{
	// 				head->b->flag++;
	// 				pa(&head);
	// 			}
	// 		}	
	// 		else
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 				rb(&head);
	// 		}
	// 	}
	// 	_print_stacks_and_arr(*head);
	// }
	// printf("ddasj;flksjd;fkajsd;lkfja;sdkfj;aksdj;faksjf;\n");
	// while (head->a->order != 1)
	// {
	// 	head->max = get_max_order(head->a);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->a->order <= head->mid)
	// 		pb(&head);
	// 	else
	// 		ra(&head);
	// }
	// rra(&head);
	// while (head->a->flag == 0)
	// {
	// 	_print_stacks_and_arr(*head);
	// 	rra(&head);
	// }
	// ra(&head);
	// _print_stacks_and_arr(*head);
	// head->max = get_max_order(head->b);
	// head->mid = (head->max - head->next) / 2 + head->next;
	// while (exists_grater_or_eq_mid_b(head))
	// {
	// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 	_print_stacks_and_arr(*head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->b->order >= head->mid)
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 		{
	// 			head->b->flag++;
	// 			pa(&head);
	// 		}
	// 	}	
	// 	else
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 			rb(&head);
	// 	}
	// }
	// while (head->a->flag != 0)
	// {
	// 	save = head->a->flag;
	// 	printf("%d\n", save);
	// 	while (head->a->flag == save)
	// 		pb(&head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	while (exists_grater_or_eq_mid_b(head))
	// 	{
	// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 		_print_stacks_and_arr(*head);
	// 		head->max = get_max_order(head->b);
	// 		head->mid = (head->max - head->next) / 2 + head->next;
	// 		if (head->b->order >= head->mid)
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 			{
	// 				head->b->flag++;
	// 				pa(&head);
	// 			}
	// 		}	
	// 		else
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 				rb(&head);
	// 		}
	// 	}
	// 	_print_stacks_and_arr(*head);
	// }
	// while (head->a->order != 1)
	// {
	// 	head->max = get_max_order(head->a);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->a->order <= head->mid)
	// 		pb(&head);
	// 	else
	// 		ra(&head);
	// }
	// //--------
	// rra(&head);
	// while (head->a->flag == 0)
	// {
	// 	_print_stacks_and_arr(*head);
	// 	rra(&head);
	// }
	// ra(&head);
	// _print_stacks_and_arr(*head);
	// head->max = get_max_order(head->b);
	// head->mid = (head->max - head->next) / 2 + head->next;
	// while (exists_grater_or_eq_mid_b(head))
	// {
	// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 	_print_stacks_and_arr(*head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->b->order >= head->mid)
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 		{
	// 			head->b->flag++;
	// 			pa(&head);
	// 		}
	// 	}	
	// 	else
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 			rb(&head);
	// 	}
	// }
	// while (head->a->flag != 0)
	// {
	// 	save = head->a->flag;
	// 	printf("%d\n", save);
	// 	while (head->a->flag == save)
	// 		pb(&head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	while (exists_grater_or_eq_mid_b(head))
	// 	{
	// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 		_print_stacks_and_arr(*head);
	// 		head->max = get_max_order(head->b);
	// 		head->mid = (head->max - head->next) / 2 + head->next;
	// 		if (head->b->order >= head->mid)
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 			{
	// 				head->b->flag++;
	// 				pa(&head);
	// 			}
	// 		}	
	// 		else
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 				rb(&head);
	// 		}
	// 	}
	// 	_print_stacks_and_arr(*head);
	// }
	// while (head->a->order != 1)
	// {
	// 	head->max = get_max_order(head->a);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->a->order <= head->mid)
	// 		pb(&head);
	// 	else
	// 		ra(&head);
	// }
	// //------
	// rra(&head);
	// while (head->a->flag == 0)
	// {
	// 	_print_stacks_and_arr(*head);
	// 	rra(&head);
	// }
	// ra(&head);
	// _print_stacks_and_arr(*head);
	// head->max = get_max_order(head->b);
	// head->mid = (head->max - head->next) / 2 + head->next;
	// while (exists_grater_or_eq_mid_b(head))
	// {
	// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 	_print_stacks_and_arr(*head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->b->order >= head->mid)
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 		{
	// 			head->b->flag++;
	// 			pa(&head);
	// 		}
	// 	}	
	// 	else
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 			rb(&head);
	// 	}
	// }
	// while (head->a->flag != 0)
	// {
	// 	save = head->a->flag;
	// 	printf("%d\n", save);
	// 	while (head->a->flag == save)
	// 		pb(&head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	while (exists_grater_or_eq_mid_b(head))
	// 	{
	// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 		_print_stacks_and_arr(*head);
	// 		head->max = get_max_order(head->b);
	// 		head->mid = (head->max - head->next) / 2 + head->next;
	// 		if (head->b->order >= head->mid)
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 			{
	// 				head->b->flag++;
	// 				pa(&head);
	// 			}
	// 		}	
	// 		else
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 				rb(&head);
	// 		}
	// 	}
	// 	_print_stacks_and_arr(*head);
	// }
	// while (head->a->order != 1)
	// {
	// 	head->max = get_max_order(head->a);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->a->order <= head->mid)
	// 		pb(&head);
	// 	else
	// 		ra(&head);
	// }
	// //---
	// rra(&head);
	// while (head->a->flag == 0)
	// {
	// 	_print_stacks_and_arr(*head);
	// 	rra(&head);
	// }
	// ra(&head);
	// _print_stacks_and_arr(*head);
	// head->max = get_max_order(head->b);
	// head->mid = (head->max - head->next) / 2 + head->next;
	// while (exists_grater_or_eq_mid_b(head))
	// {
	// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 	_print_stacks_and_arr(*head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->b->order >= head->mid)
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 		{
	// 			head->b->flag++;
	// 			pa(&head);
	// 		}
	// 	}	
	// 	else
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 			rb(&head);
	// 	}
	// }
	// while (head->a->flag != 0)
	// {
	// 	save = head->a->flag;
	// 	printf("%d\n", save);
	// 	while (head->a->flag == save)
	// 		pb(&head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	while (exists_grater_or_eq_mid_b(head))
	// 	{
	// 		printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 		_print_stacks_and_arr(*head);
	// 		head->max = get_max_order(head->b);
	// 		head->mid = (head->max - head->next) / 2 + head->next;
	// 		if (head->b->order >= head->mid)
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 			{
	// 				head->b->flag++;
	// 				pa(&head);
	// 			}
	// 		}	
	// 		else
	// 		{
	// 			if (head->b->order == head->next)
	// 			{
	// 				head->b->flag++;
	// 				head->next++;
	// 				pa(&head);
	// 				ra(&head);
	// 			}
	// 			else
	// 				rb(&head);
	// 		}
	// 	}
	// 	_print_stacks_and_arr(*head);
	// }
	// while (head->a->order != 1)
	// {
	// 	head->max = get_max_order(head->a);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->a->order <= head->mid)
	// 		pb(&head);
	// 	else
	// 		ra(&head);
	// }
	// //-----
	// // rra(&head);
	// // while (head->a->flag == 0)
	// // {
	// // 	_print_stacks_and_arr(*head);
	// // 	rra(&head);
	// // }
	// // ra(&head);
	// // _print_stacks_and_arr(*head);
	// head->max = get_max_order(head->b);
	// head->mid = (head->max - head->next) / 2 + head->next;
	// while (exists_grater_or_eq_mid_b(head))
	// {
	// 	printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// 	_print_stacks_and_arr(*head);
	// 	head->max = get_max_order(head->b);
	// 	head->mid = (head->max - head->next) / 2 + head->next;
	// 	if (head->b->order >= head->mid)
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 		{
	// 			head->b->flag++;
	// 			pa(&head);
	// 		}
	// 	}	
	// 	else
	// 	{
	// 		if (head->b->order == head->next)
	// 		{
	// 			head->b->flag++;
	// 			head->next++;
	// 			pa(&head);
	// 			ra(&head);
	// 		}
	// 		else
	// 			rb(&head);
	// 	}
	// }
	// printf("max: %d next: %d mid: %d\n", head->max, head->next, head->mid);
	// _print_stacks_and_arr(*head);
	// if (checking_for_sorting(head))
	// 	printf("HAHAHAHA\n");
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