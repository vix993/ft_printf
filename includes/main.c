#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("expected: %%\n%0133.70%\n%086.113%\n%-188.46%\n");
	ft_printf("actual: %%\n%0133.70%\n%086.113%\n%-188.46%\n");
	printf("expected: %*s\n", -3, "hello");
	ft_printf("actual: %*s\n", -3, "hello");
}
