/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:42:55 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 16:45:13 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>
# include <ctype.h>

typedef struct	s_top
{
	const char	*format;
	char		*f_copy;
	char		*f_treat;
	va_list		args;
	int			len;
	size_t		i;
	long int	precision;
	long int	fwidth;
	char		spec_flag;
	char		convert[6];
	char		arg_flag[2];
	char		*spec_mask;
	char		*converter_mask;
	char		*arg_mask;
}				t_top;

int				ft_printf(const char *format, ...);
int				treat(t_top *top);
int				parse(t_top *top);

t_top			*init(t_top *top);
t_top			*reinit(t_top *top);

t_top			*prs_convert(t_top *top);
t_top			*prs_fwidth(t_top *top);
t_top			*prs_precision(t_top *top);
t_top			*prs_args(t_top *top);
t_top			*prs_spec(t_top *top);
t_top			*switch_display(t_top *top);

t_top			*display_d(t_top *top);
t_top			*display_s(t_top *top);
t_top			*display_c(t_top *top);
t_top			*display_u(t_top *top);
t_top			*display_x(t_top *top);
t_top			*display_o(t_top *top);
t_top			*display_p(t_top *top);
t_top			*display_ws(t_top *top);
t_top			*display_other(t_top *top);
void			display_wchar(wint_t c, t_top *top);
void			display_gap(t_top *top, char c, int len, int update_len);

#endif
