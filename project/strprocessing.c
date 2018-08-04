/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:29:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/04 16:56:13 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		findoperator(char *str, int i)
{
	int	count;

	count = 1;
	i++;
	while (str[i] == ' ')
	{
		i++;
		count++;
	}
	return (count);
}

int		flagchecker(t_printf *node, char *str,  va_list args, int i)
{
	int l;

	l = findoperator(str, i);
	if (str[i + l] == '%')
	{
		dynamicstring(&(node)->output, "%");
		return (1);
	}
	else if (str[i + l] == 's')
	{
		i = findstring(node, args);
		return (i);
	}
	else if (str[i + l] == 'd' || str[i + l] == 'D' || str[i + l] == 'i')
	{
		i = finddigit(node, args, l);
		return (i);
	}
	else if (str[i + l] == 'c' || str[i + l] == 'C')
	{
		findchar(node, args);
		return (1);
	}
	else if (str[i + l] == 'x' || str[i + l] == 'X')
	{
		i = findhex(node, args, str[i + l]);
		return (i);
	}
	else if (str[i + l] == 'o' || str[i + l] == 'O')
	{
		i = findoct(node, args);
		return (i);
	}
	else if (str[i + l] == 'p')
	{
		i = findpointer(node, args);
		return (i);
	}
	else if (str[i + l] == 'U' || str[i + l] == 'u')
	{
		i = findundigit(node, args);
		return (i);
	}
	return (-1);
}

int		movei(char *str, int i)
{
	int l;

	l = findoperator(str, i);
	if (str[i + l] == '%')
		return (i + l + 1);
	else if (str[i + l] == 's')
		return (i + l + 1);
	else if (str[i + l] == 'd' || str[i + l] == 'D' || str[i + l] == 'i')
		return (i + l + 1);
	else if (str[i + l] == 'c' || str[i + l] == 'C')
		return (i + l + 1);
	else if (str[i + l] == 'x' || str[i + l] == 'X')
		return (i + l + 1);
	else if (str[i + l] == 'o' || str[i + l] == 'O')
		return (i + l + 1);
	else if (str[i + l] == 'p')
		return (i + l + 1);
	else if (str[i + l] == 'u' || str[i + l] == 'U')
		return (i + l + 1);
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
