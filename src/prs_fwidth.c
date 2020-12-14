/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_fwidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime </var/mail/vnascime>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:03:27 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:03:53 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_top		*arg_fwidth(t_top *top)
{
	int	fwidth;

	fwidth = (int)va_arg(top->args, int);
	if (fwidth < 0)
	{
		top->fwidth += -fwidth;
		top->convert[0] = '-';
	}
	else
		top->fwidth += fwidth;
	return (top);
}

t_top				*prs_fwidth(t_top *top)
{
	if (top->f_treat[top->i] == '*')
	{
		arg_fwidth(top);
		top->i++;
	}
	else
	{
		while (top->f_treat[top->i] >= '0' && top->f_treat[top->i] <= '9')
		{
			top->fwidth *= 10;
			top->fwidth += (top->f_treat[top->i] - 48);
			top->i++;
		}
	}
	return (top);
}
