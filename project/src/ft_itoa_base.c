/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:24:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/13 13:15:32 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*createinfoupper(unsigned long long value, int base, int len, int isneg)
{
	char	*ret;
	char	*tab;

	tab = ft_strdup("0123456789ABCDEF");
	len = len + isneg;
	ret = (char*)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	if (isneg == 1)
		ret[0] = '-';
	while (value > 0)
	{
		ret[--len] = tab[value % base];
		value = value / base;
	}
	free(tab);
	return (ret);
}

char	*createinfolower(unsigned long long value, int base, int len, int isneg)
{
	char	*ret;
	char	*tab;

	tab = ft_strdup("0123456789abcdef");
	len = len + isneg;
	ret = (char*)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	if (isneg == 1)
		ret[0] = '-';
	while (value > 0)
	{
		ret[--len] = tab[value % base];
		value = value / base;
	}
	free(tab);
	return (ret);
}

char	*ft_itoa_base(long long value, int base, int cap)
{
	unsigned long long	i;
	int			len;
	int			isneg;
	char		*ret;

	isneg = 0;
	len = 1;
	if (value == 0)
	{
		ret = ft_strdup("0");
		return(ret);
	}
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
	{
		isneg = 1;
		value *= -1;
	}
	i = value;
	while (i /= base)
		len++;
	if (cap == 1)
	{
		ret = createinfoupper(value, base, len, isneg);
	}
	else
		ret = createinfolower(value, base, len, isneg);
	return (ret);
}
