/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime </var/mail/vnascime>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:52:39 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 16:52:50 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void		display_gap(t_top *top, char c, int len, int update_len)
{
	char		*str;

	if (len > 0)
	{
		if (update_len)
			top->len += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}
