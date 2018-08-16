/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflowfunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:08:49 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 09:09:44 by pstubbs          ###   ########.fr       */
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

int		wstrsize(wchar_t *tmp)
{
	int		len;

	len = 0;
	while (tmp[len])
		len++;
	return (len);
}
