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
	return(top);
}
