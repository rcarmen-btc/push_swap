/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/11 03:55:57 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct s_lst
{
	int				val;
	struct s_lst	*next;
}					t_lst;

void	push(t_lst **head, int val);
int		pop(t_lst **head);
t_lst	*get_nth(t_lst *head, int n);
t_lst	*get_last(t_lst *head);
void	push_back(t_lst **head, int val);
t_lst	*get_sec_to_last(t_lst *head);

#endif