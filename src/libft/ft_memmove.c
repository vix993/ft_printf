/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:43:41 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/06 14:33:21 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		i;

	if (dst == 0 && src == 0)
		return (0);
	dest = (char *)dst;
	source = (const char *)src;
	i = 1;
	if (source < dest)
	{
		dest += len;
		source += len;
		while (i <= len--)
			*--dest = *--source;
	}
	else
	{
		while (len--)
			*dest++ = *source++;
	}
	return (dst);
}
