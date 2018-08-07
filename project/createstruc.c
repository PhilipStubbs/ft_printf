/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstruc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:53:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/07 10:27:01 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*createstruc(void)
{
	t_printf	*ret;

	ret = (t_printf*)ft_memalloc(sizeof(t_printf));
	ret->output = NULL;
	ret->size = 0;
	ret->padding = 0;
	ret->l = 0;
	ret->s = 0;
	ret->S = 0;
	ret->p = 0;
	ret->d = 0;
	ret->i = 0;
	ret->o = 0;
	ret->u = 0;
	ret->c = 0;
	return (ret);
}

t_format	*cleanformat(void)
{
	t_format	*ret;

	ret = (t_format*)ft_memalloc(sizeof(t_format));
	ret->c = 0;
	ret->start = 0;
	ret->end = 0;
	ret->spacpad = 0;
	ret->zeropad = 0;
	ret->padsize = 0;
	ret->hash = 0;
	ret->minus = 0;
	ret->plus= 0;
	ret->prec = 0;
	return (ret);
}
