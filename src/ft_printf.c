/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:20:33 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:39:45 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_top	*top;
	int		len;

	if (!(top = (t_top*)malloc(sizeof(t_top))))
		return (-1);
	top->format = format;
	top = init(top);
	if (format)
	{
		va_start(top->args, format);
		top->len = parse(top);
		va_end(top->args);
	}
	len = top->len;
	free(top);
	return (len);
}
