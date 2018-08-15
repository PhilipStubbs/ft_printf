
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "src/ft_printf.h"
#include <locale.h>
// #include ""


int main()
{
	char c;

	c = 'a';
	ft_printf("%p\n", c); 
 	ft_printf("%065p\n", c);
	 ft_printf("%06.5p\n", c); 
	 ft_printf("%06.*p\n",4 ,c); 
	 ft_printf("% 65p\n", c); 
	// ft_printf("");
	return (1);
}

