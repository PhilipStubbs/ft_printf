/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_main_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:27:07 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/04 12:57:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
// int		ft_printf()


// static char	*dynamicstring(char **ori, char *add)
// {
// 	char	*tmp;
// 	char	*ret;

// 	tmp = ft_strdup(*ori);
// 	free(*ori);
// 	ret = ft_strjoin(tmp, add);
// 	free(tmp);
// 	return (ret);
// }

// char	*stringfind(va_list args)
// {
// 	char	*tmp;
// 	char	*ret;

// 	tmp = va_arg(args, char*);
// 	ret = ft_strdup("Hello firends");
// 	ret = dynamicstring(&ret, tmp);
// 	// free(tmp);
// 	return (ret);
// }

char	charfind(va_list args)
{
	char	ret;

	ret = va_arg(args, int);
	return (ret);
}


int	intfind(va_list args)
{
	int	ret;

	ret = va_arg(args, int);
	return (ret);
}


int		test(char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	// char	*ret;
	
	i = 0;
	count = 0;

	while(str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}

	i = 0;
	va_start(args, str);
	// while (i < count)
	// {
		// tmp = va_arg(args, char*);
		// ret = stringfind(args);
		// ft_putendl(ret);
		// free(ret);
		// ft_putendl(stringfind(args));
		// ft_putendl(stringfind(args));
		// ft_putchar(charfind(args));
		// ft_putchar('\n');
		ft_putnbr(intfind(args));
		// ft_putchar('\n');
		i++;
	// }

	va_end(args);
	return (1);
}


int		main()
{
	// printf("%zs", "he");
	test("%",  5);
	return (1);
}

/*
	// %% = %
	// %s = string;
	%S = wchar_t*
	// %p = address in mem
	// %d = digit
	// %D = digit
	// %i = also digit
	// %o = unsigned int
	// %O = unsigned int
	%u = unsigned int - is for unsigned decimal type
	%U = unsigned int - is for unsigned decimal type
	// %x = hex
	// %X = hex
	// %c = char
	// %C = char

	%e = double
	%E = double
	%f = double
	%g = double
	%G = double
	%a = double
	%A = double
	%F = double
	%n = int pointer

	.* The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.'

	integer value or * that specifies minimum field width. The result is padded with space characters (by default), if required, on the left when right-justified, 
	or on the right if left-justified. In the case when * is used, the width is specified by an additional argument of type int. If the value of the argument is negative,
	 it results with the - flag specified and positive field width. (Note: This is the minimum width: The value is never truncated.)

	. followed by integer number or *, or neither that specifies precision of the conversion. In the case when * is used, the precision is specified by an additional argument of type int.
 	If the value of this argument is negative, it is ignored. If neither a number nor * is used, the precision is taken as zero. See the table below for exact effects of precision.

*/