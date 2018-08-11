/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:27:25 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/11 12:47:23 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		customputchar(t_printf *node)
{
	int		i;
	// int		l;

	i = 0;
	while (node->output[i])
	{
		if (node->output[i] == '\\' && node->output[i + 1] == '0')
		{
			write(1, "\0", 1);
			i += 2;
		}
		else
		{
			ft_putchar(node->output[i]);
			i++;
		}
	}
}

int			ft_printf(char *str, ...)
{
	t_printf	*node;
	va_list		args;
	int			error;
	int			ret;

	error = 0;
	ret = 0;
	node = createstruc();
	node->raw = ft_strdup(str);
	va_start(args, str);
	node->size = ft_strlen(str);
	error = strprocessing(node, str, args);
	va_end(args);
	if (error == 0)
	{
		// printf("%s\n", node->output);
		// ft_putstr(node->output);
		customputchar(node);
		ret = ft_strlen(node->output);
	}
	ret -= node->lenmod;
	destroy(&node, error);
	return (ret);
}
