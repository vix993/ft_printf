/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime </var/mail/vnascime>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:47:22 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 16:52:24 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static intmax_t			get_num(t_top *top)
{
	intmax_t			num;

	if (top->spec_flag == 'D')
		num = (long)(va_arg(top->args, long int));
	else if (ft_strcmp(top->arg_flag, "hh") == 0)
		num = (signed char)(va_arg(top->args, int));
	else if (ft_strcmp(top->arg_flag, "h") == 0)
		num = (short)(va_arg(top->args, int));
	else if (ft_strcmp(top->arg_flag, "ll") == 0)
		num = (long long)(va_arg(top->args, long long int));
	else if (ft_strcmp(top->arg_flag, "l") == 0)
		num = (long)(va_arg(top->args, long int));
	else if (ft_strcmp(top->arg_flag, "j") == 0)
		num = (intmax_t)(va_arg(top->args, intmax_t));
	else if (ft_strcmp(top->arg_flag, "z") == 0)
		num = (size_t)(va_arg(top->args, size_t));
	else
		num = (int)(va_arg(top->args, int));
	num = (intmax_t)num;
	return (num);
}

static int			get_tens(intmax_t num)
{
	int				tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char			get_neg(t_top *top, int is_neg)
{
	char			*tmp;

	tmp = top->convert;
	if (is_neg)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[2] == ' ')
		return (' ');
	return ('\0');
}

static t_top		*d_op(t_top *top, intmax_t num, int num_width,
		int align_left)
{
	int				has_value;
	char			neg;
	int				is_neg;

	is_neg = (num < 0) ? 1 : 0;
	num *= (is_neg && num != (-9223372036854775807 - 1)) ? -1 : 1;
	neg = get_neg(top, is_neg);
	has_value = num_width;
	if (num_width <= top->precision && top->precision >= 0)
		has_value = top->precision;
	if (neg)
		has_value++;
	top->len += (has_value <= top->fwidth) ? top->fwidth : has_value;
	if (!align_left)
		display_gap(top, ' ', top->fwidth - has_value, 0);
	if (neg)
		write(1, &neg, 1);
	display_gap(top, '0', top->precision - num_width, 0);
	if (num != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(num, 1);
	else if ((top->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (align_left)
		display_gap(top, ' ', top->fwidth - has_value, 0);
	return (top);
}

t_top			*display_d(t_top *top)
{
	intmax_t		num;
	int				num_width;
	int				align_left;

	num = get_num(top);
	if (num == 0 && top->precision == 0)
	{
		if (top->convert[1] == '+')
			display_wchar('+', top);
		if (top->convert[2] == ' ')
			display_wchar(' ', top);
		display_gap(top, ' ', top->fwidth, 1);
		return (top);
	}
	num_width = get_tens(num);
	align_left = (top->convert[0] == '-') ? 1 : 0;
	if (top->convert[3] == '0' && top->precision == -1 && !top->convert[0])
	{
		top->precision = top->fwidth;
		if (num < 0 || top->convert[2] || top->convert[1] || top->convert[0])
			top->precision--;
	}
	d_op(top, num, num_width, align_left);
	return (top);
}
