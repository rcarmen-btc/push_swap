/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/07/08 00:05:34 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define EXIT_SUCCESS 0;
# define EXIT_EXIT_FAILURE 1;
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "lst.h"
# include <stdio.h>

typedef struct s_head
{
	t_lst		*a;
	t_lst		*b;
	t_lst		*commands;
	int			*arr_commands;
	int			next;
	int			mid;
	int			flag;
	int			max;
	int			*sorted_arr;
	int			comand_counter;
}				t_head;

void		check_dup(t_lst *lsthead, t_head *head);
void		sa(t_head **head);
void		sb(t_head **head);
void		ra(t_head **head);
void		rb(t_head **head);
void		pa(t_head **head);
void		pb(t_head **head);
void		rra(t_head **head);
void		rrb(t_head **head);
void		sa_off(t_head **head);
void		sb_off(t_head **head);
void		ra_off(t_head **head);
void		rb_off(t_head **head);
void		pa_off(t_head **head);
void		pb_off(t_head **head);
void		rra_off(t_head **head);
void		rrb_off(t_head **head);
void		parse(int ac, char **av, t_head *head);
void		get_sorted_arr(t_head *head);
void		qsort_arr(int **arr, int first, int last);
void		qsort_iter(int **arr, int middle, int *left, int *right);
int			qsort_stack_loop(t_head *head);
int			find_el_with_order(t_lst *head, int order);
void		set_order(t_head head);
int			choise_bw_rrx_and_rx_a(t_head *head);
int			choise_bw_rrx_and_rx_b(t_head *head);
int			free_and_exit(t_head *head, int i);
void		del_lst(t_lst *head);
void		print_optimized_commands(t_head *head);
int			optimize_command_count(t_head *head);
int			checking_for_sorting_a(t_head *head);
int			find_el_with_order(t_lst *head, int order);
void		set_order(t_head head);
int			check_zeros_in_the_end(t_head *head);
int			check_zero_or_greater_cycle(t_head *head);
int			checking_for_sorting_b(t_head *head);
int			checking_for_sorting_a(t_head *head);
void		sort_three_el_a(t_head *head);
void		sort_three_el_b(t_head *head);
int			exists_smaller_or_eq_mid_a(t_head *head);
int			exists_grater_or_eq_mid_b(t_head *head);
void		set_rrx_or_rx_a(t_head *head);
int			checking_for_sorting_a_without_arr(t_head *head);
long long	ft_atoi_long_long(const char *np);
void		set_rrx_or_rx_b(t_head *head);
void		second_phase_b_greatest_half_to_a(t_head *head);
int			get_max_order(t_lst *head);
void		sort_three_el_a(t_head *head);
void		sort_four_el_a(t_head *head);
int			sort_three_el_one(t_head *head);
int			sort_three_el_two(t_head *head);
int			sort_three_el_three(t_head *head);
void		sort_three_el_a(t_head *head);
int			find_min(t_lst *head);
int			sort_five_or_less_count_a(t_head *head);
void		sort_five_el_a(t_head *head);
void		check_input(char *num, t_head *head);
void		check_max_int(char *num, t_head *head);

#endif
