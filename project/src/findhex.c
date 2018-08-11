/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:30:43 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/11 11:52:39 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hexhash(char **tmpstr, char cap, t_format *format)
{
	char	*tmpstr2;
	char	*check;
	int		len;

	len = ft_strlen(*tmpstr);
	check = ft_strdup(*tmpstr);
	if (cap == 'X')
	{
		if (format->zeropad == 1 && check[0] == '0' && check[1] == '0' && format->prec == 0)
		{
			tmpstr2 = ft_strdup(*tmpstr);
			tmpstr2[0] = '0';
			tmpstr2[1] = 'X';
		}
		else if (format->zeropad == 1 && check[0] == '0' && check[1] != '0' && format->prec == 0)
		{
			check[0] = 'X';
			tmpstr2 = ft_strjoin("0", check);
		}
		else
			tmpstr2 = ft_strjoin("0X", *tmpstr);
	}
	else
	{
		if(format->zeropad == 1 && check[0] == '0' && check[1] == '0' && format->prec == 0)
		{
			tmpstr2 = ft_strdup(*tmpstr);
			tmpstr2[0] = '0';
			tmpstr2[1] = 'x';
		}
		else if (format->zeropad == 1 && check[0] == '0' && check[1] != '0' && format->prec == 0)
		{
			check[0] = 'x';
			tmpstr2 = ft_strjoin("0", check);
		}
		else
			tmpstr2 = ft_strjoin("0x", *tmpstr);
	}
	free(*tmpstr);
	*tmpstr = ft_strdup(tmpstr2);
	free(tmpstr2);
	free(check);
	return(*tmpstr);
}

char	*lengthmodhex(t_format *format, long long num, int cap)
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
	unsigned long long	tmp;
	char	*tmpstr;

	tmp = va_arg(args, unsigned long long);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 && format->padsize == 0)
		return (0);
	if (cap == 'x')
	{
		if (format->lenmod == 1)
			tmpstr = lengthmodhex(format, (unsigned long long)tmp, 0);
		else
			tmpstr = ft_itoa_base(( unsigned int)tmp, 16, 0);
	}
	else
	{
		if (format->lenmod == 1)
			tmpstr = lengthmodhex(format, (unsigned long long)tmp, 1);
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