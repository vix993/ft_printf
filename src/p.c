/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:02:16 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:39:26 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static uintmax_t	get_num(t_top *top)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(top->args, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_top		*print_u(t_top *top, char *str, int align_left)
{
	int		has_value;
	int		num_width;

	num_width = ft_strlen(str) + 2;
	has_value = num_width;
	top->len += (has_value <= top->fwidth) ? top->fwidth : has_value;
	if (!align_left)
		display_gap(top, ' ', top->fwidth - has_value, 0);
	write(1, "0x", 2);
	display_gap(top, '0', (top->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (align_left)
		display_gap(top, ' ', top->fwidth - has_value, 0);
	free(str);
	return (top);
}

t_top				*display_p(t_top *top)
{
	char		*str;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(top);
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	if (top->convert[0] == '-')
		align_left = 1;
	if (top->precision == 0 && num == 0)
		*str = '\0';
	if (top->convert[3] == '0' && top->precision == -1 && !top->convert[0])
	{
		top->precision = top->fwidth - 2;
		top->fwidth = 0;
	}
	print_u(top, str, align_left);
	return (top);
}
