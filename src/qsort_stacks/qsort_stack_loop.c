/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_stack_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/24 03:12:57 by rcarmen          ###   ########.fr       */
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

void	set_rrx_or_rx(t_head *head)
{
	t_lst *tmp;
	int		len;
	int		i;

	tmp = head->a;
	len = get_lst_len(tmp);
	i = 0;
	while (tmp)
	{
		tmp->rrx = len - i;
		tmp->rx = i;
		i++;
		tmp = tmp->next;
	}
}

int	choise_bw_rrx_and_rx(t_head *head)
{
	t_lst	*tmp;
	int		min_rx;
	int		min_rrx;

	tmp = head->a;
	min_rx = get_lst_len(tmp) + 1;
	min_rrx = get_lst_len(tmp) + 1;
	while (tmp)
	{
		if (tmp->flag == 0 && tmp->order <= head->mid && tmp->rx < min_rx)
			min_rx = tmp->rx;
		if (tmp->flag == 0 && tmp->order <= head->mid && tmp->rrx < min_rrx)
			min_rrx = tmp->rrx;
		tmp = tmp->next;
	}
	if (min_rrx != 0 && min_rx != 0)
	{
		if (min_rx < min_rrx)
			return (1);
		return (2);
	}
	return (3);
}

void	first_phase_a_small_half_to_b(t_head *head)
{
	head->max = get_max_order(head->a);
	head->mid = (head->max - head->next) / 2 + head->next;
	while (head->a->flag == 0 && exists_smaller_or_eq_mid_a(head))
	{
		// printf("444\n");
		_print_stacks_and_arr(*head);
		if (head->a->order <= head->mid)
			pb(&head);
		else
		{
			set_rrx_or_rx(head);
			// printf("heeaklsdf\n");
			if (choise_bw_rrx_and_rx(head) == 1)
			{
				if (head->a->order == head->next)
					head->next++;
				ra(&head);
			}
			else if (choise_bw_rrx_and_rx(head) == 2 && get_last(head->a)->order != head->next - 1)
			{
				if (head->a->order == head->next)
					head->next++;
				rra(&head);
			}
			// else
				// ra(&head);
		}
	}
}

void	second_phase_b_greatest_half_to_a(t_head *head)
{
	int	zero_order;

	while (check_zero_or_greater_cycle(head) == 1 && get_last(head->a)->flag == 0)
	{
		rra(&head);
		if (head->b->order != head->next)
			rrb(&head);
	}

	// zero_order = check_zeros_in_the_end(head);
	// if (check_zero_or_greater_cycle(head) && zero_order)
	// {
	// 	while (head->a->order != zero_order)
	// 	{
	// 		// _print_stacks_and_arr(*head);
	// 		rra(&head);
	// 		if (head->b->order != head->next)
	// 			rrb(&head);
	// 	}
	// }


	head->max = get_max_order(head->b);
	head->mid = (head->max - head->next) / 2 + head->next;
	while (exists_grater_or_eq_mid_b(head))
	{
		
		// _print_stacks_and_arr(*head);
		if (head->b->order == head->next)
		{
			head->b->flag++;
			head->next++;
			pa(&head);
			ra(&head);
		}
		else if (head->b->order >= head->mid)
		{
			head->b->flag++;
			pa(&head);
		}
		else
			rb(&head);
		while (head->a->order == head->next)
		{
			head->next++;
			head->a->flag++;
			ra(&head);
		}
	}
	if (get_lst_len(head->b) == 1)
	{
		head->b->flag++;
		pa(&head);
	}
	while (head->a->order == head->next)
	{
		// _print_stacks_and_arr(*head);
		head->next++;
		ra(&head);
	}
}

void	third_phase_a_ones_to_b_and_back(t_head *head)
{
	int	save;

	while (!checking_for_sorting_a(head) && head->a->flag != 0)
	{
		save = head->a->flag;
		while (head->a->flag == save)
		{
			if (head->a->order == head->next)
			{
				head->a->flag++;
				head->next++;
				ra(&head);
				// _print_stacks_and_arr(*head);
			}
			else
			{
				// _print_stacks_and_arr(*head);
				pb(&head);
			}
		}
	}
}

void	qsort_stack_loop(t_head *head)
{
	int	save;

	head->next = 1;
	head->flag = 0;
	while (!checking_for_sorting_a(head))
	{
		// if (get_lst_len(head->a) <= 5 )
		// {
		// 	sort_five_or_less_count(head);
		// 	return ;
		// }
		first_phase_a_small_half_to_b(head);
		// _print_stacks_and_arr(*head);
		if (checking_for_sorting_a(head))
		{
			// printf("===============+END+==============\n");
			// printf("===============+FIRST+==============\n");
			// printf("===============+END+==============\n");
			return ;
		}
		second_phase_b_greatest_half_to_a(head);
		_print_stacks_and_arr(*head);
		// if (checking_for_sorting_a(head))
		// {
		// 	// printf("===============+END+==============\n");
		// 	// printf("===============+SECOND+==============\n");
		// 	// printf("===============+END+==============\n");
		// 	// _print_stacks_and_arr(*head);
		// 	return ;
		// }
		if (head->a->flag != 0)
		{
			third_phase_a_ones_to_b_and_back(head);
			while (head->b != NULL)
			{
				second_phase_b_greatest_half_to_a(head);
				// while (head->b != NULL && head->b->order == head->next)
				// {
				// 	head->next++;
				// 	pa(&head);
				// 	ra(&head);
				// }
				third_phase_a_ones_to_b_and_back(head);
				// _print_stacks_and_arr(*head);
			}
			while (head->a->order == head->next)
			{
				head->next++;
				ra(&head);
				// _print_stacks_and_arr(*head);
			}
			// _print_stacks_and_arr(*head);
			if (checking_for_sorting_a(head))
			{
				// printf("===============+END+==============\n");
				// printf("===============+SECOND+==============\n");
				// printf("===============+END+==============\n");
				return ;
			}
		}
		
		// // //===== wow

		// first_phase_a_small_half_to_b(head);
		// _print_stacks_and_arr(*head);
		// // if (checking_for_sorting_a(head))
		// // {
		// // 	// printf("===============+END+==============\n");
		// // 	// printf("===============+FIRST+==============\n");
		// // 	// printf("===============+END+==============\n");
		// // 	return ;
		// // }
		// second_phase_b_greatest_half_to_a(head);
		// _print_stacks_and_arr(*head);
		// // if (checking_for_sorting_a(head))
		// // {
		// // 	// printf("===============+END+==============\n");
		// // 	// printf("===============+SECOND+==============\n");
		// // 	// printf("===============+END+==============\n");
		// // 	// _print_stacks_and_arr(*head);
		// // 	return ;
		// // }
		// if (head->a->flag != 0)
		// {
		// 	third_phase_a_ones_to_b_and_back(head);
		// 	while (head->b != NULL)
		// 	{
		// 		second_phase_b_greatest_half_to_a(head);
		// 		// while (head->b != NULL && head->b->order == head->next)
		// 		// {
		// 		// 	head->next++;
		// 		// 	pa(&head);
		// 		// 	ra(&head);
		// 		// }
		// 		third_phase_a_ones_to_b_and_back(head);
		// 		// _print_stacks_and_arr(*head);
		// 	}
		// 	while (head->a->order == head->next)
		// 	{
		// 		head->next++;
		// 		ra(&head);
		// 		// _print_stacks_and_arr(*head);
		// 	}
		// 	// _print_stacks_and_arr(*head);
		// 	if (checking_for_sorting_a(head))
		// 	{
		// 		// printf("===============+END+==============\n");
		// 		// printf("===============+SECOND+==============\n");
		// 		// printf("===============+END+==============\n");
		// 		return ;
		// 	}
		// }

		_print_stacks_and_arr(*head);
		// exit(1);	
	}
}
