#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static void		leading_zero(uintmax_t num, char hash)
{
	if (hash == '#' && num)
		write(1, "0", 1);
}

static uintmax_t	get_num(t_top *top)
{
	uintmax_t	num;

	if (top->spec_flag == 'O')
		num = (unsigned long)(va_arg(top->args, unsigned long int));
	else if (ft_strcmp(top->arg_flag, "hh") == 0)
		num = (unsigned char)(va_arg(top->args, unsigned int));
	else if (ft_strcmp(top->arg_flag, "h") == 0)
		num = (unsigned short)(va_arg(top->args, unsigned int));
	else if (ft_strcmp(top->arg_flag, "ll") == 0)
		num = (unsigned long long)(va_arg(top->args, unsigned long long int));
	else if (ft_strcmp(top->arg_flag, "l") == 0)
		num = (unsigned long)(va_arg(top->args, unsigned long int));
	else if (ft_strcmp(top->arg_flag, "j") == 0)
		num = (uintmax_t)(va_arg(top->args, uintmax_t));
	else if (ft_strcmp(top->arg_flag, "z") == 0)
		num = (size_t)(va_arg(top->args, size_t));
	else
		num = (unsigned int)(va_arg(top->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static t_top		*print_u(t_top *top, uintmax_t num, char *str, int align_left)
{
	int		has_value;
	int		num_width;

	num_width = ft_strlen(str);
	if (top->convert[4] == '#' && num)
		num_width++;
	has_value = num_width;
	if (num_width <= top->precision && top->precision > 0)
		has_value = top->precision;
	top->len += (has_value <= top->fwidth) ? top->fwidth : has_value;
	if (!align_left)
		display_gap(top, ' ', top->fwidth - has_value, 0);
	leading_zero(num, top->convert[4]);
	display_gap(top, '0', top->precision - num_width, 0);
	ft_putstr(str);
	free(str);
	if (align_left)
		display_gap(top, ' ', top->fwidth - has_value, 0);
	return (top);

}

t_top			*display_o(t_top *top)
{
	char		*str;
	uintmax_t	num;
	int		align_left;

	align_left = 0;
	num = get_num(top);
	if (num == 0 && top->precision == 0 && top->convert[4] != '#')
	{
		display_gap(top, ' ', top->fwidth, 1);
		return (top);
	}
	if (!(str = ft_itoa_base(num, 8, 'a')))
		exit(-1);
	if (top->convert[0] == '-')
		align_left = 1;
	if (top->convert[3] == '0' && top->precision == -1 && !top->convert[0])
		top->precision = top->fwidth;
	print_u(top, num, str, align_left);
	return (top);
}
