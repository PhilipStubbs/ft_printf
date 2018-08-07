/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:31:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/07 13:33:18 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (format->zeropad == 1)
		c = '0';
	if (format->spacpad == 1 && format->zeropad == 1 && (format->c == 'd' || format->c == 'D' || format->c == 'i'))
	{
		tmp = ft_strdup(" ");
		amstr = ft_strnew(format->padsize - len - 1);
		ft_memset(amstr, c, format->padsize - len - 1);
		tmp = dynamicstring(&tmp ,amstr);
		free(amstr);
		amstr = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		amstr = ft_strnew(format->padsize - len);
		ft_memset(amstr, c, format->padsize - len);
	}
	tmp = ft_strjoin(amstr, *str);
	free(*str);
	*str = ft_strdup(tmp);
	free(amstr);
	free(tmp);
	return (*str);
}
