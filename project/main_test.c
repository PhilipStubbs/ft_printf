
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "src/ft_printf.h"
#include <locale.h>
// #include ""


int main()
{
	
	wchar_t *ws = L"Α α";
	// c 
	// printf("hello %C", 0);
	// printf("t|[%#.3o]\n", 2);
	// ft_printf("m|[%#.3o]\n", 2);

	 ft_printf("m|{%05p}", 0);
	printf("t|{%05p}", 0);

	// printf("{%3*p}", 10, 0);
	// ft_printf("jk{%3*p}", 10, 0);
	// ft_printf("%.0p, %.p", 0, 0);
	// ft_printf("m|%15.4S]\n", L"Α α");
	// ft_putstr("t|            ŒM-^Q ]\n");
	// ft_printf("m|%S", L"Α α");
	return (1);
}

