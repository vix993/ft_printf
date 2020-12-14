/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:34:12 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/11 20:39:28 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;
	size_t		j;

	i = start;
	j = 0;
	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (NULL == (new = (char *)ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	if (len == 0)
		return (new);
	while (j < len && s[i] != 0)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	return (new);
}
