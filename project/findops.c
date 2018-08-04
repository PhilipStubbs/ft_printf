/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:48:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/04 16:54:23 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	findstring(t_printf *node, va_list args)
{
	char	*tmp;
	int		len;

	tmp = va_arg(args, char*);
	if (tmp == NULL)
		tmp = ft_strdup("(null)");
	len = ft_strlen(tmp);
	node->output = dynamicstring(&(node)->output, tmp);
	// free(tmp);
	return (len);
}

int	finddigit(t_printf *node, va_list args, int l)
{
	int		tmp;
	int		len;
	char	*ret;
	char	*retstr;

	tmp = va_arg(args, int);
	ret = ft_itoa(tmp);
	if (l > 1)
	{
		retstr = ft_strjoin(" ", ret);
		node->output = dynamicstring(&(node)->output, retstr);
		free(retstr);
	}
	else
		node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	return (len);
}

int	findchar(t_printf *node, va_list args)
{
	char	tmp;

	tmp = va_arg(args, int);
	node->output = dynamicchar(&(node)->output, tmp);
	return (1);
}

int	findhex(t_printf *node, va_list args, char cap)
{
	int		tmp;
	char	*tmpstr;

	tmp = va_arg(args, int);
	if (cap == 'x')
		tmpstr = ft_itoa_base(tmp, 16, 0);
	else
		tmpstr = ft_itoa_base(tmp, 16, 1);
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}

int	findoct(t_printf *node, va_list args)
{
	int		tmp;
	char	*tmpstr;

	tmp = va_arg(args, int);
	tmpstr = ft_itoa_base(tmp, 8, 0);
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}

int	findpointer(t_printf *node, va_list args)
{
	unsigned long	tmp;
	char			*tmpstr;
	char			*ret;

	tmp = va_arg(args, unsigned long);
	tmpstr = ft_itoa_base(tmp, 16, 0);
	ret = ft_strjoin("0x", tmpstr);
	node->output = dynamicstring(&(node)->output, ret);
	tmp = ft_strlen(ret);
	free(tmpstr);
	free(ret);
	return (tmp);
}

int	findundigit(t_printf *node, va_list args)
{
	unsigned int	tmp;
	int				len;
	unsigned int	test;
	char			*ret;

	tmp = va_arg(args, unsigned int);
	test = (unsigned int)tmp;
	
	ret = ft_uitoa(tmp);
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	return (len);
}
