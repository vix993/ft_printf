/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime </var/mail/vnascime>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:04:09 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:04:26 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_top	*arg_precision(t_top *top)
{
	int	prec;

	prec = (int)va_arg(top->args, int);
	if (prec < 0)
	{
		top->precision = -1;
	}
	else
		top->precision += prec;
	return (top);
}

t_top			*prs_precision(t_top *top)
{
	while (top->f_treat[top->i] == '.')
	{
		top->i++;
		top->precision = 0;
	}
	if (top->f_treat[top->i] == '*')
	{
		arg_precision(top);
		top->i++;
	}
	else
	{
		while (top->f_treat[top->i] >= '0' && top->f_treat[top->i] <= '9')
		{
			top->precision *= 10;
			top->precision += (top->f_treat[top->i] - 48);
			top->i++;
		}
	}
	return (top);
}
