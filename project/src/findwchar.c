/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findwchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:47:12 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/14 18:11:43 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*wcharrip(wchar_t chr)
{
	int	wchar_len;
	char	*ret;

	wchar_len = 0;
	if (chr <= 0x7F)
	{
		wchar_len = 1;
		ret = ft_strnew(wchar_len);
		ret[0] = (char)chr;
		return (ret);
	}
	else if (chr <= 0x7FF)
	{
		wchar_len = 2;
		ret = ft_strnew(wchar_len);
		ret[0] = (((chr & 0x07c0) >> 6) + 0xc0);
		ret[1] = (((chr & 0x003F)) + 0x80);
		return (ret);
	}
	else if (chr <= 0xFFFF)
	{
		wchar_len = 3;
		ret = ft_strnew(wchar_len);
		ret[0] = (((chr & 0xF000) >> 12) + 0xc0);
		ret[1] = (((chr & 0x0Fc0) >> 6) + 0xc0);
		ret[2] = (((chr & 0x003F)) + 0x80);
		return (ret);
	}
	else if (chr <= 0x10FFFF)
	{
		wchar_len = 4;
		ret = ft_strnew(wchar_len);
		ret[0] = (((chr & 0x1c0000) >> 18) + 0xF0);
		ret[1] = (((chr & 0x03F000) >> 12) + 0x80);
		ret[2] = (((chr & 0x0Fc0) >> 6) + 0x80);
		ret[3] = ((chr & 0x003F) + 0x80);
		return (ret);
	}
	return (NULL);
}

int		wcharsize(wchar_t chr)
{
	int	wchar_len;

	wchar_len = 0;
	if (chr <= 0x7F)
		wchar_len = 1;
	else if (chr <= 0x7FF)
		wchar_len = 2;
	else if (chr <= 0xFFFF)
		wchar_len = 3;
	else if (chr <= 0x10FFFF)
		wchar_len = 4;
	
	return (wchar_len);
}

int		findwchar(t_printf *node, va_list args, t_format *format)
{
	int		i;
	int		len;
	char	*ret;
	char	*tmpstr;
	wchar_t	*tmp;

	i = 0;
	tmp = va_arg(args, wchar_t *);
	len = ft_strlen((char*)tmp);
	ret = NULL;
	(void)format;
	while (tmp[i] && i <= len)
	{
		tmpstr = wcharrip(tmp[i]);
		if (ret == NULL)
			ret = ft_strdup(tmpstr);
		else
			ret = dynamicstring(&ret, tmpstr);
		free(tmpstr);
		i++;
	}
	len = ft_strlen(ret);
	node->output = dynamicstring(&node->output, ret);
	free(ret);
	return (len);
}