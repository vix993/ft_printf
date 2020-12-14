/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:01:00 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:38:58 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static t_top		*display_percent(t_top *top)
{
	if (top->convert[3] == '0' && !top->convert[0])
	{
		top->precision = top->fwidth;
		top->fwidth = 0;
	}
	if (top->convert[0] != '-' && top->convert[3] != '0')
		display_gap(top, ' ', top->fwidth - 1, 1);
	if (top->convert[3] == '0' && top->convert[0] != '-')
		display_gap(top, '0', top->precision - 1, 1);
	write(1, "%", 1);
	if (top->convert[0] == '-')
		display_gap(top, ' ', top->fwidth - 1, 1);
	top->len++;
	return (top);
}

t_top				*display_other(t_top *top)
{
	if (top->f_treat[top->i] == '%')
	{
		display_percent(top);
		return (top);
	}
	if (top->convert[3] == '0' && top->precision <= 0 && !top->convert[0])
	{
		top->precision = top->fwidth;
		top->fwidth = 0;
	}
	if (top->convert[0] != '-')
		display_gap(top, ' ', top->fwidth - 1, 1);
	if (top->convert[3] == '0' && top->convert[0] != '-')
		display_gap(top, '0', top->precision - 1, 1);
	write(1, &top->f_copy[top->i], 1);
	if (top->convert[0] == '-')
		display_gap(top, ' ', top->fwidth - 1, 1);
	top->len++;
	return (top);
}
