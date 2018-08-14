
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "src/ft_printf.h"
// #include ""

int main()
{
	char c;
	// ft_printf("%s%d%p%%%S%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	// printf("%s%d%p|%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"a", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'B');
	// ft_printf("%.p, %.0p", 0, 0);
	// ft_printf("s: %s, p: %p, d:%d", "a string", &c, 42);
	// ft_printf("{%*.*s}", 5, 5, "42");
	// ft_printf("M|%p\n", 0);
	// printf("t|%p\n", 0);
	ft_printf("%lo, %lo", 0);
	// ft_printf("%ld", -2147483648);
	// ft_printf("%U\n", 4294967296);
	// ft_printf("%u\n", 4294967296);
	// ft_printf("%");
	// ft_printf("{%}");
	// long long num = -4294967297;
	// printf("%3d\n", 0);
	// printf("[%lld]\n",(uintmax_t )num);
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