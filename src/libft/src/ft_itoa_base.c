/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:58:26 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/11 00:27:34 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_res(int i, int n, int *convert, int up_low)
{
	char				*symbols;
	char				*res;

	if (up_low == 0)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEFG";
	res = (char *)malloc(sizeof(char) * (i + 1));
	ft_bzero(res, i);
	if (n == 1)
		res[0] = '-';
	while (--i >= 0)
		res[n++] = symbols[convert[i]];
	res[n] = '\0';
	return (res);
}

static char	*zeroo(char *res)
{
	res = (char *)malloc(sizeof(char) * (2));
	*res = '0';
	*(res + 1) = 0;
	return (res);
}

char	*ft_itoa_base(unsigned long long value, int base, int up_low)
{
	unsigned long long	val_tmp;
	int					i;
	int					n;
	char				*res;
	int					convert[64];

	i = 0;
	res = 0;
	n = 0;
	if (base < 2 || base > 16)
		return ((char *)0);
	val_tmp = value;
	if (val_tmp == 0)
		return (zeroo(res));
	while (val_tmp != 0)
	{
		convert[i++] = val_tmp % base;
		val_tmp = val_tmp / base;
	}
	return (get_res(i, n, convert, up_low));
}
