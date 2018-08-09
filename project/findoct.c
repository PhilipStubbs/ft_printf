/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findoct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:51:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/09 10:57:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		findoct(t_printf *node, va_list args, t_format *format)
{
	int		tmp;
	char	*tmpstr;
	char	*tmpstr2;

	tmp = va_arg(args, int);
	tmpstr = ft_itoa_base(tmp, 8, 0);
	if (format->prec == 1)
		tmpstr = precision(format, &tmpstr);
	tmp = ft_strlen(tmpstr);
	if (format->hash == 1 && ((format->spacpad == 0 && format->zeropad == 0) || tmp > format->precsize ))
	{
		tmpstr2 = ft_strjoin("0", tmpstr);
		free(tmpstr);
		tmpstr = ft_strdup(tmpstr2);
		free(tmpstr2);
	}
	if (format->spacpad == 1 || format->zeropad == 1)
		tmpstr = createpadding(node, &tmpstr, format);
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}
