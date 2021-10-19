/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:09:59 by rcarmen           #+#    #+#             */
/*   Updated: 2021/10/19 11:05:13 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "main.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	is_valid(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 1;
	if (ac < 5 || ac > 6)
		return (1);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] >'9')
				return (1);
			j++;
		}
		i++;
	}	
	return (0);
}

void	parse(int ac, char **av, t_args *args)
{
	int	i;
	int	num;
	int *args_arr;

	args->num_of_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->nbr_each_eat = -1;
	if (ac == 6)
		args->nbr_each_eat = ft_atoi(av[5]);
	pthread_mutex_init(&args->message, NULL);
	args->start_time = get_time();
	args->full_philo = 0;
}

int	error(t_args args, int type, char *s)
{
	if (type == 0)
	{
		write(2, s, ft_strlen(s));
		return (1);
	}
	return (0);
}

void	init_first_philo(t_philo **philo, t_args *args)
{
	(*philo)[0].id = 0;
	(*philo)[0].num_of_lunch = 0;
	pthread_mutex_init(&(*philo)[0].left_fork, NULL);
	pthread_mutex_init(&(*philo)[0].food, NULL);
	(*philo)[0].args = args;
	(*philo)[0].start_eating = get_time();
}

void	init_philo(t_philo **philo, t_args *args)
{
	int	i;

	i = 1;
	*philo = malloc(sizeof(t_philo) * args->num_of_philo);
	// init_first_philo(philo, args);
	(*philo)[0].id = 0;
	(*philo)[0].num_of_lunch = 0;
	pthread_mutex_init(&(*philo)[0].left_fork, NULL);
	pthread_mutex_init(&(*philo)[0].food, NULL);
	(*philo)[0].args = args;
	(*philo)[0].start_eating = get_time();
	while (i < args->num_of_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].num_of_lunch = 0;
		pthread_mutex_init(&(*philo)[i].left_fork, NULL);
		pthread_mutex_init(&(*philo)[i].food, NULL);
		(*philo)[i].rigth_fork = &(*philo)[i - 1].left_fork;
		(*philo)[i].args = args;
		(*philo)[i].start_eating = get_time();
		i++;
	}
	(*philo)[0].rigth_fork = &(*philo)[i].left_fork;
	if (i == 1)
		(*philo)[0].rigth_fork = &(*philo)[0].left_fork;

}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void	start_dinner(t_philo *philo)
{
	
}

void	msg(char *s, t_philo *p)
{
	pthread_mutex_lock(&p->args->message);
	printf(s, get_time() - p->args->start_time, p->id + 1);
	pthread_mutex_unlock(&p->args->message);
}

void	*life(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		ft_usleep(p->args->time_to_eat / 2);
	while (p->num_of_lunch != p->args->nbr_each_eat)
	{
		pthread_mutex_lock(&p->left_fork);
		// printf("%d - %d\n", pthread_mutex_lock(&p->left_fork), p->id + 1);
		msg("%ld %i taken left fork\n", p);
		pthread_mutex_lock(p->rigth_fork);
		// printf("%d - %d\n", pthread_mutex_lock(p->rigth_fork), p->id + 1);
		msg("%ld %i taken right fork\n", p);
		p->start_eating = get_time();
		p->num_of_lunch++;
		if (p->num_of_lunch == p->args->nbr_each_eat)
		{
			pthread_mutex_lock(&p->food);
			p->args->full_philo++;
			pthread_mutex_unlock(&p->food);
		}
		msg("%ld %i is eating\n", p);
		ft_usleep(p->args->time_to_eat);
		pthread_mutex_unlock(&p->left_fork);
		pthread_mutex_unlock(p->rigth_fork);
		if (p->num_of_lunch == p->args->nbr_each_eat)
			continue ;
		msg("%ld %i is sleeping\n", p);
		ft_usleep(p->args->time_to_sleep);
		msg("%ld %i is thinking\n", p);
	}
	return (NULL);
}

void	monitor(t_philo *p)
{
	int	i;
	
	i = 0;
	while (i < p->args->num_of_philo)
	{
		if (p->args->full_philo == p->args->num_of_philo)
		{
			pthread_mutex_lock(&p->args->message);
			printf("%ld\tall full\n", get_time() - p->args->start_time);
			return ;
		}
		ft_usleep(1);
		if (get_time() - p[i].start_eating >= p->args->time_to_die)
		{
			pthread_mutex_lock(&p->args->message);
			printf("%ld %i is died\n", get_time() - p->args->start_time, i + 1);
			return ;
		}
		i++;
		if (i == p->args->num_of_philo)
			i = 0;
	}
	
}

int	main(int ac, char **av)
{
	t_philo *philo;
	t_args	args;
	int		i;

	if (is_valid(ac, av))
		return (error(args, 0, "Invalid argument\n"));
	parse(ac, av, &args);
	init_philo(&philo, &args);
	i = 0;
	while (i < args.num_of_philo)
	{
		pthread_create(&philo[i].thread, NULL, &life, &philo[i]);
		pthread_detach(philo[i].thread);
		i++;
	}
	monitor(philo);
}
