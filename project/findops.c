/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:48:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/03 17:22:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	findstring(t_printf *node, va_list args)
{
	char	*tmp;
	int		len;

	tmp = va_arg(args, char*);
	len = ft_strlen(tmp);
	node->output = dynamicstring(&(node)->output, tmp);
	// free(tmp);
	return (len);
}

int	finddigit(t_printf *node, va_list args)
{
	int		tmp;
	int		len;
	char	*ret;

	tmp = va_arg(args, int);
	ret = ft_itoa(tmp);
	
	node->output = dynamicstring(&(node)->output, ret);


	len = ft_strlen(ret);

	free(ret);
	return (len);
}