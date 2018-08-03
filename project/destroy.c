/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:18:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/03 10:32:20 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	destroy(t_printf **node, int error)
{
	free((*node)->output);
	free(*node);
	if (error == 1)
		ERROR;
	exit(1);
}