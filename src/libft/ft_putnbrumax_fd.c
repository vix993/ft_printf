#include "libft.h"

void	ft_putnbrumax_fd(uintmax_t n, int fd)
{
	if (n > 9)
		ft_putnbrumax_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
