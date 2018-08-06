/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstruc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:53:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/06 10:23:51 by pstubbs          ###   ########.fr       */
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
