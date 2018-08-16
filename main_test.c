
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "includes/ft_printf.h"
#include <locale.h>
// #include ""


int main()
{
	setlocale(LC_ALL, "");
	int	i;
	i = 0;

	// while (i < 10000)
		// printf("%C",i++);
	ft_printf("Hello %0*.*s", 5,2, "FRIENDS!");
	// ft_printf("{BLU}%S", L"我是一只猫。");
	return (1);
}

