/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findwchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:47:12 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/14 18:59:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		findwchar(t_printf *node, va_list args, t_format *format)
{
	int		len;
	char	*ret;
	char	*tmpstr;
	wchar_t	tmp;

	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, wchar_t );
	tmpstr = wcharfinder(tmp);
	if (tmpstr == NULL)
	{
		free(tmpstr);
		return (0);
	}
	free(tmpstr);

	ret = wcharfinder(tmp);
	if ((format->spacpad == 1 || format->zeropad == 1))
		tmpstr = createpadding(&tmpstr, format);
	len = ft_strlen(ret);
	node->output = dynamicstring(&node->output, ret);
	free(ret);
	return (len);
}