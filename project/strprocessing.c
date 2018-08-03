/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:29:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/03 10:49:10 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flagchecker(t_printf *node, char *str,  va_list args, int i)
{
	if (str[i + 1] == '%')
	{
		dynamicstring(&(node)->output, "%");
		return (i + 2);
	}
	else if (str[i + 1] == 's')
	{
		i = findstring(node, args);
		return (i);
	}
	return (i);
}

int		strprocessing(t_printf *node, char *str, va_list args)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	node->output = (char*)ft_memalloc(sizeof(char) * node->size);
	while (str[i])
	{
		if (str[i] != '%')
			node->output[l] = str[i];
		if (str[i] == '%')
		{
			if ((l = flagchecker(node, str, args, i)) <= 0)
				return (1);
			i = movei(str, i);
		}
		else
		{
			l++;
			i++;
		}
	}
	return (0);
}
