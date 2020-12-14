/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:16:48 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:32:42 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static void			leading_zero(uintmax_t num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static uintmax_t	get_num(t_top *top)
{
	uintmax_t	num;

	if (ft_strcmp(top->arg_flag, "hh") == 0)
		num = (unsigned char)(va_arg(top->args, unsigned int));
	else if (ft_strcmp(top->arg_flag, "h") == 0)
		num = (unsigned short)(va_arg(top->args, unsigned int));
	else if (ft_strcmp(top->arg_flag, "ll") == 0)
		num = (unsigned long long)(va_arg(top->args, unsigned long long int));
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

static t_top		*x_op(t_top *top, uintmax_t num, char *str, int align_left)
{
	int		num_b;
	int		num_w;

	if ((num_w = ft_strlen(str)) && top->convert[4] == '#' && num &&
			top->convert[3] == '0' && top->fwidth)
		num_w += 2;
	else if ((num_w = ft_strlen(str)) && top->convert[4] == '#' && num)
	{
		top->fwidth -= 2;
		top->len += 2;
	}
	num_b = (num_w <= top->precision && top->precision > 0)
		? top->precision : num_w;
	top->len += (num_b <= top->fwidth) ? top->fwidth : num_b;
	if (!align_left)
		display_gap(top, ' ', top->fwidth - num_b, 0);
	leading_zero(num, top->convert[4], top->spec_flag);
	display_gap(top, '0', top->precision - num_w, 0);
	ft_putstr(str);
	if (align_left)
		display_gap(top, ' ', top->fwidth - num_b, 0);
	return (top);
}

t_top				*display_x(t_top *top)
{
	char		*str;
	char		c;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(top);
	if (num == 0 && top->precision == 0)
	{
		display_gap(top, ' ', top->fwidth, 1);
		return (top);
	}
	c = 'a';
	if (top->spec_flag == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16, c)))
		exit(-1);
	if (top->convert[0] == '-')
		align_left = 1;
	if (top->convert[3] == '0' && top->precision == -1 && !top->convert[0])
		top->precision = top->fwidth;
	x_op(top, num, str, align_left);
	free(str);
	return (top);
}
