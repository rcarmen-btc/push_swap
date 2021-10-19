/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:47:54 by rcarmen           #+#    #+#             */
/*   Updated: 2021/10/18 15:54:58 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_atoi(char *np)
{
	int				sign;
	int				res;

	sign = 1;
	res = 0;
	while (ft_isspace(*np))
		np++;
	if (*np == '-' || *np == '+')
		if (*np++ == '-')
			sign = -1;
	while (ft_isdigit(*np))
		res = (res * 10) + (*np++ - '0');
	return (res * sign);
}

int	ft_isspace(char c)
{
	if ((c == '\t' || c == '\v' || c == '\n' || c == '\f'
			|| c == '\r' || c == ' '))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}