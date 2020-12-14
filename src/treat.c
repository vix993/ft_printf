/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:06:35 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:34:40 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int		treat(t_top *top)
{
	top->i++;
	prs_convert(top);
	prs_fwidth(top);
	prs_precision(top);
	prs_args(top);
	prs_spec(top);
	switch_display(top);
	return (top->len);
}
