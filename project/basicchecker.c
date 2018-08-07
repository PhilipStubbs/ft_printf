/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicchecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:28:14 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/07 18:11:35 by pstubbs          ###   ########.fr       */
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

	// 	if (!(c == 's' || c == 'd' || c == 'S' || c == 'p' || c == 'h' || c == 'l' ||
	// c == 'D' ||	c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
	// c == 'x' ||	c == 'X' || c == 'c' || c == 'C' || c == 'j' || c == 'e' ||
	// c == 't' || c == 'z' || c == '%' || c == '-' || ft_isdigit(c) == 1))
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
