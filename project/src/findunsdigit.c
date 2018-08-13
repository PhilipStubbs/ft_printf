/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findunsdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:03:21 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/13 09:23:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*lengthmodunsigned(t_format *format, long long num)
{
	char	*ret;

	if (format->hh == 1)
		ret = ft_ulltoa((unsigned char)num);
	else if (format->h == 1)
		ret = ft_ulltoa((unsigned short int)num);
	else if (format->l == 1)
		ret = ft_ulltoa((unsigned long int)num);
	else if (format->ll == 1)
		ret = ft_ulltoa((unsigned long long int)num);
	else if (format->j == 1)
		ret = ft_ulltoa((uintmax_t)num);
	else if (format->z == 1)
		ret = ft_ulltoa((size_t)num);
	else
		ret = ft_ulltoa(num);
	return (ret);
}

int		findundigit(t_printf *node, va_list args, t_format *format)
{
	unsigned long long 	tmp;
	int				len;
	char			*ret;

	tmp = va_arg(args, unsigned long long);

	if (format->lenmod == 1)
		ret = lengthmodunsigned(format, (unsigned long long)tmp);
	else
	{
		if (format->c == 'U')
			ret = ft_ulltoa((unsigned long int)tmp);
		else
			ret = ft_ulltoa((unsigned int)tmp);
	}
	if (format->prec == 1)
		ret = precision(format, &ret);
	if (format->spacpad == 1 || format->zeropad == 1)
		ret = createpadding(&ret, format);
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	return (len);
}
