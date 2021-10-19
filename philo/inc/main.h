/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:30:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/10/18 16:09:29 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_each_eat;
	pthread_mutex_t	message;
	int				full_philo;
	long			start_time;

}		t_args;

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	pthread_mutex_t left_fork;
	pthread_mutex_t *rigth_fork;
	pthread_mutex_t	food;
	int				num_of_lunch;
	long			start_eating;
	t_args			*args;
}					t_philo;

int	ft_strlen(char *s);
int ft_atoi(char *np);
int	ft_isspace(char c);
int	ft_isdigit(int c);

#endif
