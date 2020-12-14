/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:42:04 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/09 18:12:14 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		valid(char str)
{
	if (str == ' ' || str == '\n' || str == '\t'
			|| str == '\f' || str == '\r' || str == '\v')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	res = 0;
	i = 0;
	sign = 1;
	while (valid(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
