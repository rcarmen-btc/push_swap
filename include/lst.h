/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/11 11:56:09 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct s_lst
{
	int				val;
	int				order;
	int				flag;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct s_dlst
{
	size_t	size;
	t_lst	*head;
	t_lst	*tail;
}				t_dlst;

void	push(t_lst **head, int val);
int		pop(t_lst **head);
t_lst	*get_nth(t_lst *head, int n);
t_lst	*get_last(t_lst *head);
void	push_back(t_lst **head, int val);
t_lst	*get_sec_to_last(t_lst *head);
size_t	get_lst_len(t_lst *head);

#endif