
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "src/ft_printf.h"
// #include ""

int main()
{
	// wchar_t *ws = L"\x0c";
	// c 
	ft_printf("{%05.%}", 0);
	printf("{%05.%}", 0);
	// printf("t|%hhO, %hhO\n", 0, USHRT_MAX);
	return (1);
}

	

// int main(void)
// {
//     int i;
//     setlocale(LC_ALL, "");
//     i = 0;
//     while (i < 0xffff)
//     {
//         ft_printf("%x - %lc", i, i);
//         i++;
//     }
//     return (0);
// }


	// if (chr <= 0x7F)
	// 	chr_len = 1;
	// else if (chr <= 0x7FF)
	// 	chr_len = 2;
	// else if (chr <= 0xFFFF)
	// 	chr_len = 3;
	// else if (chr <= 0x10FFFF)
	// 	chr_len = 4;
	// else
	// 	chr_len = 0;