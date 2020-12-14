/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:07:37 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/07 14:58:29 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*a;
	int			len;

	len = ft_strlen(s);
	a = 0;
	if ((char)c == 0)
		return ((char *)s + len);
	while (*s)
	{
		if (*s == (char)c)
			a = s;
		s++;
	}
	if (a != 0)
		return ((char *)a);
	return ((char *)a);
}
