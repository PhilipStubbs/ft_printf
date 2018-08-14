
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "src/ft_printf.h"
// #include ""

// char	*wcharsize(wchar_t chr)
// {
// 	int	wchar_len;
// 	char	*ret;

// 	wchar_len = 0;
// 	if (chr <= 0x7F)
// 	{
// 		wchar_len = 1;
// 		ret = ft_strnew(wchar_len);
// 		ret[0] = (char)chr;
// 		return (ret);
// 	}
// 	else if (chr <= 0x7FF)
// 	{
// 		wchar_len = 2;
// 		ret = ft_strnew(wchar_len);
// 		ret[0] = (((chr & 0x07c0) >> 6) + 0xc0);
// 		ret[1] = (((chr & 0x003F)) + 0x80);
// 		return (ret);
// 	}
// 	else if (chr <= 0xFFFF)
// 	{
// 		wchar_len = 3;
// 		ret = ft_strnew(wchar_len);
// 		ret[0] = (((chr & 0xF000) >> 12) + 0xc0);
// 		ret[1] = (((chr & 0x0Fc0) >> 6) + 0xc0);
// 		ret[2] = (((chr & 0x003F)) + 0x80);
// 		return (ret);
// 	}
// 	else if (chr <= 0x10FFFF)
// 	{
// 		wchar_len = 4;
// 		ret[0] = (((chr & 0x1c0000) >> 18) + 0xF0);
// 		ret[1] = (((chr & 0x03F000) >> 12) + 0x80);
// 		ret[2] = (((chr & 0x0Fc0) >> 6) + 0x80);
// 		ret[3] = ((chr & 0x003F) + 0x80);
// 		return (ret);
// 	}
// 	return (ret);
// }

// int		findwchar(wchar_t	*tmp )
// {
// 	int		size;
// 	int		i;
// 	int		x;
// 	char	*ret;

// 	// tmp = va_arg(args, wchar_t);
// 	size = 0;
// 	i = 0;
// 	// while (tmp[i])
// 		// size += wcharsize(tmp[i++]);
// 	ret = ft_strnew(size);
// 	// printf("size = [%d]\n", size);
// 	x = 0;
// 	i = 0;
// 	// size = wcharsize(tmp[i]);
// 	x = ft_strlen((char*)tmp);
// 	while (tmp[i] && i <= x)
// 	{
// 		// printf(" i[%d]\n", x);
// 		// ret[x] = tmp[i];
// 		ft_putstr(wcharsize(tmp[i]));
// 		i++;
// 	}
// 	ft_putstr(ret);
// 	return (size);
// }

int main()
{
	wchar_t *ws = L"Α α";
	// c 
	ft_printf("%C", L'ي');;
	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S NICE! %C YES\n",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"", L'ي');
	// printf("[%d]\n", findwchar(ws));
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