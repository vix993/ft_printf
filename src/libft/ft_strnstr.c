/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:45:24 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/06 17:56:56 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		a;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && &haystack[i] != &haystack[len])
	{
		j = 0;
		a = i;
		while (haystack[i] == needle[j] && &haystack[i] != &haystack[len])
		{
			j++;
			i++;
			if (needle[j] == '\0')
				return ((char *)haystack + a);
		}
		i = a;
		i++;
	}
	return (NULL);
}
