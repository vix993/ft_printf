#include "ft_printf.h"

t_top		*prs_spec(t_top *top)
{
	size_t		i;

	i = 0;
	while (top->spec_mask[i] != '\0')
	{
		if (top->spec_mask[i] == top->f_treat[top->i])
			top->spec_flag = top->spec_mask[i];
		i++;
	}
	return (top);
}

