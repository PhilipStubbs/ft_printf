/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:27:25 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/03 10:40:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *str, ...)
{
	t_printf	*node;
	va_list		args;
	int			error;

	error = 0;
	node = createstruc();
	va_start(args, str);
	node->size = ft_strlen(str);
	error = strprocessing(node, str, args);
	va_end(args);
	destroy(&node, error);
	return (node->size);
}