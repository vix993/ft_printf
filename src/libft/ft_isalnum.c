/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:36:08 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/05 15:25:03 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (c >= 48 && c <= 122 && !((c >= 58 && c <= 64)
				|| (c >= 91 && c <= 96)))
	{
		return (1);
	}
	return (0);
}
