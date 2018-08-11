/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:48:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/11 18:00:14 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		justpercent(t_printf *node, t_format *format)
{
	char	*tmp;
	int		len;

	tmp = ft_strdup("%");
	if (format->zeropad == 1 || format->spacpad == 1)
	{
		tmp = createpadding(&tmp, format);
	}
	node->output = dynamicstring(&(node)->output, tmp);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
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
	if (format->prec == 1)
		tmp2 = precision(format, &tmp2);
	if (format->zeropad == 1 || format->spacpad == 1)
		tmp2 = createpadding(&tmp2, format);
	len = ft_strlen(tmp2);
	node->output = dynamicstring(&(node)->output, tmp2);
	free(tmp2);
	return (len);
}

char	*addplus(char **str)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strdup("+");
	tmp2 = ft_strdup(*str);
	free(*str);
	tmp3 = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (tmp3);
}

int		finddigit(t_printf *node, va_list args, t_format *format)
{
	long long 	tmp;
	int		len;
	char	*ret;

	tmp = va_arg(args, long long );
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 && format->padsize == 0)
		return (0);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 && format->padsize != 0)
		ret = ft_strdup(" ");
	else
	{
		if (format->lenmod == 1)
			ret = lengthmoddig(format, tmp);
		else
			ret = ft_itoa(tmp);
		if (format->plus == 1 && format->prec == 0 && ret[0] != '-')
			ret = addplus(&ret);
		if (format->prec == 1)
			ret = precision(format, &ret);
		if (format->plus == 1 && format->prec == 1 && ret[0] != '-')
			ret = addplus(&ret);
		if (format->spacpad == 1 && format->zeropad == 0 && format->padsize == 0 && tmp > 0 && format->plus == 0 && format->prec == 0)
			format->padsize = ft_strlen(ret) + 1;
	}
	if (format->spacpad == 1 || format->zeropad == 1)
		ret = createpadding(&ret, format);
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
	int		i;

	i = 0;
	tmp = va_arg(args, int);
	if (tmp == 0 )
	{
		tmpstr = ft_strdup("\\0");
		node->lenmod++;
		if (format->padsize > 0)
			format->padsize++;
	}
	else
	{
		tmpstr = ft_strnew(1);
		tmpstr[0] = tmp;
	}
	if (format->spacpad == 1 || format->zeropad == 1)
		tmpstr = createpadding(&tmpstr, format);
	node->output = dynamicstring(&(node)->output, tmpstr);
	i = ft_strlen(tmpstr);
	free(tmpstr);
	return (i);
}

int		findpointer(t_printf *node, va_list args, t_format *format)
{
	unsigned long long	tmp;
	char			*tmpstr;
	char			*ret;

	tmp = va_arg(args, unsigned long long);
	tmpstr = ft_itoa_base(tmp, 16, 0);
	if (format->prec == 1)
		tmpstr = precision(format, &tmpstr);
	ret = ft_strjoin("0x", tmpstr);
	if (format->spacpad == 1 || format->zeropad == 1)
		ret = createpadding(&ret, format);
	node->output = dynamicstring(&(node)->output, ret);
	tmp = ft_strlen(ret);
	free(tmpstr);
	free(ret);
	return (tmp);
}
