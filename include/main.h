/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/12 19:54:25 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define EXIT_SUCCESS 0;
# define EXIT_EXIT_FAILURE 1;
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include "lst.h"
# include <stdio.h>

typedef struct s_head
{
	t_lst		*a;
	t_lst		*b;
	int			next;
	int			mid;
	int			flag;
	int			max;
}				t_head;

/*
 * 
 */
void	sa(t_head **head);
void	print_lst(t_lst *head);
void	ra(t_head **head);
void	rra(t_head **head);
void	rrb(t_head **head);
void	pa(t_head **head);
void	pb(t_head **head);

/*
 * 
 */
int		*get_sort_arr(t_lst *head);
void	*qsort_arr(int **arr, int first, int last);
void	*qsort_iter(int **arr, int middle, int *left, int *right);

#endif
