/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findoct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:51:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 11:15:05 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*lengthmodoct(t_format *format, long long num, int cap)
{
	char	*ret;

	if (format->l == 1 || format->c == 'O')
		ret = ft_itoa_base((unsigned long int)num, 8, cap);
	else if (format->hh == 1)
		ret = ft_itoa_base((unsigned char)num, 8, cap);
	else if (format->h == 1)
		ret = ft_itoa_base((unsigned short int)num, 8, cap);
	else if (format->ll == 1)
		ret = ft_itoa_base((unsigned long long int)num, 8, cap);
	else if (format->j == 1)
		ret = ft_itoa_base((uintmax_t)num, 8, cap);
	else if (format->z == 1)
		ret = ft_itoa_base((size_t)num, 8, cap);
	else
		ret = ft_itoa_base(num, 8, cap);
	return (ret);
}

void	hashflagoct(char **tmpstr)
{
	char	*tmpstr2;

	tmpstr2 = ft_strjoin("0", *tmpstr);
	free(*tmpstr);
	*tmpstr = ft_strdup(tmpstr2);
	free(tmpstr2);
}

int		findoct(t_printf *node, va_list args, t_format *format)
{
	long long	tmp;
	char	*tmpstr;
	// char	*tmpstr2;

	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, long long);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 && format->padsize == 0 && format->hash == 0)
		return (0);
	else if (tmp == 0 && format->prec == 1 && format->precsize == 0 && format->padsize != 0)
		tmpstr = ft_strdup(" ");
	else
	{
		if (format->lenmod == 1 || format->c == 'O')
			tmpstr = lengthmodoct(format, tmp, 0);
		else
			tmpstr = ft_itoa_base((unsigned int)tmp, 8, 0);
		if ( (tmp > 0 && format->hash == 1) && ((format->spacpad == 0 && format->zeropad == 0) || (tmp > format->precsize)))
			hashflagoct(&tmpstr);
		if (format->prec == 1)
			tmpstr = precision(format, &tmpstr);
		
	}
	// if ( (tmp > 0 && format->hash == 1) && ((format->spacpad == 0 && format->zeropad == 0) || (tmp > format->precsize)))
	// if ( (tmp > 0 && format->hash == 1) && ((format->spacpad == 0 && format->zeropad == 0) && format->prec == 0))
	// {
	// 	hashflagoct(&tmpstr);
		// tmpstr2 = ft_strjoin("0", tmpstr);
		// free(tmpstr);
		// tmpstr = ft_strdup(tmpstr2);
		// free(tmpstr2);
	// }
	
	if (format->spacpad == 1 || format->zeropad == 1)
		tmpstr = createpadding(&tmpstr, format);
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}
