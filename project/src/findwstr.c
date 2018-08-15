/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findwstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:47:12 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 19:18:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		istherezero(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int		findwstr(t_printf *node, va_list args, t_format *format)
{
	int		i;
	int		len;
	char	*ret;
	char	*tmpstr;
	wchar_t	*tmp;

	i = 0;
	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, wchar_t *);
	if (tmp == NULL)
	{
		tmpstr = ft_strdup("(null)");
		node->output = dynamicstring(&node->output, tmpstr);
		free(tmpstr);
		return (6);
	}
	if (ft_strcmp((char*)tmp, "") == 0)
		return (0);
	tmpstr = wcharfinder(format, tmp[i]);

	if (tmp == 0)
	{
		free(tmpstr);
		tmpstr = ft_strdup("\\0");
		node->output = dynamicstring(&node->output, tmpstr);
		node->lenmod++;
		free(tmpstr);
		return (2);
	}
	len = 0;
	while (tmp[len])
		len++;
	ret = NULL;
	while (tmp[i] && i <= len && tmp != NULL)
	{
		free(tmpstr);
		tmpstr = wcharfinder(format ,tmp[i]);
		if (ret == NULL)
			ret = ft_strdup(tmpstr);
		else
			ret = dynamicstring(&ret, tmpstr);
		if (format->prec == 1 && format->wchar > format->precsize)
			break;
		i++;
	}
	if (format->prec == 1)
	{
		ret = precision(format, &ret);
	}
	if (istherezero(node->raw) == 0)
		format->prec = 0;
	if ((format->spacpad == 1 || format->zeropad == 1))
		ret = createpadding(&ret, format);
	len = ft_strlen(ret);
	node->output = dynamicstring(&node->output, ret);
	free(ret);
	free(tmpstr);
	return (len);
}