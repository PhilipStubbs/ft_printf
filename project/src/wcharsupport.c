/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcharsupport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:53:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/14 18:53:28 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wcharrip(wchar_t chr, char *ret ,int wchar_len)
{
	if (wchar_len <= 2)
	{
		ret[0] = (((chr & 0x07c0) >> 6) + 0xc0);
		ret[1] = (((chr & 0x003F)) + 0x80);
	}
	else if (wchar_len <= 3)
	{
		ret[0] = (((chr & 0xF000) >> 12) + 0xc0);
		ret[1] = (((chr & 0x0Fc0) >> 6) + 0xc0);
		ret[2] = (((chr & 0x003F)) + 0x80);
	}
	else if (wchar_len <= 4)
	{
		ret[0] = (((chr & 0x1c0000) >> 18) + 0xF0);
		ret[1] = (((chr & 0x03F000) >> 12) + 0x80);
		ret[2] = (((chr & 0x0Fc0) >> 6) + 0x80);
		ret[3] = ((chr & 0x003F) + 0x80);
	}
}

char	*wcharfinder(wchar_t chr)
{
	int		wchar_len;
	char	*ret;

	wchar_len = 0;
	ret = NULL;
	if (chr <= 0x7F)
		wchar_len = 1;
	else if (chr <= 0x7FF)
		wchar_len = 2;
	else if (chr <= 0xFFFF)
		wchar_len = 3;
	else if (chr <= 0x10FFFF)
		wchar_len = 4;
	if (wchar_len == 1)
	{
		ret = ft_strnew(wchar_len);
		ret[0] = (char)chr;
	}
	else
	{
		ret = ft_strnew(wchar_len);
		wcharrip(chr, ret, wchar_len);
	}
	return (ret);
}