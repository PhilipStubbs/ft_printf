/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:59:51 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/08 17:55:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specialprecision(t_format *format, char **str)
{
	char	*tmp;
	char	*bigprec;
	int		len;
	int		isneg;

	len = ft_strlen(*str);
	isneg = 0;
	if (len < format->precsize)
	{
		if (*str[0] == '-')
		{
			isneg = 1;
			*str[0] = '0';
		}
		len = format->precsize - len;
		bigprec = (char*)ft_memalloc(sizeof(char) * (len + isneg) + 1);
		ft_memset(bigprec, '0', (len + isneg));
		tmp = ft_strjoin(bigprec, *str);
	}
	else
		tmp = ft_strdup(*str);
	free(bigprec);
	// free(*str);
	if (isneg == 1)
		tmp[0] = '-';
	return(tmp);
}

char	*precision(t_format *format, char **str)
{
	char	*tmp;

	if (format->c == 'd' || format->c == 'D' || format->c == 'i')
		tmp = specialprecision(format, str);
	else
		tmp = ft_strsub(*str, 0, format->precsize);
	free(*str);
	return(tmp);
}
