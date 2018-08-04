/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:29:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/04 12:48:42 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flagchecker(t_printf *node, char *str,  va_list args, int i)
{
	if (str[i + 1] == '%')
	{
		dynamicstring(&(node)->output, "%");
		return (1);
	}
	else if (str[i + 1] == 's')
	{
		i = findstring(node, args);
		return (i);
	}
	else if (str[i + 1] == 'd' || str[i + 1] == 'D' || str[i + 1] == 'i')
	{
		i = finddigit(node, args);
		return (i);
	}
	else if (str[i + 1] == 'c' || str[i + 1] == 'C')
	{
		findchar(node, args);
		return (1);
	}
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
	{
		i = findhex(node, args, str[i + 1]);
		return (i);
	}
	else if (str[i + 1] == 'o' || str[i + 1] == 'O')
	{
		i = findoct(node, args);
		return (i);
	}
	else if (str[i + 1] == 'p')
	{
		i = findpointer(node, args);
		return (i);
	}
	return (-1);
}

int		movei(char *str, int i)
{
	if (str[i + 1] == '%')
		return (i + 2);
	else if (str[i + 1] == 's')
		return (i + 2);
	else if (str[i + 1] == 'd' || str[i + 1] == 'D' || str[i + 1] == 'i')
		return (i + 2);
	else if (str[i + 1] == 'c' || str[i + 1] == 'C')
		return (i + 2);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		return (i + 2);
	else if (str[i + 1] == 'o' || str[i + 1] == 'O')
		return (i + 2);
	else if (str[i + 1] == 'p')
		return (i + 2);
	return (i);
}

int		strprocessing(t_printf *node, char *str, va_list args)
{
	int		i;

	i = 0;
	node->output = (char*)ft_memalloc(sizeof(char) * node->size + 1);
	while (str[i])
	{
		if (str[i] != '%')
		{
			// node->output[node->l] = str[i];
			node->output = dynamicchar(&(node)->output, str[i]);
		}
		if (str[i] == '%')
		{
			if ((node->l += flagchecker(node, str, args, i)) <= 0)
				return (1);
			i = movei(str, i);
		}
		else
		{
			node->l++;
			i++;
		}
		// printf("i:%d%c | l:%d%c insied[%s]\n",i,str[i], node->l,node->output[node->l] ,node->output );
	}
	return (0);
}
