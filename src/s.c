/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:06:01 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:36:37 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_top		*display_s(t_top *top)
{
	char		*s;
	int			len;

	s = va_arg(top->args, char *);
	if (top->precision > -1 && s)
		s = ft_strndup(s, top->precision);
	else if (top->precision == -1 && s)
		s = ft_strdup(s);
	else if (top->precision > -1 && !s)
		s = ft_strndup("(null)", top->precision);
	else if (top->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	top->len += len;
	if (top->convert[3] == '0' && top->convert[0] != '-')
		display_gap(top, '0', top->fwidth - len, 1);
	else if (top->convert[0] != '-')
		display_gap(top, ' ', top->fwidth - len, 1);
	ft_putstr(s);
	if (top->convert[0] == '-')
		display_gap(top, ' ', top->fwidth - len, 1);
	free(s);
	return (top);
}
