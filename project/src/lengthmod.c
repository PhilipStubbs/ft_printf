/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengthmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:09:39 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/09 16:37:40 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*lengthmoddig(t_format *format, long long num)
{
	char	*ret;

	if (format->hh == 1)
		ret = ft_itoa((signed char)num);
	else if (format->h == 1)
		ret = ft_itoa((short int)num);
	else if (format->l == 1)
		ret = ft_itoa((long int)num);
	else if (format->ll == 1)
		ret = ft_itoa((long long int)num);
	else if (format->j == 1)
		ret = ft_itoa((intmax_t)num);
	else if (format->z == 1)
		ret = ft_itoa((size_t)num);
	else
		ret = ft_itoa(num);
	return (ret);
}

// char	*lengthmodweird(t_format *format, long long num, int cap)
// {
// 	char	*ret;

// 	if (format->hh == 1)
// 		ret = ft_itoa((unsigned char)num);
// 	else if (format->h == 1)
// 		ret = ft_itoa((unsigned short int)num);
// 	else if (format->l == 1)
// 		ret = ft_itoa((unsigned long int)num);
// 	else if (format->ll == 1)
// 		ret = ft_itoa((unsigned long long int)num);
// 	else if (format->j == 1)
// 		ret = ft_itoa((uintmax_t)num);
// 	else if (format->z == 1)
// 		ret = ft_itoa((size_t)num);
// 	else
// 		ret = ft_itoa(num);
// 	return (ret);
// }