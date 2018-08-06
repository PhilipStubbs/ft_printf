/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:48:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/06 18:15:39 by pstubbs          ###   ########.fr       */
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
	if (format->padsize < len)
		return (*str);

	c = ' ';
	if (format->zeropad == 1)
		c = '0';
	if (format->spacpad == 1 && format->zeropad == 1)
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

int	findstring(t_printf *node, va_list args)
{
	char	*tmp;
	int		len;

	tmp = va_arg(args, char*);
	if (tmp == NULL)
		tmp = ft_strdup("(null)");
	len = ft_strlen(tmp);
	node->output = dynamicstring(&(node)->output, tmp);
	// free(tmp);
	return (len);
}

int	finddigit(t_printf *node, va_list args, t_format *format)
{
	int		tmp;
	int		len;
	char	*ret;

	tmp = va_arg(args, int);
	ret = ft_itoa(tmp);
	if (format->spacpad == 1 || format->zeropad == 1)
	{
		ret = createpadding(node, &ret, format);
	}
	// printf("here[%d]\n", f[2]);
	// if (f[3] != -1 || spacechecker(node->raw, f[2]))
	// 	ret = createpadding(node, &ret, f, node->raw[f[2]]);
	
	// if (node->raw[f[1]] == ' ')
	// {
	// 	retstr = ft_strjoin(" ", ret);
	// 	node->output = dynamicstring(&(node)->output, retstr);
	// 	free(retstr);
	// }
	// else
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	node->padding = -1;
	return (len);
}

int	findchar(t_printf *node, va_list args)
{
	char	tmp;

	tmp = va_arg(args, int);
	node->output = dynamicchar(&(node)->output, tmp);
	return (1);
}

int	findhex(t_printf *node, va_list args, char cap , t_format *format)
{
	int		tmp;
	char	*tmpstr;
	char	*tmpstr2;

	tmp = va_arg(args, int);
	if (cap == 'x')
		tmpstr = ft_itoa_base(tmp, 16, 0);
	else
		tmpstr = ft_itoa_base(tmp, 16, 1);
	if (format->hash == 1)
	{
		if (cap == 'X')
			tmpstr2 = ft_strjoin("0X", tmpstr);
		else
			tmpstr2 = ft_strjoin("0x", tmpstr);
		free(tmpstr);
		tmpstr = ft_strdup(tmpstr2);
		free(tmpstr2);
	}
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}

int	findoct(t_printf *node, va_list args, t_format *format)
{
	int		tmp;
	char	*tmpstr;
	char	*tmpstr2;

	tmp = va_arg(args, int);
	tmpstr = ft_itoa_base(tmp, 8, 0);
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

int	findpointer(t_printf *node, va_list args)
{
	unsigned long	tmp;
	char			*tmpstr;
	char			*ret;

	tmp = va_arg(args, unsigned long);
	tmpstr = ft_itoa_base(tmp, 16, 0);
	ret = ft_strjoin("0x", tmpstr);
	node->output = dynamicstring(&(node)->output, ret);
	tmp = ft_strlen(ret);
	free(tmpstr);
	free(ret);
	return (tmp);
}

int	findundigit(t_printf *node, va_list args)
{
	unsigned int	tmp;
	int				len;
	char			*ret;

	tmp = va_arg(args, unsigned int);
	ret = ft_uitoa(tmp);
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	return (len);
}
// 	if (chr <= 0x7F)
// 		chr_len = 1;
// 	else if (chr <= 0x7FF)
// 		chr_len = 2;
// 	else if (chr <= 0xFFFF)
// 		chr_len = 3;
// 	else if (chr <= 0x10FFFF)
// 		chr_len = 4;
// 	else
// 		chr_len = 0;