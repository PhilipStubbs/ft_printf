/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:30:43 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 18:49:29 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*lengthmodhex(t_format *format, uintmax_t num, int cap)
{
	char	*ret;

	if (format->hh == 1)
		ret = ft_itoa_base((unsigned char)num, 16, cap);
	else if (format->h == 1)
		ret = ft_itoa_base((unsigned short int)num, 16, cap);
	else if (format->l == 1)
		ret = ft_itoa_base((unsigned long int)num, 16, cap);
	else if (format->ll == 1)
		ret = ft_itoa_base((unsigned long long int)num, 16, cap);
	else if (format->j == 1)
		ret = ft_itoa_base((uintmax_t)num, 16, cap);
	else if (format->z == 1)
		ret = ft_itoa_base((size_t)num, 16, cap);
	else
		ret = ft_itoa_base(num, 16, cap);
	return (ret);
}

int		findhex(t_printf *node, va_list args, char cap, t_format *format)
{
	uintmax_t	tmp;
	char	*tmpstr;

	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, uintmax_t);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 && format->padsize == 0)
		return (0);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 && format->padsize != 0)
		tmpstr = ft_strdup(" ");
	else if (cap == 'x')
	{
		if (format->lenmod == 1)
			tmpstr = lengthmodhex(format, tmp, 0);
		else
			tmpstr = ft_itoa_base((unsigned int)tmp, 16, 0);
	}
	else
	{
		if (format->lenmod == 1)
			tmpstr = lengthmodhex(format, tmp, 1);
		else
			tmpstr = ft_itoa_base((unsigned int)tmp, 16, 1);
	}
	tmp = ft_strlen(tmpstr);
	if (tmp == 1 && ft_strcmp("0", tmpstr) == 0)
		format->hash = 0;
	if (format->prec == 1)
		tmpstr = precision(format, &tmpstr);
	if ((format->hash == 1 && format->zeropad == 0 && format->spacpad == 1) || (format->prec == 1 && format->hash == 1 && format->zeropad == 0 && format->spacpad == 0) || (format->prec == 0 && format->hash == 1 && format->zeropad == 0 && format->spacpad == 0))
	{
		tmpstr = hexhash(&tmpstr, cap, format);
	}
	if ((format->spacpad == 1 || format->zeropad == 1))
		tmpstr = createpadding(&tmpstr, format);
	if (format->hash == 1 && format->zeropad == 1 && format->prec == 0)
	{
		tmpstr = hexhash(&tmpstr, cap, format);
	}
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}