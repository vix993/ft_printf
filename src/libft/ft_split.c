/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:06:06 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/11 17:11:45 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

static size_t	countstr(char const *s, char c)
{
	size_t		i;
	int			count;

	if (!s || !c)
		return (0);
	count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (i == 0)
		{
			if (s[i] != c)
				count++;
			i++;
		}
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		l;
	char		**new;

	if (NULL == (new = (char **)ft_calloc(countstr(s, c) + 1, sizeof(char **))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < countstr(s, c) && countstr(s, c) != 0)
	{
		if (s[j] != c && s[j] != 0)
		{
			l = j;
			while (s[j] != c && s[j] != 0)
				j++;
			if (NULL == (new[i] = (char *)ft_calloc(j - l + 1, sizeof(char))))
				return (NULL);
			ft_memcpy(new[i], s + l, (j - l));
			i++;
		}
		else
			j++;
	}
	return (new);
}
