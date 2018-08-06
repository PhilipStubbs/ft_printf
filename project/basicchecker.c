/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicchecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:28:14 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/06 12:28:36 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isnormalflag(char *str, int i)
{
	char	c;

	c = str[i];
	if (c == 's' || c == 'd' || c == 'S' || c == 'p' ||
	c == 'D' ||	c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
	c == 'x' ||	c == 'X' || c == 'c' || c == 'C')
	{
		return (1);
	}
	return (0);
}

int		spacechecker(char *str, int l)
{
	char	c;

	c = str[l - 1];
	if (str[l] == ' ' && c != 's' && c != 'd' && c != 'S' && c != 'p' &&
	c != 'D' &&	c != 'i' && c != 'o' && c != 'O' && c != 'u' && c != 'U' &&
	c != 'x' &&	c != 'X' && c != 'c' && c != 'C')
	{
		return (1);
	}
	return (0);
}
