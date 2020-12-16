/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:47:46 by vnascime          #+#    #+#             */
/*   Updated: 2020/01/26 19:39:50 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t		ft_strlen(const char *str)
{
	unsigned long int	i;
	unsigned long int	a;

	i = 0;
	while (str[i] != 0)
		i++;
	a = i;
	return (i);
}
