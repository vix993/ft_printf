/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:05:03 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:37:02 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_top		*reinit(t_top *top)
{
	top->spec_flag = '\0';
	top->convert[0] = '\0';
	top->convert[1] = '\0';
	top->convert[2] = '\0';
	top->convert[3] = '\0';
	top->convert[4] = '\0';
	top->convert[5] = '\0';
	top->arg_flag[0] = '\0';
	top->arg_flag[1] = '\0';
	top->precision = -1;
	top->fwidth = 0;
	return (top);
}
