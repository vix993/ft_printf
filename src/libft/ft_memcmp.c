/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:44:13 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/06 14:41:28 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	i = 0;
	res = 0;
	while (i < n)
	{
		c1 = ((unsigned char *)s1)[i];
		c2 = ((unsigned char *)s2)[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (res);
}
