/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:06:51 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/06 18:30:53 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	i = 0;
	if (NULL == (new = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	while (s[i] != 0)
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	return (new);
}
