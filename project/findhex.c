/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:30:43 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/09 10:44:41 by pstubbs          ###   ########.fr       */
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

int		findhex(t_printf *node, va_list args, char cap, t_format *format)
{
	int		tmp;
	char	*tmpstr;

	tmp = va_arg(args, int);
	if (cap == 'x')
		tmpstr = ft_itoa_base(tmp, 16, 0);
	else
		tmpstr = ft_itoa_base(tmp, 16, 1);
	tmp = ft_strlen(tmpstr);
	if (format->prec == 1)
		tmpstr = precision(format, &tmpstr);
	if ((format->hash == 1 && format->zeropad == 0 && format->spacpad == 1) || format->prec == 1)
	{
		tmpstr = hexhash(&tmpstr, cap, format);
	}
	if ((format->spacpad == 1 || format->zeropad == 1))
		tmpstr = createpadding(node, &tmpstr, format);
	if (format->hash == 1 && format->zeropad == 1 && format->prec == 0)
	{
		tmpstr = hexhash(&tmpstr, cap, format);
	}
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}