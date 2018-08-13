/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 08:39:33 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/13 08:56:49 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_lltoa(long long n)
{
	char	*ret;
	int		len;
	int		isneg;
	long long tmp;

	if (n == 0)
		return ((ret = ft_strdup("0")));
	len = 1;
	isneg = 0;
	if (n < 0)
	{
		isneg = 1;
		n = n * -1;
	}
	tmp = n;
	while (tmp /= 10)
		len++;
	len += isneg;
	if (!(ret = (char*)ft_memalloc(len + 1)))
		return (NULL);
	ret[len + 1] = '\0';
	while (n != 0)
	{
		ret[--len] = n % 10 + 48;
		n = n / 10;
	}
	if (isneg)
		ret[0] = '-';
	return (ret);
}
