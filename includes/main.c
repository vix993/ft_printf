#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int a, b;

	printf("expected: %%\n%0133.70%\n%086.113%\n%-188.46%\n");
	ft_printf("actual: %%\n%0133.70%\n%086.113%\n%-188.46%\n");
	printf("expected: %*s\n", -3, "hello");
	ft_printf("actual: %*s\n", -3, "hello");
	printf("expected: %05%\n");
	ft_printf("actual: %05%\n");
	printf("expected: %-05%\n");
	ft_printf("actual: %-05%\n");
	printf("expected: %05%\n");
	ft_printf("actual: %05%\n");
	a = printf("|this %d number|\n", -267);
	printf("|%d|\n", a);
	b = ft_printf("|this %d number|\n", -267);
	ft_printf("|%d|\n", b);
	a = printf("|%7i|\n", -14);
	printf("%d\n", a);
	b = ft_printf("|%7i|\n", -14);
	ft_printf("|%d|\n", b);
	a = printf("|%5i|\n", -2562);
	printf("%d\n", a);
	b = ft_printf("|%5i|\n", -2562);
	ft_printf("%d\n", b);
	a = printf("|%4i|\n", -2562);
	printf("%d\n", a);
	b = ft_printf("|%4i|\n", -2562);
	ft_printf("%d\n", b);
	a = printf("|%-7i|\n", -14);
	printf("%d\n", a);
	b = ft_printf("|%-7i|\n", -14);
	ft_printf("%d\n", b);
	a = printf("|%.4i|\n", -2372);
	printf("%d\n", a);
	b = ft_printf("|%.4i|\n", -2372);
	ft_printf("%d\n", b);
	a = printf("|%.3i|\n", -23646);
	printf("%d\n", a);
	b = ft_printf("|%.3i|\n", -23646);
	ft_printf("%d\n", b);
	a = printf("|%05i|\n", 43);
	printf("%d\n", a);
	b = ft_printf("|%05i|\n", 43);
	ft_printf("%d\n", b);
	a = printf("|%07i|\n", -54);
	printf("%d\n", a);
	b = ft_printf("|%07i|\n", -54);
	ft_printf("%d\n", b);
	a = printf("|%03i|\n", 0);
	printf("%d\n", a);
	b = ft_printf("|%03i|\n", 0);
	ft_printf("%d\n", b);
	a = printf("|%04i|\n", -532);
	printf("%d\n", a);
	b = ft_printf("|%04i|\n", -532);
	ft_printf("%d\n", b);
	a = printf("|%04i|\n", -4825);
	printf("%d\n", a);
	b = ft_printf("|%04i|\n", -4825);
	ft_printf("%d\n", b);
	a = printf("|%10.5i|\n", -216);
	printf("%d\n", a);
	b = ft_printf("|%10.5i|\n", -216);
	ft_printf("%d\n", b);
	a = printf("|%8.3i|\n", -8473);
	printf("%d\n", a);
	b = ft_printf("|%8.3i|\n", -8473);
	ft_printf("%d\n", b);
	a = printf("|%3.7i|\n", -2375);
	printf("%d\n", a);
	b = ft_printf("|%3.7i|\n", -2375);
	ft_printf("%d\n", b);
	a = printf("|%3.3i|\n", -8462);
	printf("%d\n", a);
	b = ft_printf("|%3.3i|\n", -8462);
	ft_printf("%d\n", b);
	a = printf("|%-10.5i|\n", -216);
	printf("%d\n", a);
	b = ft_printf("|%-10.5i|\n", -216);
	ft_printf("%d\n", b);
	a = printf("|%-8.3i|\n", -8473);
	printf("%d\n", a);
	b = ft_printf("|%-8.3i|\n", -8473);
	ft_printf("%d\n", b);
	a = printf("|%-3.7i|\n", -2375);
	printf("%d\n", a);
	b = ft_printf("|%-3.7i|\n", -2375);
	ft_printf("%d\n", b);
	a = printf("|%-3.3i|\n", -8462);
	printf("%d\n", a);
	b = ft_printf("|%-3.3i|\n", -8462);
	ft_printf("%d\n", b);
	a = printf("|%010.5i|\n", -216);
	printf("%d\n", a);
	b = ft_printf("|%010.5i|\n", -216);
	ft_printf("%d\n", b);
	a = printf("|%08.3i|\n", -8473);
	printf("%d\n", a);
	b = ft_printf("|%08.3i|\n", -8473);
	ft_printf("%d\n", b);
	a = printf("|%03.7i|\n", -2375);
	printf("%d\n", a);
	b = ft_printf("|%03.7i|\n", -2375);
	ft_printf("%d\n", b);
	a = printf("|%03.3i|\n", -8462);
	printf("%d\n", a);
	b = ft_printf("|%03.3i|\n", -8462);
	ft_printf("%d\n", b);
	//a = printf("%0-10.5i\n", -216);
	//printf("%d\n", a);
	//b = ft_printf("%0-10.5i\n", -216);
	//ft_printf("%d\n", b);
	//a = printf("%0-8.3i\n", -8473);
	//printf("%d\n", a);
	//b = ft_printf("%0-8.3i\n", -8473);
	//ft_printf("%d\n", b);
	a = printf("|%8.5x|\n", 34);
	printf("%d\n", a);
	b = ft_printf("|%8.5x|\n", 34);
	ft_printf("%d\n", b);
	a = printf("|%8.5x|\n", 0);
	printf("%d\n", a);
	b = ft_printf("|%8.5x|\n", 0);
	ft_printf("%d\n", b);
	a = printf("|%8.3x|\n", 8375);
	printf("%d\n", a);
	b = ft_printf("|%8.3x|\n", 8375);
	ft_printf("|%d|\n", b);
	a = printf("|%-8.5x|\n", 34);
	printf("%d\n", a);
	b = ft_printf("|%-8.5x|\n", 34);
	ft_printf("%d\n", b);
	a = printf("|%08.5x|\n", 34);
	printf("%d\n", a);
	b = ft_printf("|%08.5x|\n", 34);
	ft_printf("%d\n", b);
	a = printf("|%08.5x|\n", 8375);
	printf("%d\n", a);
	b = ft_printf("|%08.5x|\n", 8375);
	ft_printf("%d\n", b);
	a = printf("|%5X|\n", 33);
	printf("%d\n", a);
	b = ft_printf("|%5X|\n", 33);
	ft_printf("%d\n", b);
	a = printf("|%-7X|\n", 33);
	printf("%d\n", a);
	b = ft_printf("|%-7X|\n", 33);
	ft_printf("%d\n", b);
	a = printf("|%8.3X|\n", 8375);
	printf("%d\n", a);
	b = ft_printf("|%8.3X|\n", 8375);
	ft_printf("%d\n", b);
	a = printf("|%-8.3X|\n", 34);
	printf("%d\n", a);
	b = ft_printf("|%-8.3X|\n", 34);
	ft_printf("%d\n", b);
	a = printf("|%08.5X|\n", 34);
	printf("%d\n", a);
	b = ft_printf("|%08.5X|\n", 34);
	ft_printf("%d\n", b);
	a = printf("|%08.3X|\n", 8375);
	printf("%d\n", a);
	b = ft_printf("|%08.3X|\n", 8375);
	ft_printf("%d\n", b);
	a = printf("|%-*.*s|\n", 7, 3, "yolo");
	printf("%d\n", a);
	b = ft_printf("|%-*.*s|\n", 7, 3, "yolo");
	ft_printf("%d\n", b);
	a = printf("|%*i|\n", 4, 94827);
	printf("%d\n", a);
	b = ft_printf("|%*i|\n", 4, 94827);
	ft_printf("%d\n", b);
	a = printf("|%0*i|\n", 7, -54);
	printf("%d\n", a);
	b = ft_printf("|%0*i|\n", 7, -54);
	ft_printf("%d\n", b);
	a = printf("|%*s|\n", -32, "abc");
	printf("%d\n", a);
	b = ft_printf("|%*s|\n", -32, "abc");
	ft_printf("%d\n", b);
	a = printf("|%.*s|\n", -3, "hello");
	printf("%d\n", a);
	b = ft_printf("|%.*s|\n", -3, "hello");
	ft_printf("%d\n", b);
	a = printf("|%-*.*s|\n", -7, -3, "yolo");
	printf("%d\n", a);
	b = ft_printf("|%-*.*s|\n", -7, -3, "yolo");
	ft_printf("%d\n", b);
	a = printf("|%*i|\n", -14, 94827);
	printf("%d\n", a);
	b = ft_printf("|%*i|\n", -14, 94827);
	ft_printf("%d\n", b);
	a = printf("|%0*i|\n", -7, -54);
	printf("%d\n", a);
	b = ft_printf("|%0*i|\n", -7, -54);
	ft_printf("%d\n", b);
	a = printf("|%.*i|\n", -6, -3);
	printf("%d\n", a);
	b = ft_printf("|%.*i|\n", -6, -3);
	ft_printf("%d\n", b);
}
