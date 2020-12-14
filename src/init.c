/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:53:08 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:40:03 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_top	*init(t_top *top)
{
	top->len = 0;
	top->i = 0;
	top->spec_mask = "scSCdDiuUoOxXbp%";
	top->converter_mask = "-+ 0#";
	top->arg_mask = "lhjz";
	top->f_treat = (char *)top->format;
	top->f_copy = (char *)top->format;
	return (top);
}
