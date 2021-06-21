/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/20 21:33:46 by rcarmen          ###   ########.fr       */
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

int	checking_for_sorting_a(t_head *head)
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

int	checking_for_sorting_b(t_head *head)
{
	t_lst	*tmp;
	int		len;
	int		pre;
	int		i;

	pre = head->b->order;
	tmp = head->b->next;
	len = get_lst_len(head->b);
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->order < pre)
			return (0);
		pre = tmp->order;
		tmp = tmp->next;
		i++;
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

void	sort_three_el_a(t_head *head)
{
	if (checking_for_sorting_a(head))
		return ;
	sa_off(&head);
	if (checking_for_sorting_a(head))
	{
		sa_off(&head);
		sa(&head);
		return ;
	}
	else
		sa_off(&head);
	sa_off(&head);
	rra_off(&head);
	if (checking_for_sorting_a(head))
	{
		ra_off(&head);
		sa_off(&head);
		sa(&head);
		rra(&head);
		return ;
	}
	else
	{
		ra_off(&head);
		sa_off(&head);
	}
	ra_off(&head);
	if (checking_for_sorting_a(head))
	{
		rra_off(&head);
		ra(&head);
		return ;
	}
	else
		rra_off(&head);
	sa_off(&head);
	ra_off(&head);
	if (checking_for_sorting_a(head))
	{
		rra_off(&head);
		sa_off(&head);
		sa(&head);
		ra(&head);
		return ;
	}
	else
	{
		rra_off(&head);
		sa_off(&head);
	}
	rra_off(&head);
	if (checking_for_sorting_a(head))
	{
		ra_off(&head);
		rra(&head);
		return ;
	}
	else
		ra_off(&head);
}

void	sort_three_el(t_head *head)
{
	if (checking_for_sorting_b(head))
		return ;
	sb_off(&head);
	if (checking_for_sorting_b(head))
	{
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

int	check_zero_or_greater_cycle(t_head *head)
{
	t_lst	*tmp;

	tmp = head->a;
	while (tmp)
	{
		if (tmp->order != 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	first_phase_a_small_half_to_b(t_head *head)
{
	if (get_lst_len(head->a) <= 3 )
	{
		sort_three_el_a(head);
		return ;
	}
	head->max = get_max_order(head->a);
	// if (check_zero_or_greater_cycle(head) == 0)
	// 	head->mid = head->max / 2 + head->next;
	// else
		head->mid = (head->max - head->next) / 2 + head->next;
	while (head->a->flag == 0 && exists_smaller_or_eq_mid_a(head))
	{
		printf("1");
		_print_stacks_and_arr(*head);
		if (head->a->order <= head->mid)
			pb(&head);
		else
			ra(&head);
	}
	while (head->a->flag != 0 && head->a->order == head->next)
	{
		while (head->a->order == head->next)
		{
			printf("2");
			_print_stacks_and_arr(*head);
			ra(&head);
			head->next++;
		}
		if (head->a->flag != 0)
			ra(&head);
	}
	while (head->a->order == head->next)
	{
		printf("3");
		_print_stacks_and_arr(*head);
		ra(&head);
		head->next++;
	}
}

int	check_zeros_in_the_end(t_head  *head)
{
	t_lst	*tmp;
	int		i;

	tmp = head->a;
	i = 1;
	while (tmp)
	{
		if (tmp->order != i)
			return (tmp->order);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	second_phase_b_greatest_half_to_a(t_head *head)
{
	int	zero_order;

	if (get_lst_len(head->b) > 3)
	{
		zero_order = check_zeros_in_the_end(head);
		if (check_zero_or_greater_cycle(head) && zero_order)
		{
			while (head->a->order != zero_order)
			{
				printf("4");
				_print_stacks_and_arr(*head);
				rra(&head);
				if (head->b->order != head->next)
					rrb(&head);
			}
		}
		head->max = get_max_order(head->b);
		head->mid = (head->max - head->next) / 2 + head->next;
		while (exists_grater_or_eq_mid_b(head))
		{
			printf("5");
			_print_stacks_and_arr(*head);
			// head->max = get_max_order(head->b);
			// head->mid = (head->max - head->next) / 2 + head->next;
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
					while (head->a->order == head->next)
					{
						head->next++;
						ra(&head);
					}
				}
				else
				{
					rb(&head);
					// while (head->a->order == head->next)
					// {
					// 	head->a->flag++; //b
					// 	head->next++;
					// 	ra(&head);
					// }
				}
			}
		}
		// while (head->a->order == head->next)
		// {
		// 	head->next++;
		// 	ra(&head);
		// }
	}
	else if (get_lst_len(head->b) > 1)
	{
		zero_order = check_zeros_in_the_end(head);
		if (check_zero_or_greater_cycle(head) && zero_order)
		{
			while (head->a->order != zero_order)
			{
				_print_stacks_and_arr(*head);
				rra(&head);
				if (head->b->order != head->next)
					rrb(&head);
			}
			sort_three_el_a(head);
			// while (head->a->order == head->next)
			// {
			// 	head->next++;
			// 	// _print_stacks_and_arr(*head);
			// 	ra(&head);
			// }
		}
		sort_three_el(head);
		while (head->b != NULL && head->b->order == head->next)
		{
			_print_stacks_and_arr(*head);
			head->b->flag++;
			head->next++;
			pa(&head);
			ra(&head);
		}
		// while (head->a->order == head->next)
		// {
		// 	head->next++;
		// 	// _print_stacks_and_arr(*head);
		// 	ra(&head);
		// }
	}
	else if (get_lst_len(head->b) == 1)
	{
		zero_order = check_zeros_in_the_end(head);
		if (check_zero_or_greater_cycle(head) && zero_order)
		{
			while (head->a->order != zero_order)
			{
				printf("6");
				_print_stacks_and_arr(*head);
				rra(&head);
			}
		}
		pa(&head);
		if (head->b != NULL && head->b->order == head->next)
			ra(&head);
	}
	while (head->a->order == head->next)
	{
		head->next++;
		printf("7");
		_print_stacks_and_arr(*head);
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
				printf("8");
				_print_stacks_and_arr(*head);
			}
			else
			{
				printf("9");
				_print_stacks_and_arr(*head);
				pb(&head);
			}
		}
		// while (head->a->order == head->next)
		// {
		// 	head->a->flag++;
		// 	head->next++;
		// 	ra(&head);
		// }
	}
}

void	qsort_stack_loop(t_head *head)
{
	int	save;

	head->next = 1;
	head->flag = 0;
	while (!checking_for_sorting_a(head))
	{
		if (checking_for_sorting_a(head))
		{
			// printf("===============+END+==============\n");
			printf("===============+ZERO+==============\n");
			// printf("===============+END+==============\n");
			return ;
		}
		first_phase_a_small_half_to_b(head);
		_print_stacks_and_arr(*head);
		if (checking_for_sorting_a(head))
		{
			// printf("===============+END+==============\n");
			printf("===============+FIRST+==============\n");
			// printf("===============+END+==============\n");
			return ;
		}
		second_phase_b_greatest_half_to_a(head);
		_print_stacks_and_arr(*head);
		if (checking_for_sorting_a(head))
		{
			// printf("===============+END+==============\n");
			printf("===============+SECOND+==============\n");
			// printf("===============+END+==============\n");
			// _print_stacks_and_arr(*head);
			return ;
		}
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
				_print_stacks_and_arr(*head);
			}
			while (head->a->order == head->next)
			{
				head->next++;
				ra(&head);
				_print_stacks_and_arr(*head);
			}
			_print_stacks_and_arr(*head);
			if (checking_for_sorting_a(head))
			{
				// printf("===============+END+==============\n");
				// printf("===============+SECOND+==============\n");
				// printf("===============+END+==============\n");
				return ;
			}
		}
		// exit(1);
	}
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
	int	i;
	int	len;

	len = get_lst_len(head.a);	
	while (head.a)
	{
		i = 0;
		while (i < len)
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