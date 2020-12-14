#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void		display_gap(t_top *top, char c, int len, int update_len)
{
	char		*str;

	if (len > 0)
	{
		if (update_len)
			top->len += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}
