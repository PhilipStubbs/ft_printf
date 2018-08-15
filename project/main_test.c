
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "src/ft_printf.h"
// #include ""


int main()
{
	wchar_t *ws = L"Α α";
	// c 
	// printf("hello %C", 0);
	// printf("t|[%#.3o]\n", 2);
	// ft_printf("m|[%#.3o]\n", 2);
	printf("T|{%05.S}", L"42 c est cool");
	ft_printf("M|{%05.S}", L"42 c est cool");
	return (1);
}

