/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:48:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/07 12:18:03 by pstubbs          ###   ########.fr       */
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

int		findstring(t_printf *node, va_list args, t_format *format)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	tmp = va_arg(args, char*);
	if (tmp == NULL)
		tmp2 = ft_strdup("(null)");
	else
		tmp2 = ft_strdup(tmp);
	if (format->zeropad == 1 || format->spacpad == 1)
		tmp2 = createpadding(node, &tmp2, format);
	len = ft_strlen(tmp2);
	node->output = dynamicstring(&(node)->output, tmp2);
	free(tmp2);
	return (len);
}

int		finddigit(t_printf *node, va_list args, t_format *format)
{
	int		tmp;
	int		len;
	char	*ret;

	tmp = va_arg(args, int);
	ret = ft_itoa(tmp);
	if (format->spacpad == 1 || format->zeropad == 1)
		ret = createpadding(node, &ret, format);
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	node->padding = -1;
	return (len);
}

int		findchar(t_printf *node, va_list args, t_format *format)
{
	char	tmp;
	char	*tmpstr;

	tmp = va_arg(args, int);
	tmpstr = ft_strnew(1);
	tmpstr[0] = tmp;
	if (format->spacpad == 1 || format->zeropad == 1)
		tmpstr = createpadding(node, &tmpstr, format);
	node->output = dynamicstring(&(node)->output, tmpstr);
	free(tmpstr);
	return (1);
}

char	*hexhash(char **tmpstr, char cap, t_format *format)
{
	char	*tmpstr2;
	char	*check;
	int		len;

	len = ft_strlen(*tmpstr);
	check = ft_strdup(*tmpstr);
	if (cap == 'X')
	{
		if (format->zeropad == 1 && check[0] == '0' && check[1] == '0')
		{
			tmpstr2 = ft_strdup(*tmpstr);
			tmpstr2[0] = '0';
			tmpstr2[1] = 'X';
		}
		else if (format->zeropad == 1 && check[0] == '0' && check[1] != '0')
		{
			check[0] = 'X';
			tmpstr2 = ft_strjoin("0", check);
		}
		else
			tmpstr2 = ft_strjoin("0X", *tmpstr);
	}
	else
	{
		if(format->zeropad == 1 && check[0] == '0' && check[1] == '0')
		{
			tmpstr2 = ft_strdup(*tmpstr);
			tmpstr2[0] = '0';
			tmpstr2[1] = 'x';
		}
		else if (format->zeropad == 1 && check[0] == '0' && check[1] != '0')
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
	if (format->hash == 1 && format->zeropad == 0 && format->spacpad == 1)
		tmpstr = hexhash(&tmpstr, cap, format);
	if ((format->spacpad == 1 || format->zeropad == 1))
		tmpstr = createpadding(node, &tmpstr, format);
	if (format->hash == 1 && format->zeropad == 1)
		tmpstr = hexhash(&tmpstr, cap, format);
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}

int		findoct(t_printf *node, va_list args, t_format *format)
{
	int		tmp;
	char	*tmpstr;
	char	*tmpstr2;

	tmp = va_arg(args, int);
	tmpstr = ft_itoa_base(tmp, 8, 0);
	if (format->spacpad == 1 || format->zeropad == 1)
		tmpstr = createpadding(node, &tmpstr, format);
	if (format->hash == 1)
	{
		tmpstr2 = ft_strjoin("0", tmpstr);
		free(tmpstr);
		tmpstr = ft_strdup(tmpstr2);
		free(tmpstr2);
	}
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}

int		findpointer(t_printf *node, va_list args, t_format *format)
{
	unsigned long	tmp;
	char			*tmpstr;
	char			*ret;

	tmp = va_arg(args, unsigned long);
	tmpstr = ft_itoa_base(tmp, 16, 0);
	ret = ft_strjoin("0x", tmpstr);
	if (format->spacpad == 1 || format->zeropad == 1)
		ret = createpadding(node, &ret, format);
	node->output = dynamicstring(&(node)->output, ret);
	tmp = ft_strlen(ret);
	free(tmpstr);
	free(ret);
	return (tmp);
}

int		findundigit(t_printf *node, va_list args, t_format *format)
{
	unsigned int	tmp;
	int				len;
	char			*ret;

	tmp = va_arg(args, unsigned int);
	ret = ft_uitoa(tmp);
	if (format->spacpad == 1 || format->zeropad == 1)
		ret = createpadding(node, &ret, format);
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	return (len);
}
