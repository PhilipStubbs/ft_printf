/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findwstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:47:12 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 08:03:57 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	tmpstr = wcharfinder(tmp[i]);
	if (tmpstr == NULL || tmp == 0)
	{
		free(tmpstr);
		tmpstr = ft_strdup("\\0");
		node->output = dynamicstring(&node->output, tmpstr);
		node->lenmod++;
		free(tmpstr);
		return (2);
	}
	else
		len = ft_strlen((char*)tmp);
	ret = NULL;
	while (i <= len && tmp != NULL)
	{
		free(tmpstr);
		tmpstr = wcharfinder(tmp[i]);
		if (ret == NULL)
			ret = ft_strdup(tmpstr);
		else
			ret = dynamicstring(&ret, tmpstr);
		i++;
	}
	if (format->prec == 1)
		tmpstr = precision(format, &tmpstr);
	if ((format->spacpad == 1 || format->zeropad == 1))
		tmpstr = createpadding(&tmpstr, format);
	len = ft_strlen(ret);
	node->output = dynamicstring(&node->output, ret);
	free(ret);
	free(tmpstr);
	return (len);
}