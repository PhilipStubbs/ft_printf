
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "src/ft_printf.h"
// #include ""

int main()
{
	ft_printf("%-#6o\n", 2500);
	printf("%-#6o\n", 2500);


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


// 	if (chr <= 0x7F)
// 		chr_len = 1;
// 	else if (chr <= 0x7FF)
// 		chr_len = 2;
// 	else if (chr <= 0xFFFF)
// 		chr_len = 3;
// 	else if (chr <= 0x10FFFF)
// 		chr_len = 4;
// 	else
// 		chr_len = 0;