/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:09:06 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/04 14:09:11 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_returnzero(void)
{
	char	*p;

	p = (char*)ft_memalloc(2);
	if (!p)
		return (NULL);
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

char			*ft_uitoa(unsigned int n)
{
	char			*ret;
	int				len;
	unsigned int	tmp;

	if (n == 0)
		return (ft_returnzero());
	tmp = n;
	len = 1;
	while (tmp/=10)
		len++;
	if (!(ret = (char*)ft_memalloc(len + 1)))
		return (NULL);
	ret[len + 1] = '\0';
	while (n != 0)
	{
		ret[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (ret);
}