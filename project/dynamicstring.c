/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamicstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:52:29 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/03 09:52:37 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dynamicstring(char **ori, char *add)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strdup(*ori);
	free(*ori);
	ret = ft_strjoin(tmp, add);
	free(tmp);
	return (ret);
}
