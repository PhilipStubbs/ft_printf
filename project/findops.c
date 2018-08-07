/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:48:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/07 13:33:10 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
