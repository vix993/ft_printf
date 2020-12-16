/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:07:02 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:32:12 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static uintmax_t	get_num(t_top *top)
{
	uintmax_t		num;

	if (top->spec_flag == 'U')
		num = (unsigned long)(va_arg(top->args, unsigned long int));
	else if (ft_strcmp(top->arg_flag, "hh") == 0)
		num = (unsigned char)(va_arg(top->args, unsigned int));
	else if (ft_strcmp(top->arg_flag, "h") == 0)
		num = (unsigned short)(va_arg(top->args, unsigned int));
	else if (ft_strcmp(top->arg_flag, "ll") == 0)
		num = (unsigned long long)(va_arg(top->args, unsigned long long int));
	else if (ft_strcmp(top->arg_flag, "l") == 0)
		num = (unsigned long)(va_arg(top->args, unsigned long int));
	else if (ft_strcmp(top->arg_flag, "j") == 0)
		num = (uintmax_t)(va_arg(top->args, uintmax_t));
	else if (ft_strcmp(top->arg_flag, "z") == 0)
		num = (size_t)(va_arg(top->args, size_t));
	else
		num = (unsigned int)(va_arg(top->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static int			get_tens(uintmax_t num)
{
	int			tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_top		*u_op(t_top *top, uintmax_t num, int num_width, int left)
{
	int			has_value;

	has_value = num_width;
	if (num_width <= top->precision)
		has_value = top->precision;
	top->len += (has_value <= top->fwidth) ? top->fwidth : has_value;
	if (!left)
		display_gap(top, ' ', top->fwidth - has_value, 0);
	display_gap(top, '0', top->precision - num_width, 0);
	ft_putnbrumax_fd(num, 1);
	if (left)
		display_gap(top, ' ', top->fwidth - has_value, 0);
	return (top);
}

t_top				*display_u(t_top *top)
{
	uintmax_t	num;
	int			num_width;
	int			left;

	left = 0;
	num = get_num(top);
	if (num == 0 && top->precision == 0)
	{
		display_gap(top, ' ', top->fwidth, 1);
		return (top);
	}
	num_width = get_tens(num);
	if (top->convert[0] == '-')
		left = 1;
	if (top->convert[3] == '0' && top->precision == -1 && !top->convert[0])
		top->precision = top->fwidth;
	u_op(top, num, num_width, left);
	return (top);
}
