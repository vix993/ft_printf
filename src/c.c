/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:46:43 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:40:21 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <ctype.h>

t_top		*display_c(t_top *top)
{
	wint_t		c;

	if (ft_strcmp(top->arg_flag, "l") == 0)
		c = (unsigned long)va_arg(top->args, unsigned long);
	else if (top->spec_flag == 'C')
		c = (wchar_t)va_arg(top->args, wint_t);
	else
		c = (char)va_arg(top->args, int);
	c = (wint_t)c;
	if (top->convert[3] == '0' && top->convert[0] != '-')
		display_gap(top, '0', top->fwidth - 1, 1);
	else if (top->convert[0] != '-')
		display_gap(top, ' ', top->fwidth - 1, 1);
	display_wchar(c, top);
	if (top->convert[0] == '-')
		display_gap(top, ' ', top->fwidth - 1, 1);
	return (top);
}
