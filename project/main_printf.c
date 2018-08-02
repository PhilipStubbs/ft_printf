/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:27:07 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/02 13:54:13 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
// int		ft_printf()

int		main()
{
	printf("%S", "he");

}

/*
	%% = %
	%s = string;
	%S = wchar_t*
	%p = address in mem
	%d = digit
	%D = digit
	%i = also digit
	%o = unsigned int
	%O = unsigned int
	%u = unsigned int - is for unsigned decimal type
	%U = unsigned int - is for unsigned decimal type
	%x = hex
	%X = hex
	%c = char
	%C = char

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