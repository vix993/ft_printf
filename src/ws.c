/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime </var/mail/vnascime>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:10:08 by vnascime          #+#    #+#             */
/*   Updated: 2020/12/14 17:10:53 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static int			char_len(wchar_t c)
{
	int	len;

	if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

static wchar_t		*wstrndup(wchar_t *s1, size_t n)
{
	wchar_t		*s2;
	size_t		i;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		exit(-1);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static wchar_t		*wstrdup(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, len));
}

static t_top		*null_op(t_top *top)
{
	wchar_t		*s;
	int			i;

	i = 0;
	s = wstrdup(L"(null)");
	if (top->precision > -1)
	{
		while (s[i] && top->precision-- > 0)
			display_wchar(s[i++], top);
	}
	else
	{
		while (s[i])
			display_wchar(s[i++], top);
	}
	free(s);
	return (top);
}

t_top				*display_ws(t_top *top)
{
	wchar_t		*s;
	int			i;
	int			j;
	int			len;

	i = 0;
	len = 0;
	if (!(s = (wchar_t *)va_arg(top->args, wchar_t *)))
		return (null_op(top));
	while (s[i] && !(j = 0))
	{
		if (top->precision > -1 && (len + char_len(s[i])) > top->precision)
			break ;
		len += char_len(s[i++]);
	}
	if (top->convert[3] == '0' && top->convert[0] != '-')
		display_gap(top, '0', top->fwidth - len, 1);
	else if (top->convert[0] != '-')
		display_gap(top, ' ', top->fwidth - len, 1);
	while (j < i)
		display_wchar(s[j++], top);
	if (top->convert[0] == '-')
		display_gap(top, ' ', top->fwidth - len, 1);
	return (top);
}
