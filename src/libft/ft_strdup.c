/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:14:37 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/07 13:47:42 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*temp;
	char		*new;

	len = ft_strlen(s1);
	if (NULL == (new = malloc(len + 1 * sizeof(char))))
		return (NULL);
	temp = new;
	while (*s1)
		*temp++ = *s1++;
	*temp = 0;
	return ((char *)new);
}
