#include "ft_printf.h"

t_top		*prs_convert(t_top *top)
{
	size_t		i;

	i = 0;
	while (top->converter_mask[i] != '\0')
	{
		while (top->converter_mask[i] == top->f_treat[top->i])
		{
			while (top->f_treat[top->i] == '-' && top->i++)
				top->convert[0] = '-';
			while (top->f_treat[top->i] == '+' && top->i++)
				top->convert[1] = '+';
			while (top->f_treat[top->i] == ' ' && top->i++)
				top->convert[2] = ' ';
			while (top->f_treat[top->i] == '0' && top->i++)
				top->convert[3] = '0';
			while (top->f_treat[top->i] == '#' && top->i++)
				top->convert[4] = '#';
			i = 0;
		}
		i++;
	}
	return (top);
}

