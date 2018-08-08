/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:31:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/08 17:57:30 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specialpaddingfordigit(t_format *format, int len, char c ,char **str)
{
		char	*amstr;
		char	*tmp;
		int		isneg;

		if (*str[0] == '-' && format->minus == 0 && format->prec == 0)
		{
			tmp = ft_strdup("-");
			*str[0] = '0';
		}
		else if (*str[0] != '-' && (format->spacpad == 1 && format->zeropad == 1) || format->prec == 1)
			tmp = ft_strdup(" ");
		else
			tmp = ft_strdup("0");
		amstr = ft_strnew(format->padsize - len - 1);
		ft_memset(amstr, c, format->padsize - len - 1);
		tmp = dynamicstring(&tmp ,amstr);
		free(amstr);
		amstr = ft_strdup(tmp);
		free(tmp);
		return (amstr);
}


char	*createpadding(t_printf *node, char **str, t_format *format)
{
	int		len;
	char	*amstr;
	char	*tmp;
	char	c;

	len = ft_strlen(*str);
	if (format->padsize <= len)
		return (*str);
	c = ' ';
	if (format->zeropad == 1 && format->minus == 0 && format->prec == 0)
		c = '0';
	if ((((format->spacpad == 1 && format->zeropad == 1) || (format->zeropad == 1 && format->spacpad == 0)) && (format->c == 'd' || format->c == 'D' || format->c == 'i')) && format->minus == 0)
		amstr = specialpaddingfordigit(format, len, c, str);
	else
	{
		if (format->minus == 1 && format->hash == 1 && (format->c == 'x' || format->c == 'X'))
			len += 2;
		if (format->minus == 1 && format->hash == 1 && (format->c == 'o' || format->c == 'O'))
			len += 1;
		amstr = ft_strnew(format->padsize - len);
		ft_memset(amstr, c, format->padsize - len);
	}
	if (format->minus == 1)
		tmp = ft_strjoin(*str, amstr);
	else
		tmp = ft_strjoin(amstr, *str);
	free(*str);
	*str = ft_strdup(tmp);
	free(amstr);
	free(tmp);
	return (*str);
}
