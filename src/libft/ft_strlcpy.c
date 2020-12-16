/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:39:36 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/06 14:29:30 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = dst;
	source = src;
	i = dstsize;
	if (i != 0 && --i != 0)
	{
		while (i != 0)
		{
			if ((*dst++ = *src++) == 0)
				break ;
			i--;
		}
	}
	if (i == 0)
	{
		if (dstsize != 0)
			*dst = 0;
	}
	return (ft_strlen(source));
}
