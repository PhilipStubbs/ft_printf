/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:27:25 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/07 09:08:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_putstr(node->output);
		ret = ft_strlen(node->output);
	}
	destroy(&node, error);
	return (ret);
}
