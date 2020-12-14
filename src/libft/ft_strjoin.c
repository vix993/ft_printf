/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:29:29 by vnascime          #+#    #+#             */
/*   Updated: 2020/01/28 12:05:54 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	size_t		i;
	size_t		j;
	size_t		f;
	char		*new;

	i = 0;
	j = 0;
	f = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)ft_calloc(len, sizeof(char));
	if (new == 0)
		return (NULL);
	while (s1[j] != 0)
	{
		new[j] = s1[j];
		j++;
	}
	f = j;
	while (s2[i] != 0)
	{
		new[f++] = s2[i++];
	}
	return (new);
}
