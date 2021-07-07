/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:23:50 by rcarmen           #+#    #+#             */
/*   Updated: 2021/06/11 00:32:53 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*d_ptr;
	size_t			i;

	d_ptr = (unsigned char *)dest;
	i = 0;
	while (i < n)
		d_ptr[i++] = (unsigned char)c;
	return (dest);
}
