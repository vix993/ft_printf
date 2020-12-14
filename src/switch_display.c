#include "ft_printf.h"
#include "libft.h"

t_top		*switch_display(t_top *top)
{
	char		*flag;

	flag = &top->spec_flag;
	if (*flag == 'd' || *flag == 'i' || *flag == 'D')
		display_d(top);
	else if (*flag == 'c' || *flag == 'C')
		display_c(top);
	else if (*flag == 's' && ft_strcmp(top->arg_flag, "l") == 0)
		display_ws(top);
	else if (*flag == 's')
		display_s(top);
	else if (*flag == 'S')
		display_ws(top);
	else if (*flag == 'u' || *flag == 'U')
		display_u(top);
	else if (*flag == 'x' || *flag == 'X')
		display_x(top);
	else if (*flag == 'o' || *flag == 'O')
		display_o(top);
	else if (*flag == 'p')
		display_p(top);
	else
		display_other(top);
	return (top);
}

