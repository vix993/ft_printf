/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:54:05 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:33:20 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static void			print_format(t_top *top, int count)
{
	char			*format;

	format = NULL;
	if (!count || count < 0)
		return ;
	if (!(format = ft_strndup((top->f_copy + (top->i - count)), count)))
		exit(1);
	ft_putstr(format);
	free(format);
	format = NULL;
}

int					parse(t_top *top)
{
	int				count;

	count = 0;
	if (ft_strcmp(top->f_copy, "%") == 0)
		return (0);
	while (top->f_copy[top->i] != '\0')
	{
		if (top->f_copy[top->i] == '%')
		{
			print_format(top, count);
			reinit(top);
			treat(top);
			count = 0;
		}
		else
		{
			count++;
			top->len++;
		}
		if (top->f_copy[top->i] != '\0')
			top->i++;
	}
	print_format(top, count);
	return (top->len);
}
