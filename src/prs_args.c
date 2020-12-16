/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:02:40 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:34:13 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_top		*prs_args(t_top *top)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (top->arg_mask[i] != '\0' && top->f_treat[top->i] != '\0')
	{
		while (top->arg_mask[i] == top->f_treat[top->i])
		{
			top->arg_flag[j] = top->f_treat[top->i];
			top->arg_flag[j + 1] = '\0';
			top->i++;
			j++;
		}
		i++;
	}
	return (top);
}
