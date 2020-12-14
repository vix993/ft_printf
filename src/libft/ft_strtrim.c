/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:05:03 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/12 11:04:32 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static size_t	checkfront(char const *s1, char const *set)
{
	size_t		i;
	size_t		start;

	i = 0;
	start = 0;
	while (set[i] != 0)
	{
		if (s1[start] == set[i])
		{
			i = 0;
			start++;
		}
		else
			i++;
	}
	return (start);
}

static size_t	checkback(char const *s1, char const *set)
{
	size_t		i;
	size_t		end;

	i = 0;
	end = ft_strlen(s1);
	while (set[i] != 0 || s1[end] == set[i])
	{
		if (s1[end] == set[i])
		{
			i = 0;
			end--;
		}
		else
			i++;
	}
	return (end + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		start;
	size_t		end;
	char		*new;

	start = checkfront(s1, set);
	i = 0;
	if (start == ft_strlen(s1))
	{
		if (NULL == (new = (char *)ft_calloc(1, sizeof(char))))
			return (NULL);
		return (new);
	}
	else
	{
		end = checkback(s1, set);
		if (NULL == (new = (char *)ft_calloc((end - start + 1), sizeof(char))))
			return (NULL);
	}
	while (start < end)
		new[i++] = s1[start++];
	return (new);
}
